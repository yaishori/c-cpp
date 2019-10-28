CFLAGS  = -pedantic -g -ansi -Wall 

qqprog : qq.o parser_t.o tokenizer_t.o analyzer_t.o
	g++ -o qqprog qq.o analyzer_t.o parser_t.o tokenizer_t.o

qq.o : qq.cpp parser_t.h 
	g++ -c $(CFLAGS) qq.cpp

parser_t.o : parser_t.cpp parser_t.h tokenizer_t.h analyzer_t.h
	g++ -c $(CFLAGS) parser_t.cpp 

tokenizer_t.o : tokenizer_t.cpp tokenizer_t.h
	g++ -c $(CFLAGS) tokenizer_t.cpp

analyzer_t.o : analyzer_t.cpp analyzer_t.h 
	g++ -c $(CFLAGS) analyzer_t.cpp