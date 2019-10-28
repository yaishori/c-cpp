#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <queue>

using namespace std;

class tokenizer_t{
	public:
		~tokenizer_t();
		tokenizer_t(){};
		
		queue<string>& tokenizer(const string& line);

	private:
		queue<string> m_tokens;
		tokenizer_t(const tokenizer_t&);
		tokenizer_t& operator=(const tokenizer_t&);
		static string delimiters;
};



#endif