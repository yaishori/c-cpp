#include <string>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

#ifndef H_MAN
#define H_MAN

class memManager_t{

public:
	memManager_t();
	memManager_t(const unsigned int pos, const unsigned int actual);
	virtual unsigned int readData(void* buff,unsigned int nbytes)=0;
	virtual unsigned int readData(void* buff,unsigned int nbytes, unsigned int position)=0;
	virtual unsigned int writeData(void* buff,unsigned int nbytes)=0;
	virtual unsigned int writeData(void* buff,unsigned int nbytes, unsigned int position)=0;
	virtual unsigned int getPosition()const{
		return m_position;
	}
	
	virtual unsigned int getActualSize()const{
		return m_actualSize;
	}


	virtual void setPosition(unsigned int pos){
		m_position = pos;
		/*if (pos > m_actualSize){
			throw pos;
		}
		else {
			m_position = pos;
			return;
		}*/
	}
	virtual void setActualSize(unsigned int actual){
		m_actualSize=actual;
	}

	virtual bool isEmpty()const{
		return(m_actualSize==0);
	}

protected:
	virtual ~memManager_t(){return;};

private:
	unsigned int m_position;
	unsigned int m_actualSize;  

};

#endif