#include <string>
#include <stdio.h>
#include <fstream> 
#include <iostream> 
#include "tokenizer_t.h"
#include "analyzer_t.h"
using namespace std;

#ifndef PARSER_H
#define PARSER_H

class parser_t{
	public:
		parser_t();
		~parser_t();
		
		void readFile(const char* name);

	private:
	tokenizer_t* m_tokenizer;
	analyzer_t* m_analyzer;
};



#endif