CFLAGS  = -ansi -pedantic 

aprog : main.o 
	g++ -o aprog main.o 

main.o : main.cpp building_t.h street_t.h city_t.h
	g++ -c -g $(CFLAGS) main.cpp

