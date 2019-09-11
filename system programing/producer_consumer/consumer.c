#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include "queue.h"
#include "consumer.h"

struct consumers{
   Queue** queues;
   pthread_t** consumer_t;
   int size;
   sem_t sem_c;
};


consumers* createConsumers(Queue* QPC, Queue* QCP,int size){
   int i;
   consumers* mycons= malloc(sizeof(consumers));
   mycons->size = size;
   mycons->queues= malloc((sizeof(Queue*))*2);
   mycons->queues[0]= QPC;
   mycons->queues[1]= QCP;
   mycons->consumer_t=malloc((sizeof(pthread_t))*size);
   sem_init(&(mycons->sem_c), 0, size);

   for (i= 0; i < size; i++){
     /* sem_wait(&sem_c);*/
      pthread_create((mycons->consumer_t[i]), NULL, consumer,(void**)(mycons->queues));
   }

}

void joinConsumers(consumers* mycons){
   int i;
   for (i = 0; i < mycons->size; i++){
      pthread_join(*(mycons->consumer_t[i]), NULL);
   }
} 



void *consumer(void* args)
{
   int x;
   char** st = malloc(sizeof(char*)); 
   /*sem_post(&sem_c);*/
   while(1){
   	  x= (int)syscall(__NR_gettid);
      dequeue((Queue*)((void**)args)[0] , st);
      if(!strcmp(*st,"stop")){
         enqueue((Queue*)((void**)args)[0],*st);
      	enqueue((Queue*)((void**)args)[1],*st);
         break;
      }
      printf("my consumer index:%d\n",x);
      printf("my message:%s\n",*st);
    }
   
}