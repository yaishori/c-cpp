#include "memPage_t.h"
#include <vector>
using namespace std;

#ifndef H_POOL
#define H_POOL


class memPool_t: virtual public memManager_t{
public:
	virtual ~memPool_t();
	memPool_t();
	memPool_t(const unsigned int pos, const unsigned int actual,const char* page);
	virtual void print();
	virtual unsigned int readData(void* buff,unsigned int nbytes);
	virtual unsigned int readData(void* buff,unsigned int nbytes, unsigned int position);
	virtual unsigned int writeData(void* buff,unsigned int nbytes);
	virtual unsigned int writeData(void* buff,unsigned int nbytes, unsigned int position);
	const vector <memPage_t*> getVector() const{
			return v;
	}

private:
	vector <memPage_t*>v;
};

#endif