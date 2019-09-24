#ifndef H_STRING
#define H_STRING

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

class string_t{
public:
	~string_t();
	string_t();
	string_t(const char* str);
	string_t(const string_t &str);

	void setString(const char* str);
	/*static int setCase(int flag);*/
	static int setDefCap(int def);

	static int setCase(int flag){
		int prevCase=getCase();
		caseSense=flag;
		return prevCase;
	}

	/*int getLen() const;
	const char* getString() const;
	static int getDefCap();
	int getCapacity() const;
	static int getNumOfString();
	fdf int getCase();*/

	static int getCase(){
		return caseSense;
	}

	int getLen() const{
		return len;
	}

	static int getDefCap(){
		return defaultCap;
	}

	int getCapacity() const{
		return capacity;
	}
	static int getNumOfString(){
		return numOfString;
	}

	const char* getString() const{
			return s;
	}

	int string_tCmp(const string_t& str) const;
	int firstOccur(char x) const;
	int lastOccur(char x) const;
	void print() const;
	void lowerCase();
	void upperCase();
	void prePend(string_t& str);
	int contains(string_t& str)const;

	string_t& operator=(const string_t& str);
	string_t& operator+=(string_t& str);
	bool operator<(string_t& str)const;
	bool operator>(string_t& str)const;
	bool operator<=(string_t& str)const;
	bool operator>=(string_t& str)const;
	bool operator==(string_t& str)const;
	bool operator!=(string_t& str)const;
	char& operator[](int index);
	char operator[](int index) const;
	string_t operator()(int start,int length);
	
	

private:
	char* s;
	int len;
	int capacity;
	static int caseSense;
	static int defaultCap;
	static int numOfString;
	void createMyString(const char* str);
	void createMyString_t(const string_t &str);
	
};

ostream& operator<<(ostream& os, const string_t& str);
istream& operator>>(istream& is, string_t& str);

unsigned int nextPowerOf2(unsigned int n);
#endif