#include <string.h>
#include "string_t.h"
#include <stdio.h>
#include <iostream>
using namespace std;


string_t::string_t(){
		s=new char[1];
		len = 0;
}

string_t::string_t(const char* str){
		s=new char[strlen(str)+1];
		strcpy(s,str);
		len = strlen(str);
}

string_t::string_t(const string_t &str){
		s=new char[strlen(str.s)+1];
		strcpy(s,str.s);
		len = str.len;


}

string_t& string_t:: operator=(const string_t& str){
		if(this!=&str){
			delete []s;
			s=new char[strlen(str.s)+1];
			strcpy(s,str.s);
			len = str.len;
		}
		return *this;
}

string_t::~string_t(){
		delete []s;
}

void string_t:: setString(const char* str) {
	  delete []s;
	  s= new char[strlen(str)+1];
      strcpy(s,str);
      len = strlen(str);
}

int string_t:: getLen(){
		return len;
}

const char* string_t::getString(){
		return s;
}

int string_t::string_tCmp(const string_t& str){
		int ret= strcmp (s,str.s);
		if(ret == 0){
			return 0;
		}
		if(ret < 0){
			return 1;
		}
		if(ret > 0){
			return 2;
		}

}

void string_t:: print(){
		cout << "string:" << endl;
		cout << s << endl;
		cout << len << endl;
}


