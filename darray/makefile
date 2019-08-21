CFLAGS  = -ansi -pedantic 

aprog : hello.o darray_int.o 
	gcc -o aprog hello.o darray_int.o

darray_int.o : darray_int.c darray_int.h
	gcc -c $(CFLAGS) darray_int.c

hello.o : hello.c darray_int.h
	gcc -c $(CFLAGS) hello.c