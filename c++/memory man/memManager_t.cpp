#include "memManager_t.h"


memManager_t::memManager_t(){
	m_position=0;
	m_actualSize=0;
}

memManager_t::memManager_t(const unsigned int pos, const unsigned int actual){
	m_position=pos;
	m_actualSize=actual;
}

