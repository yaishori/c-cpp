typedef struct producers producers;

producers* createProducers(Queue* QPC, Queue* QCP,int size);
void joinProducers(producers* myprods);
void *producer(void* args);