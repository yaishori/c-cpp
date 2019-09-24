#include "string_t.h"

int string_t::numOfString =0;
int string_t::caseSense=1;
int string_t::defaultCap=16;

string_t::string_t(){
		numOfString++;
		capacity =defaultCap;
		s=new char[defaultCap];
		s[0]=0;
		len = 0;
}

string_t::string_t(const char* str){
		numOfString++;
		createMyString(str);
}

string_t::string_t(const string_t &str){
		numOfString++;
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
		numOfString--;
}

void string_t:: setString(const char* str) {
	  delete []s;
	  createMyString(str);
}

int string_t::setDefCap(int def){
	unsigned int nextpower=nextPowerOf2(def);
	defaultCap=nextpower;
}


int string_t::string_tCmp(const string_t& str) const{
		int ret;
		if (caseSense==0){ 
			ret=strcasecmp(s,str.s);
		}
		else{
			ret=strcmp(s,str.s);
		}
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

int string_t::firstOccur(char x) const{
	char *e;
	char y;
	int index1=-1;
	int index2=-1;
	if(caseSense!=0){
		e = strchr(s, x);
		index1 = (int)(e - s);
	}
	else{
		y=char(tolower(x));
		e = strchr(s, y);
		index1 = (int)(e - s);
		y=(char)(toupper(x));
		e = strchr(s, y);
		index2 = (int)(e - s);
			if(index2<index1){
				index1=index2;
			}
	}
	return index1;
}

int string_t::lastOccur(char x) const{
	char *e;
	char y;
	int index1=-1;
	int index2=-1;
	if(caseSense!=0){
		e = strrchr(s, x);
		index1 = (int)(e - s);
	}
	else{
		y=char(tolower(x));
		e = strrchr(s, y);
		index1 = (int)(e - s);
		y=(char)(toupper(x));
		e = strrchr(s, y);
		index2 = (int)(e - s);
			if(index2>index1){
				index1=index2;
			}
	}
	return index1;
}

string_t string_t::operator()(int start,int length){
	char dest[length+1];
	strncpy(dest, s+start, length);
	dest[length+1]=0;
	string_t mystr(dest);
	return mystr;

}

void string_t:: print() const{
		cout << "string:" << endl;
		cout << s << endl;
		cout <<"len: "<< len << endl;
		cout <<"capacity: "<< capacity << endl;
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
	if(caseSense!=0){
	  	return (strstr(s,str.s)!=0);
	}
	else{
		return (strcasestr(s,str.s)!=0);
	}
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

char string_t::operator[](int index) const
{ 
    if (index >= len) 
    { 
        cout << "out of bound"<<endl; 
        exit(0); 
    } 
    return s[index]; 
} 

void string_t::createMyString(const char* str){
	unsigned int nextpower=nextPowerOf2(strlen(str)+1);
	s=new char[nextpower];
	strcpy(s,str);
	len = strlen(str);
	capacity=nextpower;
}

void string_t::createMyString_t(const string_t &str){
		unsigned int nextpower=nextPowerOf2(strlen(str.s)+1);
		s=new char[nextpower];
		strcpy(s,str.s);
		len = str.len;
		capacity=nextpower;
}


ostream& operator<<(ostream& os, const string_t& str)
{
    os << str.getString() << '/' << str.getLen() << endl;
    return os;
}

istream& operator>>(istream& is, string_t& str){
	char buf[1024];
	is >> buf;
	str.setString(buf);
	return is;
}



unsigned int nextPowerOf2(unsigned int n)  
{  
    unsigned count = 0;  
      
    if (n && !(n & (n - 1)))  
        return n;  
      
    while( n != 0)  
    {  
        n >>= 1;  
        count += 1;  
    }  
      
    return 1 << count;  
}  