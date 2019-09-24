#ifndef H_STRING
#define H_STRING

#include <string.h>
#include "string_t.h"
#include <stdio.h>
#include <ctype.h>
#include <iostream>
using namespace std;

class string_t{
public:
	~string_t();
	string_t();
	string_t(const char* str);
	string_t(const string_t &str);
	string_t& operator=(const string_t& str);
	void setString(const char* str);
	int getLen() const;
	const char* getString() const;
	int string_tCmp(const string_t& str) const;
	void print() const;
	void lowerCase();
	void upperCase();
	string_t& operator+=(string_t& str);
	bool operator<(string_t& str)const;
	bool operator>(string_t& str)const;
	bool operator<=(string_t& str)const;
	bool operator>=(string_t& str)const;
	bool operator==(string_t& str)const;
	bool operator!=(string_t& str)const;
	void prePend(string_t& str);
	int contains(string_t& str)const;
	char& operator[](int index);
private:
	char* s;
	int len;
	void createMyString(const char* str);
	void createMyString_t(const string_t &str);
	
};

ostream& operator<<(ostream& os, const string_t& str);

int locatin(char* str1,char* str2);
#endif