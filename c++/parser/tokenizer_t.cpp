#include "tokenizer_t.h"
#include "ctype.h"

string tokenizer_t::delimiters = "()[]{};<>=+-*&, \t\n\f\v\r";

tokenizer_t::~tokenizer_t(){;}

queue<string>& tokenizer_t::tokenizer(const string& line){

	size_t found = line.find_first_of(delimiters);
	size_t from =0;
	/*while (found != string::npos){
		if(from != found){
			m_tokens.push(line.substr(from,found-from));
		}
		if(!isspace(line[found])){
			m_tokens.push(string(1,line[found]));
		}

		from=found+1; 
		found=line.find_first_of(delimiters,from);
	}*/

	while (found != string::npos) {
		if (line.substr(from, found - from).size() != 0)
        	m_tokens.push(line.substr(from, found - from));

        if (isspace(line[found]) == 0 && line[found] != '\0')
        	m_tokens.push(string(1,line[found]));

        from = found + 1;
        found = line.find_first_of(delimiters, from);
    }
    
    if (isspace(line[found]) == 0 && line[found] != '\0'){
    	m_tokens.push(line.substr(from, found - from));
    }

	return m_tokens;
}