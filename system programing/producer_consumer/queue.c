#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

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

int isEmpty(Queue* q){
    return (q->size == 0);
}

int isFull(Queue* q){
    return q->size == q->capacity;
}

