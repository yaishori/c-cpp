CFLAGS  = -ansi -pedantic 

aprog : exceptionTest.o 
	g++ -o aprog exceptionTest.o 

exceptionTest.o : exceptionTest.cpp TException_t.h
	g++ -c -g $(CFLAGS) exceptionTest.cpp

