CFLAGS  = -ansi -pedantic 


aprog : md5.o hashTable.o findDup.o init.c
	gcc -g -o aprog  md5.o findDup.o hashTable.o init.c -lcrypto
	
md5.o : md5.c md5.h
	gcc -c md5.c 
hashTable.o : hashTable.c hashTable.h
	gcc -c $(CFLAGS) hashTable.c
findDup.o : findDup.c findDup.h hashTable.h  md5.h
	gcc -c $(CFLAGS) findDup.c
init.o : init.c hashTable.h findDup.h md5.h
	gcc -c $(CFLAGS) init.c
