#ifndef ASCII_H
#define ASCII_H

#include "virtIO_t.h"
#include <string.h>
using namespace std;

class asciiIO_t : public virthIO_t{

	public:
		~asciiIO_t(){;};
		asciiIO_t();
		asciiIO_t(const char * name,const char * mode);

		asciiIO_t& operator>>(int& num);
		asciiIO_t& operator<<(int num);
		asciiIO_t& operator>>(unsigned int& num);
		asciiIO_t& operator<<(unsigned int num);
		asciiIO_t& operator>>(char& num);
		asciiIO_t& operator<<(char num);
		asciiIO_t& operator>>(unsigned char& num);
		asciiIO_t& operator<<(unsigned char num);
		asciiIO_t& operator>>(short& num);
		asciiIO_t& operator<<(short num);
		asciiIO_t& operator>>(unsigned short& num);
		asciiIO_t& operator<<(unsigned short num);
		asciiIO_t& operator>>(long& num);
		asciiIO_t& operator<<(long num);
		asciiIO_t& operator>>(unsigned long& num);
		asciiIO_t& operator<<(unsigned long num);
		asciiIO_t& operator>>(float& num);
		asciiIO_t& operator<<(float num);
		asciiIO_t& operator>>(double& num);
		asciiIO_t& operator<<(double num);


	private:
		asciiIO_t(const asciiIO_t &asc);
		asciiIO_t& operator=(const asciiIO_t& asc);
		template <class T> asciiIO_t& writeHelper(T,const char* format);
		template <class T> asciiIO_t& readHelper(T&,const char* format);

};

#endif

