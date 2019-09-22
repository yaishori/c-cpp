
aprog : string_t.o string_t_test.o
	g++ -o aprog string_t.o string_t_test.o

string_t.o : string_t.cpp string_t.h
	g++ -c  string_t.cpp
string_t_test.o : string_t_test.cpp string_t.h
	g++ -c  string_t_test.cpp
