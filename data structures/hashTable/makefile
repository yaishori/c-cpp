CFLAGS  = -ansi -pedantic 


aprog : hashTableTest.o hashTable.o 
	gcc -o aprog hashTableTest.o hashTable.o
	
hashTable.o : hashTable.c hashTable.h
	gcc -c $(CFLAGS) hashTable.c
hashTableTest.o : hashTableTest.c hashTable.h
	gcc -c $(CFLAGS) hashTableTest.c