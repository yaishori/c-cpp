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
		cout<<v[i]->getString()<<endl;
	}
}


unsigned int memPool_t::readData(void* buff,const unsigned int nbytes){
		readData(buff,nbytes,getPosition());
}

unsigned int memPool_t::readData(void* buff,unsigned int nbytes, unsigned int position){
	unsigned int pagePosPlusBytes;
	unsigned int bytescounter;
	unsigned int count=0;
	unsigned int readCounter=0;
	unsigned int capa=v[0]->getCapacity();
	unsigned int bytesOffset=position%capa;
	unsigned int pagePos=position/capa;
	unsigned int bytes=getActualSize()-position;
	
	if(position>=getActualSize()){
		buff=0;
		return 0;
	}

	if(nbytes>bytes-1){
		nbytes=bytes;
	}
	bytescounter=nbytes;

	/*pagePosPlusBytes=(position+nbytes)/capa;
	if (pagePos ==pagePosPlusBytes){
		setPosition(position+nbytes);
		 return v[pagePos]->readData(buff,nbytes,bytesOffset);
	}*/
	while(bytescounter){
	//secondCount= nbytes - firstCount;
		count =v[pagePos]->readData((char*)buff+readCounter,bytescounter,bytesOffset);
		readCounter= readCounter+count;
		bytescounter=bytescounter-count;
		bytesOffset=bytesOffset+count;
		setPosition(position+count);
		if(bytesOffset+1==capa){
			bytesOffset=(bytesOffset+1)%capa;
			setPosition(position+2);
			pagePos++;
		}
	}

	 
	 return nbytes;
}

unsigned int memPool_t::writeData(void* buff,const unsigned int nbytes){
		writeData(buff,nbytes,getPosition());
}

unsigned int memPool_t::writeData(void* buff,unsigned int nbytes, unsigned int position){
	unsigned int pagePosPlusBytes;
	unsigned int bytescounter;
	unsigned int count=0;
	unsigned int readCounter=0;
	unsigned int capa=v[0]->getCapacity();
	unsigned int bytesOffset=position%capa;
	unsigned int pagePos=position/capa;
	unsigned int actualSizeOffset;
	
	if(position>getActualSize()){
		buff=0;
		return 0;
	}
	bytescounter=nbytes;
	
	/*if (pagePos ==pagePosPlusBytes){
		setPosition(position+nbytes);
		if(getPosition()>getActualSize()){
		 	setActualSize(getPosition());
		 	actualSizeOffset=getActualSize()%capa;
		 	char* my=(char*)(v[pagePos]->getString());
			my[actualSizeOffset]='\0';
		}
		 return v[pagePos]->writeData(buff,nbytes,bytesOffset);
	}*/
	while(bytescounter){
	//secondCount= nbytes - firstCount;
		count =v[pagePos]->writeData((char*)buff+readCounter,bytescounter,bytesOffset);
		readCounter= readCounter+count;
		bytescounter=bytescounter-count;
		bytesOffset=bytesOffset+count;
		setPosition(position+count);
		if(getPosition()>getActualSize()){
				setActualSize(getPosition());
		}
		if(bytesOffset+1==capa){
			setPosition(position+2);
			if(getPosition()>getActualSize()){
				setActualSize(getPosition());
			}
			bytesOffset=(bytesOffset+1)%capa;
			if(pagePos==v.size()-1){
				memPage_t* page =new memPage_t;
				v.insert(v.end(),page);
			}
			pagePos++;
		}
	}

	if(getPosition()>getActualSize()){///need to make function
			setActualSize(getPosition());
			actualSizeOffset=getActualSize()%capa;
			char* my;
			my=(char*)(v[pagePos]->getString());
			my[actualSizeOffset]='\0';
	}

	 return (nbytes);
}