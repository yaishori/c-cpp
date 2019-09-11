
typedef struct Queue Queue;

Queue* createQueue(unsigned long capacity);
void deleteQueue(Queue*  q);
int enqueue(Queue* q, char* st);
int dequeue(Queue* q, char** st);