#include <string>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

class memManager_t{

public:
	memManager_t();
	memManager_t(const unsigned int pos, const unsigned int actual);
	virtual unsigned int readData(void* buff,unsigned int nbytes){return 0;}
	virtual unsigned int readData(void* buff,unsigned int nbytes, unsigned int position){return 0;}
	virtual unsigned int writeData(const void* buff,unsigned int nbytes){return 0;}
	virtual unsigned int writeData(const void* buff,unsigned int nbytes, unsigned int position){return 0;}
	virtual unsigned int getPosition()const{
		return m_position;
	}
	
	virtual unsigned int getActualSize()const{
		return m_actualSize;
	}


	virtual void setPosition(unsigned int pos){
		m_position=pos;
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