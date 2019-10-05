#include <string>
using namespace std;

#ifndef H_EXCEP
#define H_EXCEP

template <class T> 
class TException_t {
public:
	~TException_t(){;}
	TException_t();

	TException_t(const T& obj,const string& message,const char* file,const int line); 
	const T& getObject() const;

	const string& getMessage() const;

	const char* getFile() const;

	const int& getLine() const;

private:
	T m_object;
	string m_message;
	const char* m_file;
	int m_line;
};

template <class T> 
TException_t<T>::TException_t(){
		m_object=0;
		m_message="";
		m_file="";
		m_line=-1;
}

template <class T> 
TException_t<T>::TException_t(const T& obj,const string& message,const char* file, const int line){
		m_object=obj;
		m_message=message;
		m_file=file;
		m_line=line;
}

template <class T> 
const T& TException_t<T>::getObject() const{
		return m_object;
}

template <class T> 
const string& TException_t<T>::getMessage() const{
		return m_message;
}

template <class T> 
const char* TException_t<T>::getFile() const{
		return m_file;
}

template <class T> 
const int& TException_t<T>::getLine() const{
		return m_line;
}

#endif