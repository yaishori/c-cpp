#include "memPool_t.h"

memPool_t::memPool_t(){
	memPage_t* page =new memPage_t;
	v.insert(v.end(),page);
}

memPool_t::~memPool_t(){
	int i;
	for(i=0;i<v.size();i++){
		delete v[i];
	}
}

void memPool_t::print(){
	int i;
	for(i=0;i<v.size();i++){
		v[i]->print();
	}
}


unsigned int memPool_t::readData(void* buff,const unsigned int nbytes){
		readData(buff,nbytes,getPosition());
}

unsigned int memPool_t::readData(void* buff,unsigned int nbytes, unsigned int position){
	unsigned int pagePosPlusBytes;
	unsigned int firstCount;
	unsigned int secondCount;
	unsigned int bytesOffset=position%1024;
	unsigned int pagePos=position/v.size();
	unsigned int bytes=getActualSize()-position;
	if(nbytes>bytes-1){
		nbytes=bytes;
	}
	 pagePosPlusBytes=(position+nbytes-1)/v.size();
	
	if (pagePos ==pagePosPlusBytes){
		 return v[pagePos]->readData(buff,nbytes,bytesOffset);
	}
	firstCount= 1024-bytesOffset;
	secondCount= nbytes - firstCount;
	 firstCount = v[pagePos]->readData(buff,firstCount,bytesOffset);
	 secondCount= v[pagePosPlusBytes]->readData((char*)buff+firstCount,secondCount,0);
	 *((char*)buff+bytes)=0;

	 return (firstCount + secondCount);
}

unsigned int memPool_t::writeData(void* buff,const unsigned int nbytes){
		writeData(buff,nbytes,getPosition());
}

unsigned int memPool_t::writeData(void* buff,unsigned int nbytes, unsigned int position){
	unsigned int pagePosPlusBytes;
	unsigned int firstCount;
	unsigned int secondCount;
	unsigned int bytesOffset=position%1024;
	unsigned int pagePos=position/v.size();
	unsigned int bytes=getActualSize()-position;
	if(nbytes>bytes-1){
		nbytes=bytes;
	}
	 pagePosPlusBytes=(position+nbytes-1)/v.size();
	
	if (pagePos ==pagePosPlusBytes){
		 return v[pagePos]->writeData(buff,nbytes,bytesOffset);
	}
	firstCount= 1024-bytesOffset;
	secondCount= nbytes - firstCount;
	 firstCount = v[pagePos]->writeData(buff,firstCount,bytesOffset);
	 secondCount= v[pagePosPlusBytes]->writeData((char*)buff+firstCount,secondCount,0);
	 *((char*)buff+bytes)=0;

	 return (firstCount + secondCount);
}