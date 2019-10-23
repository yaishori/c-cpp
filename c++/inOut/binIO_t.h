#ifndef BIN_H
#define BIN_H

#include "virtIO_t.h"
#include <string.h>
using namespace std;

typedef enum {read, write} Op;

class binIO_t : public virthIO_t{

	public:
		~binIO_t(){;};
		binIO_t();
		binIO_t(const char * name,const char * mode);

		binIO_t& operator>>(int& num);
		binIO_t& operator<<(int num);
		binIO_t& operator>>(unsigned int& num);
		binIO_t& operator<<(unsigned int num);
		binIO_t& operator>>(char& num);
		binIO_t& operator<<(char num);
		binIO_t& operator>>(unsigned char& num);
		binIO_t& operator<<(unsigned char num);
		binIO_t& operator>>(short& num);
		binIO_t& operator<<(short num);
		binIO_t& operator>>(unsigned short& num);
		binIO_t& operator<<(unsigned short num);
		binIO_t& operator>>(long& num);
		binIO_t& operator<<(long num);
		binIO_t& operator>>(unsigned long& num);
		binIO_t& operator<<(unsigned long num);
		binIO_t& operator>>(float& num);
		binIO_t& operator<<(float num);
		binIO_t& operator>>(double& num);
		binIO_t& operator<<(double num);

		binIO_t& operator>>(void* buff);
		binIO_t& operator<<(const void* buff);
		void operator,(int len);

	private:
		Op m_op;
		void* m_buff;
		binIO_t(const binIO_t &bin);
		binIO_t& operator=(const binIO_t& bin);
		template <class T> binIO_t& writeHelper(T);
		template <class T> binIO_t& readHelper(T&);

};

#endif

