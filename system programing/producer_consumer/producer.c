#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t sem_p; 
sem_t sem_c;

typedef struct Queue{
    char** array;
    unsigned long front, back, size, capacity;
    pthread_mutex_t lock;
    sem_t full;
    sem_t empty;  
}Queue;

Queue* createQueue(unsigned long capacity){
    Queue *q = malloc(sizeof(Queue));
    if(q != NULL){
	q->array = calloc(capacity, sizeof(char*));
	if(q->array == NULL){
	    free(q);
	    return NULL;
	}
	q->capacity = capacity;
	q->back = capacity - 1;
	q->front = 0;
	q->size = 0;
	pthread_mutex_init(&(q->lock), NULL);
	sem_init(&(q->full), 0, 0); 
	sem_init(&(q->empty), 0, capacity);
    }
    return q;

}

void deleteQueue(Queue*  q){
	free(q->array);
	free(q);
}

int enqueue(Queue* q, char* st){
	unsigned long ret;
	sem_wait(&(q->empty));
	pthread_mutex_lock(&(q->lock));
	q->back = (q->back + 1)%q->capacity;
    q->array[q->back] = st;
    ++q->size;
    pthread_mutex_unlock(&(q->lock));
    sem_post(&(q->full));
    return 0;
}

int dequeue(Queue* q, char** st){
	sem_wait(&(q->full));
	pthread_mutex_lock(&(q->lock));
    *st = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    --q->size;
    pthread_mutex_unlock(&(q->lock));
    sem_post(&(q->empty));
    return 0;
}


void *producer(void* q)
{
   int x;
   char* st = malloc(32);
   sem_post(&sem_p);
   
   	  x= (int)syscall(__NR_gettid);
	  sprintf(st,"my pid is%d\n", x);
      printf("my message: %s\n",  st);
      enqueue((Queue*)q,st);
   
}

void *consumer(void* q)
{
   int x;

   char** st = malloc(sizeof(char*)); 
   sem_post(&sem_c);
   
   	  x= (int)syscall(__NR_gettid);
      dequeue((Queue*)q,st);
      printf("my consumer index:%d\n",x);
      printf("my message:%s\n",*st);
   
}

void main()
{
   int i;
   pthread_t producer_t[10];
   pthread_t consumer_t[5];
   Queue* q = createQueue(40);
   sem_init(&sem_p, 0, 1);
   sem_init(&sem_c, 0, 1);


   for (i = 0; i < 10; i++){
   	  sem_wait(&sem_p);
      pthread_create(&producer_t[i], NULL, producer,q);
   }
    
   for (i= 0; i < 5; i++){
   	sem_wait(&sem_c);
      pthread_create(&consumer_t[i], NULL, consumer,q);
   }

   for (i = 0; i < 10; i++){
      pthread_join(producer_t[i], NULL);
   }


   for (i = 0; i < 5; i++)
      pthread_join(consumer_t[i], NULL);

   exit(0);
}


