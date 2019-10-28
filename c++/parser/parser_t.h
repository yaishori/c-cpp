#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <queue>
#include <stdio.h>
#include <fstream> 
#include <iostream> 
using namespace std;



class tokenizer_t;
class analyzer_t;

class parser_t{
	public:
		parser_t();
		~parser_t();
		
		void readFile(const char* name);

	private:
	string line;
    ifstream myfile;
	tokenizer_t* m_tokenizer;
	analyzer_t* m_analyzer;
	parser_t& operator=(const parser_t& parser);
	parser_t(const parser_t& parser);
};



#endif