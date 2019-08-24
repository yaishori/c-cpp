CFLAGS  = -ansi -pedantic 


aprog : hello.o darray_generic.o 
	gcc -o aprog hello.o darray_generic.o
	
darray_generic.o : darray_generic.c darray_generic.h
	gcc -c $(CFLAGS) darray_generic.c
hello.o : hello.c darray_generic.h
	gcc -c $(CFLAGS) hello.c