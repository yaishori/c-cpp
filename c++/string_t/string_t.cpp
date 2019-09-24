#include "string_t.h"

string_t::string_t(){
		s=new char[1];
		len = 0;
}

string_t::string_t(const char* str){
		createMyString(str);
}

string_t::string_t(const string_t &str){
		createMyString_t(str);

}

string_t& string_t:: operator=(const string_t& str){
		if(this!=&str){
			delete []s;
			createMyString_t(str);
		}
		return *this;
}

string_t::~string_t(){
		delete []s;
}

void string_t:: setString(const char* str) {
	  delete []s;
	  createMyString(str);
}

int string_t:: getLen() const{
		return len;
}

const char* string_t::getString() const{
		return s;
}

int string_t::string_tCmp(const string_t& str) const{
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

void string_t:: print() const{
		cout << "string:" << endl;
		cout << s << endl;
		cout << len << endl;
}

void string_t::upperCase() {
		int i=0;
		char c;
		while (s[i])
		{
		   c=s[i];
		   s[i]=toupper(c);
		   i++;
		 }

}

void string_t::lowerCase() {
		int i=0;
		char c;
		while (s[i])
		{
		   c=s[i];
		   s[i]=tolower(c);
		   i++;
		 }

}

void string_t:: prePend(string_t& str) {
	  	char* x=new char[strlen(str.s)+strlen(s)+1];
		strcpy(x,str.s);
		strcat(x,s);
		delete []s;
		createMyString(x);
}

string_t& string_t:: operator+=(string_t& str){
		char* x=new char[strlen(str.s)+strlen(s)+1];
		strcpy(x,s);
		strcat(x,str.s);
		delete []s;
		createMyString(x);
		return *this;
}

bool string_t:: operator<(string_t& str)const{
	return(string_tCmp(str)==1);
	
}

bool string_t:: operator>(string_t& str)const{
	return(string_tCmp(str)==2);
}

bool string_t:: operator==(string_t& str)const{
	return(string_tCmp(str)==0);
}

bool string_t:: operator<=(string_t& str)const{
	return(string_tCmp(str)!=2);
}

bool string_t:: operator>=(string_t& str)const{
	return(string_tCmp(str)!=1);
}

bool string_t:: operator!=(string_t& str)const{
	return(string_tCmp(str)!=0);
}

int string_t::contains(string_t& str)const {
	  	return (locatin(s,str.s)!=-1);

}

char& string_t::operator[](int index) 
{ 
    if (index >= len) 
    { 
        cout << "out of bound"<<endl; 
        exit(0); 
    } 
    return s[index]; 
} 

void string_t::createMyString(const char* str){
	s=new char[strlen(str)+1];
	strcpy(s,str);
	len = strlen(str);
}

void string_t::createMyString_t(const string_t &str){
		s=new char[strlen(str.s)+1];
		strcpy(s,str.s);
		len = str.len;
}


ostream& operator<<(ostream& os, const string_t& str)
{
    os << str.getString() << '/' << str.getLen() << endl;
    return os;
}

int locatin(char* str1,char* str2){
	int len =strlen(str2);
	int count = 0;
	int flag = 0;
	int ret;
	if(str1==NULL ||str2==NULL)
	return -1;
	while(*str1 != '\0'){
		if(!memcmp(str1,str2,len)){     /*if return 0 so str1 and str2 are equal*/
		flag=1;
		break;
		}
	count++;
	str1++;
	}
	ret = (flag) ? count : -1;
	return ret;	
}

