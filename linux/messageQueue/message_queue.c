#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/stat.h> /* for permission bits on module_param */
#include <linux/fs.h> /* for fops */
#include <linux/device.h> /* for device_create */
#include <linux/moduleparam.h> /* for module_param, MODULE_PARM_DESC... */
#include <linux/init.h> /* for __init, __exit */
#include <linux/cdev.h> /* for cdev_* */
#include <linux/list.h>
#include <linux/slab.h> /* for kmalloc, kfree */
#include "mq.h"
#include <linux/uaccess.h> /*for copy to user*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ori Yaish");
MODULE_DESCRIPTION("A simple implementation for something like /dev/null");

static int auto_register = 8;
static int message_queue_count = 8;
const size_t MESSAGE_SIZE = 4096;
/*static int message_queue_size = PAGE_SIZE; */
module_param(auto_register, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(auto_register, "Do you want me to auto register the file in /dev ?");


struct mystruct{
	char* buf;
	int size;
	struct list_head node;
};

struct my_message_queue_t {
	struct list_head q_messages;
	int size; /* number of messages in queue */
	size_t max_mes;
	struct device *message_queue_device;
	/*struct mutex *mutex;*/
};

static struct my_message_queue_t *queues;

static dev_t first_dev;

/* this variable will store the class */
static struct class *my_class;
/* this variable will hold our cdev struct */
static struct cdev cdev;
/* this is our first minor (0 by default)*/
static int first_minor;


static inline void message_queue_ctor(struct my_message_queue_t *msq)
{
	INIT_LIST_HEAD(&msq->q_messages);
	/* Mmutex_init(msq->mutex); */
	msq->size = 0;
	msq->max_mes = 100;
	msq->message_queue_device = NULL;
}

static inline void message_queue_dtor(struct my_message_queue_t *queue)
{   
	while(!list_empty(&queue->q_messages)){
		list_del((&queue->q_messages)->prev);
	}
}

static long mq_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
		struct my_message_queue_t *queue = file->private_data;
		struct mystruct *ms_b;
		/*struct list_head *p;*/
		struct mystruct *new_ms;
		struct ms_buff my_buff;
		char* new_buff;
		int ret;
         switch(cmd) {
                case WR_VALUE:
                		if((queue->size) ==100){
                			pr_info(KBUILD_MODNAME " overFlow\n");
                			break;
                		}
                		/*mutex_lock(queue->mutex);*/
                		
                        ret=copy_from_user(&my_buff ,(struct ms_buff*)arg, sizeof(struct ms_buff));
                        pr_info(KBUILD_MODNAME "a\n");
                        if(ret) {
                        	pr_err("%s: cannot copy from user\n", THIS_MODULE->name);
                        	/*mutex_unlock(queue->mutex);*/
                        	return ret;
                        }
                        ms_b=(struct mystruct*)kmalloc(sizeof(struct mystruct), GFP_KERNEL);
                        if(IS_ERR(ms_b)) {
                        	pr_err("%s: cannot allocate memoryh\n", THIS_MODULE->name);
                        	/*mutex_unlock(queue->mutex);*/
                        	return PTR_ERR(ms_b);
                        }
                        pr_info(KBUILD_MODNAME "b\n");
                        ms_b->size=my_buff.size;
                        new_buff=(char*)kmalloc(ms_b->size, GFP_KERNEL);
                        pr_info(KBUILD_MODNAME "c\n");
                        if(IS_ERR(new_buff)) {
                        	pr_err("%s: cannot allocate memory 2\n", THIS_MODULE->name);
                        	/*mutex_unlock(queue->mutex);*/
                        	return PTR_ERR(new_buff);
                        }
                        ret=copy_from_user(new_buff, my_buff.mes, ms_b->size);
                        if(ret) {
                        	pr_err("%s: cannot copy buffer from user space\n", THIS_MODULE->name);
                        	/*mutex_unlock(queue->mutex);*/
                        	return ret;
                        }
                        pr_info(KBUILD_MODNAME "d\n");
                        ms_b->buf=new_buff;
                        pr_info("%s: size is %u", THIS_MODULE->name, ms_b->size);
                		pr_info("%s: size is %p", THIS_MODULE->name, ms_b->buf);
                        list_add(&ms_b->node, &queue->q_messages);
                        pr_info(KBUILD_MODNAME "e\n");
                        queue->size= queue->size + 1;
                        pr_info(KBUILD_MODNAME "%d\n",queue->size);
                        
                        
                        /*list_for_each(p, &queue->q_messages) 
				        {
				                new_ms = list_entry(p, struct mystruct, mylist);
				                printk(KERN_INFO"%d\n", new_ms->msg.size);
				                printk(KERN_INFO"%s\n", new_ms->msg->mes);

				        }*/
                        /*mutex_unlock(queue->mutex);*/
                        break;
                case RD_VALUE:
                		if(queue->size == 0){
                			pr_info("%s: empty queue\n", THIS_MODULE->name);
                			return -ENOTTY;
                		}
                		pr_info(KBUILD_MODNAME "begin reading\n");
                	
                		/*mutex_lock(&queue->mutex);*/
                		new_ms = list_entry((&queue->q_messages)->prev, struct mystruct, node);
                		pr_info(KBUILD_MODNAME "list_entry\n");
                		
                		pr_info("%s: size is %u", THIS_MODULE->name, new_ms->size);
                		pr_info("%s: size is %p", THIS_MODULE->name, new_ms->buf);
                		list_del((&queue->q_messages)->prev);
                		pr_info(KBUILD_MODNAME "after delete\n");
                		ret=copy_to_user((char*)arg,new_ms->buf, new_ms->size);
                        if(ret) {
                        	pr_err("%s: cannot copy buffer from user space\n", THIS_MODULE->name);
                        	//mutex_unlock(queue->mutex);
                        	return ret;
                        }
                        pr_info(KBUILD_MODNAME "after copy\n");
                        /*mutex_unlock(&queue->mutex);*/
                        return new_ms->size;
                        break;
        }
        return 0;
}



