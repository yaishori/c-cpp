#include "asciiIO_t.h"

asciiIO_t::asciiIO_t() : virthIO_t(){
}

asciiIO_t::asciiIO_t(const char* name, const char* mode) : virthIO_t(name, mode){
}

asciiIO_t& asciiIO_t::operator>>(int& num){
	return readHelper(num,"%d");
}
asciiIO_t& asciiIO_t::operator<<(int num){
	return writeHelper(num,"%d");
}
asciiIO_t& asciiIO_t::operator>>(unsigned int& num){
	return readHelper(num,"%u");
}
asciiIO_t& asciiIO_t::operator<<(unsigned int num){
	return writeHelper(num,"%u");
}
asciiIO_t& asciiIO_t::operator>>(char& num){
	return readHelper(num,"%c");
}
asciiIO_t& asciiIO_t::operator<<(char num){
	return writeHelper(num,"%c");
}
asciiIO_t& asciiIO_t::operator>>(unsigned char& num){
	return readHelper(num,"%u");
}
asciiIO_t& asciiIO_t::operator<<(unsigned char num){
	return writeHelper(num,"%u");
}
asciiIO_t& asciiIO_t::operator>>(short& num){
	return readHelper(num,"%hd");
}
asciiIO_t& asciiIO_t::operator<<(short num){
	return writeHelper(num,"%hd");
}
asciiIO_t& asciiIO_t::operator>>(unsigned short& num){
	return readHelper(num,"%hu");
}
asciiIO_t& asciiIO_t::operator<<(unsigned short num){
	return writeHelper(num,"%hu");
}
asciiIO_t& asciiIO_t::operator>>(long& num){
	return readHelper(num,"%ld");
}
asciiIO_t& asciiIO_t::operator<<(long num){
	return writeHelper(num,"%ld");
}
asciiIO_t& asciiIO_t::operator>>(unsigned long& num){
	return readHelper(num,"%lu");
}
asciiIO_t& asciiIO_t::operator<<(unsigned long num){
	return writeHelper(num,"%lu");
}
asciiIO_t& asciiIO_t::operator>>(float& num){
	return readHelper(num,"%f");
}
asciiIO_t& asciiIO_t::operator<<(float num){
	return writeHelper(num,"%f");
}
asciiIO_t& asciiIO_t::operator>>(double& num){
	return readHelper(num,"%f");
}
asciiIO_t& asciiIO_t::operator<<(double num){
	return writeHelper(num,"%f");
}




template <class T> asciiIO_t& asciiIO_t::writeHelper(T var,const char* format){
	FILE* fd = getFd();
	if ( (strcmp(getMode(),"r")!=0) && getStatus() == ok_e){
		fprintf(fd, format, var);
		return *this;
	}
	else {
		setStatus(writeErr_e);
		throw writeErr_e;  
	}
}

template <class T> asciiIO_t& asciiIO_t::readHelper(T& var,const char* format){
	FILE* fd = getFd();

	if ( (strcmp(getMode(),"w")!=0) && getStatus() == ok_e){
		fscanf(fd, format, &var);	
	}
	else {
		setStatus(readErr_e);
		throw readErr_e;  
	}
}
