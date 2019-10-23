#include "binIO_t.h"

binIO_t::binIO_t() : virthIO_t(){
	m_buff = NULL;
}

binIO_t::binIO_t(const char* name, const char* mode) : virthIO_t(name, mode){
	m_buff = NULL;
}

binIO_t& binIO_t::operator>>(int& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(int num){
	return writeHelper(num);
}
binIO_t& binIO_t::operator>>(unsigned int& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(unsigned int num){
	return writeHelper(num);
}
binIO_t& binIO_t::operator>>(char& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(char num){
	return writeHelper(num);
}
binIO_t& binIO_t::operator>>(unsigned char& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(unsigned char num){
	return writeHelper(num);
}
binIO_t& binIO_t::operator>>(short& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(short num){
	return writeHelper(num);
}
binIO_t& binIO_t::operator>>(unsigned short& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(unsigned short num){
	return writeHelper(num);
}
binIO_t& binIO_t::operator>>(long& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(long num){
	return writeHelper(num);
}
binIO_t& binIO_t::operator>>(unsigned long& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(unsigned long num){
	return writeHelper(num);
}
binIO_t& binIO_t::operator>>(float& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(float num){
	return writeHelper(num);
}
binIO_t& binIO_t::operator>>(double& num){
	return readHelper(num);
}
binIO_t& binIO_t::operator<<(double num){
	return writeHelper(num);
}

binIO_t& binIO_t::operator>>(void* buff){
	if(strcmp(getMode(),"w")!= 0){
		m_buff = buff;
		m_op = read;
		return *this;
	}
	else{
		throw readErr_e;
	}
}

binIO_t& binIO_t::operator<<(const void* buff){
	if(strcmp(getMode(),"r")!= 0){
		m_buff = (void*)buff;
		m_op = write;
		return *this;
	}
	else{
		throw writeErr_e;
	}
}

void binIO_t::operator,(int len){
	FILE* fd = getFd();
	if (m_buff != NULL){
		if (m_op == read){
			fread(m_buff, 1, len, fd);
			
		}
		else{
			fwrite(m_buff, 1, len, fd);
		}	
	}
}

template <class T> binIO_t& binIO_t::writeHelper(T var){
	FILE* fd = getFd();
	if ( (strcmp(getMode(),"r")!=0) && getStatus() == ok_e){
		fwrite(&var, sizeof(var), 1, fd);
		return *this;
	}
	else {
		setStatus(writeErr_e);
		throw writeErr_e;  
	}
}

template <class T> binIO_t& binIO_t::readHelper(T& var){
	FILE* fd = getFd();

	if ( (strcmp(getMode(),"w")!=0) && getStatus() == ok_e){
		fread(&var, sizeof(var), 1, fd);
		
	}
	else {
		setStatus(readErr_e);
		throw readErr_e;  
	}
}
