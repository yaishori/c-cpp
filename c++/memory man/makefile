
aprog : memTest.o memManager_t.o memPage_t.o memPool_t.o
	g++ -o  aprog memTest.o memManager_t.o memPage_t.o memPool_t.o

memTest.o : memTest.cpp memManager_t.h memPage_t.h
	g++ -c -g memTest.cpp
memManager_t.o : memManager_t.cpp memManager_t.h
	g++ -c -g memManager_t.cpp
memPage_t.o : memPage_t.cpp memPage_t.h memManager_t.h
	g++ -c  -g memPage_t.cpp
memPool_t.o : memPool_t.cpp memPool_t.h memPage_t.h 
	g++ -c  -g memPool_t.cpp
