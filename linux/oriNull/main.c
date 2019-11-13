#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/stat.h> /* for permission bits on module_param */
#include <linux/fs.h> /* for fops */
#include <linux/device.h> /* for device_create */
#include <linux/moduleparam.h> /* for module_param, MODULE_PARM_DESC... */
#include <linux/init.h> /* for __init, __exit */
#include <linux/cdev.h> /* for cdev_* */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ori Yaish");
MODULE_DESCRIPTION("A simple implementation for something like /dev/null");

static int auto_register = 1;
module_param(auto_register, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(auto_register, "Do you want me to auto register the file in /dev ?");

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

static const struct file_operations oriNull_fops = {
	.owner = THIS_MODULE,
	.write = write_oriNull,
};

static dev_t first_dev;

/* this variable will store the class */
static struct class *my_class;
/* this variable will hold our cdev struct */
static struct cdev cdev;
/* this is our first minor (0 by default)*/
static int first_minor;

struct device *oriNull_device;

static int __init oriNull_init(void){

	int ret;
	ret = alloc_chrdev_region(&first_dev, first_minor, auto_register,
			THIS_MODULE->name);
	if (ret) {
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
	pr_debug("allocated the region\n");

	/* add the cdev structure */
	cdev_init(&cdev, &oriNull_fops);

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

	oriNull_device = device_create(my_class, NULL,
			MKDEV(MAJOR(first_dev), MINOR(first_dev)),
			NULL, "%s", THIS_MODULE->name);

	if (IS_ERR(oriNull_device)) {
			pr_err("device_create\n");
			ret = PTR_ERR(oriNull_device);
			goto err_class;
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
		return ret;



} 

static void __exit oriNull_exit(void)
{
	device_destroy(my_class, MKDEV(MAJOR(first_dev),
					MINOR(first_dev)));
	class_destroy(my_class);
	cdev_del(&cdev);
	unregister_chrdev_region(first_dev, auto_register);
	pr_info(KBUILD_MODNAME " unloaded successfully\n");
}

module_init(oriNull_init);
module_exit(oriNull_exit);