#include "memManager_t.h"

#ifndef H_PAGE
#define H_PAGE

class memPage_t: virtual public memManager_t{
public:
	virtual ~memPage_t();
	memPage_t();
	memPage_t(const unsigned int pos, const unsigned int actual,const char* page);
	virtual unsigned int getCapacity()const{
		return m_capacity;
	}
	const char* getString() const{
			return m_page;
	}
	virtual unsigned int readhelper(void* buff,unsigned int bytes, unsigned int position);
	virtual unsigned int readData(void* buff,unsigned int nbytes);
	virtual unsigned int readData(void* buff,unsigned int nbytes, unsigned int position);
	virtual unsigned int writeHelper(void* buff,unsigned int bytes, unsigned int position);
	virtual unsigned int writeData(void* buff,unsigned int nbytes);
	virtual unsigned int writeData(void* buff,unsigned int nbytes, unsigned int position);
	bool isFull(){
		return (getActualSize()==defaultSize+1);
	}

private:
	const unsigned int m_capacity;
	static unsigned int defaultSize;
	char* m_page;
};

#endif