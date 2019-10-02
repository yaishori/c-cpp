#include "memPage_t.h"

unsigned int memPage_t::defaultSize=6;


	memPage_t::~memPage_t(){
		delete m_page;
	}
	memPage_t::memPage_t():m_capacity(defaultSize){
		m_page= new char[defaultSize];
		m_page[0]=0;
	}
	memPage_t::memPage_t(const unsigned int pos, const unsigned int actual,const char* page):memManager_t(pos,actual),m_capacity(defaultSize){
		m_page= new char[m_capacity];
		memcpy(m_page,page,m_capacity-1);
		m_page[m_capacity-1]=0;
		setActualSize(strlen(m_page));

	}


	unsigned int memPage_t::readhelper(void* buff,unsigned int bytes,unsigned int position){
			memcpy(buff,m_page+position,bytes);
			*((char*)buff+bytes)=0;
			setPosition(position+bytes);	
			return bytes;
	}

	unsigned int memPage_t::readData(void* buff,const unsigned int nbytes){
		readData(buff,nbytes,getPosition());
	}

	unsigned int memPage_t::readData(void* buff,unsigned int nbytes, unsigned int position){
		unsigned int bytes;
		if(position>=getActualSize()){
			buff=0;
			return 0;
		}
		bytes=getActualSize()-position;
		if(nbytes>bytes){
			 return readhelper(buff,bytes,position);
		}
		else{
			return readhelper(buff,nbytes,position);
		}
	}

	unsigned int memPage_t::writeHelper(void* buff,unsigned int bytes, unsigned int position){
		memcpy(m_page+position,buff,bytes);
		

		setPosition(position+bytes);
		if(getPosition()>getActualSize()){
			setActualSize(getPosition());
			m_page[getActualSize()]='\0';
		}
		return bytes;
	}

	unsigned int memPage_t::writeData(void* buff,unsigned int nbytes){
		writeData(buff,nbytes,getPosition());
	}
	
	unsigned int memPage_t::writeData(void* buff,unsigned int nbytes, unsigned int position){
		unsigned int bytes;
		if(position<=getActualSize()){
			bytes=m_capacity-1-position;
			if(nbytes>bytes){
				return writeHelper(buff,bytes,position);
			}
			else{
				return writeHelper(buff,nbytes,position);
			}
		}
		return 0;
	}