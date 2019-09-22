#ifndef H_STRING
#define H_STRING

class string_t{
public:
	string_t();
	string_t(const char* str);
	string_t(const string_t &str);
	string_t& operator=(const string_t& str);
	~string_t();
	void setString(const char* str);
	int getLen();
	const char* getString();
	int string_tCmp(const string_t& str);
	void print();
private:
	char* s;
	int len;
};

#endif