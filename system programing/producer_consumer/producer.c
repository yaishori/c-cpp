#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h>
#include <pthread.h> 
#include "queue.h"
#include "producer.h"
#include "consumer.h"


struct producers{
   Queue** queues;
   pthread_t** producer_t;
   int size;
   sem_t sem_p;
};


producers* createProducers(Queue* QPC, Queue* QCP,int size){
   int i;
   producers* myprods= malloc(sizeof(producers));
   myprods->size = size;
   myprods->queues= malloc((sizeof(Queue*))*2);
   myprods->queues[0]= QPC;
   myprods->queues[1]= QCP;
   myprods->producer_t = malloc((sizeof(pthread_t*))*size);
   sem_init(&(myprods->sem_p), 0, size);

   for (i= 0; i < size; i++){
      myprods->producer_t[i]=malloc(sizeof(pthread_t));
      pthread_create((myprods->producer_t[i]), NULL, producer,(void**)(myprods->queues));
   }
   return myprods;
}

void joinProducers(producers* myprods){
   int i;
   for (i = 0; i < myprods->size; i++){
      pthread_join(*(myprods->producer_t[i]), NULL);
   }
} 


void *producer(void* args)
{
	int i;
   int x;
   char* st = malloc(32);
   char** retst=malloc(sizeof(char*));
   /*sem_post(&sem_p);*/
   for(i=0;i<2;i++){
   	x= (int)syscall(__NR_gettid);
	  sprintf(st,"my pid is%d\n", x);
      printf("my message: %s\n",  st);
      enqueue((Queue*)((void**)args)[0],st);
      dequeue((Queue*)((void**)args)[1] , retst);
      
      sprintf(st,"my pid is%d\n", x);
      printf("i got message: %s\n",  *retst);
  }
   
}



void main()
{
   Queue* qpc = createQueue(5);
   Queue* qcp = createQueue(5);
   producers* prods= createProducers(qpc,qcp,10);
   consumers* cons= createConsumers(qpc,qcp,10);
   joinProducers(prods);
   enqueue(qpc,"stop");
   joinConsumers(cons);
   

   return;
}