static ssize_t write_oriNull(struct file *file, const char __user *buf,
		size_t count, loff_t *ppos)
{
	/* remmember to increment the position to let the user think that
	he is actually writing something...
	*/
	pr_info("count is %zd\n", count);
	*ppos += count;
	return count;
}

static int message_queue_open(struct inode *inode, struct file *filp)
{
	/* hide the pipe in the private_data of the struct file... */
	int the_queue_number = iminor(inode)-MINOR(first_dev);
	struct my_message_queue_t *queue = queues+the_queue_number;
	filp->private_data = queue;
	return 0;
}


static const struct file_operations message_queue_fops = {
	.owner = THIS_MODULE,
	.open = message_queue_open,
	.write = write_oriNull,
	.unlocked_ioctl = mq_ioctl,
};




static int __init message_queue_init(void){
	int i;
	int ret;
	queues = kmalloc(sizeof(struct my_message_queue_t)*message_queue_count, GFP_KERNEL);

	if (IS_ERR(queues)) {
		pr_err("kmalloc\n");
		ret = PTR_ERR(queues);
		goto err_return;
	}
	/* initialize all pipes */
	for (i = 0; i < message_queue_count; i++){
		message_queue_ctor(queues+i);
	}

	ret = alloc_chrdev_region(&first_dev, first_minor, auto_register,
			THIS_MODULE->name);
	if (ret) {
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
	pr_debug("allocated the region\n");

	/* add the cdev structure */
	cdev_init(&cdev, &message_queue_fops);

	ret = cdev_add(&cdev, first_dev, auto_register);
	if (ret) {
		pr_err("cannot cdev_add\n");
		goto err_dealloc;
	}
	pr_debug("added the cdev\n");

	/* this is creating a new class (/proc/devices) */
	my_class = class_create(THIS_MODULE, THIS_MODULE->name);
	if (IS_ERR(my_class)) {
		pr_err("class_create\n");
		ret = PTR_ERR(my_class);
		goto err_cdev_del;
	}

	pr_debug("created the class\n");
	for (i = 0; i < message_queue_count; i++) {
		queues[i].message_queue_device = device_create(my_class, NULL,
				MKDEV(MAJOR(first_dev), MINOR(first_dev)+i),
				NULL, "%s%d", THIS_MODULE->name, i);

		if (IS_ERR(queues[i].message_queue_device)) {
				pr_err("device_create\n");
				ret = PTR_ERR(queues[i].message_queue_device);
				goto err_class;
		}
	}

	pr_info(KBUILD_MODNAME " loaded successfully\n");
	return 0;

	err_class:
		class_destroy(my_class);
	err_cdev_del:
		cdev_del(&cdev);
	err_dealloc:
		unregister_chrdev_region(first_dev, auto_register);
	err_final:
		for (i = 0; i < message_queue_count; i++){
			message_queue_dtor(queues+i);
		}
		kfree(queues);
	err_return:
		return ret;



} 

static void __exit message_queue_exit(void)
{
	int i;
	pr_info("%s: started exit\n", THIS_MODULE->name);
	for (i = 0; i < message_queue_count; i++){
		device_destroy(my_class, MKDEV(MAJOR(first_dev),
			MINOR(first_dev)+i));
	}
	pr_info("%s: done device_destroy\n", THIS_MODULE->name);
	class_destroy(my_class);
	pr_info("%s: done class_destroy\n", THIS_MODULE->name);
	cdev_del(&cdev);
	pr_info("%s: done cdev_del\n", THIS_MODULE->name);
	unregister_chrdev_region(first_dev, auto_register);
	pr_info("%s: done unregister_chrdev_region\n", THIS_MODULE->name);
	for (i = 0; i < message_queue_count; i++){
		message_queue_dtor(queues+i);
	}
	pr_info("%s: message_queue_dtor\n", THIS_MODULE->name);
	kfree(queues);
	pr_info("%s: free queues\n", THIS_MODULE->name);
	
	pr_info("%s: unloaded successfully\n", THIS_MODULE->name);
}

module_init(message_queue_init);
module_exit(message_queue_exit);