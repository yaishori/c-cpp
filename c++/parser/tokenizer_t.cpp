#include "tokenizer_t.h"

tokenizer_t::~tokenizer_t(){;}

queue<string>& tokenizer_t::tokenizer(const string& line){
	const char delimiters[] =" \n\t\v\f\r;()[]{}<>=+-*&";
	unsigned int found =line.find_first_of(delimiters);
	unsigned int from =0;
	while (found != string::npos){
		if(from != found){
			m_tokens.push(line.substr(from,found-from));
		}
		if(!isspace(line[found])){
			m_tokens.push(line.substr(found,1));
		}

		from=found+1; 
		found=line.find_first_of(delimiters,from);
	}
	return m_tokens;
}