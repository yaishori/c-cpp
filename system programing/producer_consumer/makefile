pro : prodoucer.o consumer.o queue.o
	gcc -g -o sol producer.o consumer.o queue.o -lpthread

queue.o : queue.c queue.h
	gcc  -g -c queue.c

prodoucer.o : producer.c queue.h producer.h
	gcc -g -c producer.c

consumer.o : consumer.c queue.h consumer.h
	gcc -g -c  consumer.c