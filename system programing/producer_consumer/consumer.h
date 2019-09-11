typedef struct consumers consumers;

consumers* createConsumers(Queue* QPC, Queue* QCP,int size);
void joinConsumers(consumers* mycons);
void *consumer(void* args);