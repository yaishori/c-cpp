#include "parser_t.h"
#include "tokenizer_t.h"
#include "analyzer_t.h"

parser_t::parser_t(){
	m_tokenizer=new tokenizer_t;
	m_analyzer=new analyzer_t;
}

parser_t::~parser_t()
{
	delete m_tokenizer;
	delete m_analyzer;
}

void parser_t::readFile(const char* name){
    myfile.open(name);

   if(!myfile.is_open()) {
     cout<<"wrong file"<<endl;
   }
    while(getline(myfile, line)) {
    
    m_analyzer->analyzer(m_tokenizer->tokenizer(line));
   
    }
    m_analyzer->endRun();
	myfile.close();
}
