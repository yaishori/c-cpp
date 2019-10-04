#include "street_t.h"
#include <vector>
using namespace std;

#ifndef H_CITY
#define H_CITY

template <class BID, class SID, class CID> 
class city_t { 
public:
	~city_t(){;}
	city_t(){;}

	city_t(const city_t& city);

	city_t& operator=(const city_t& city);

	const CID& getCityID() const;
	void setCityID(const CID& id);
	void addStreet(const street_t<BID,SID>&);
	const street_t<BID,SID>& getStreet(const SID& id)const;

private: 
    CID m_id;
    vector <street_t<BID,SID> > v;  
};

template <class BID, class SID, class CID>  
city_t<BID,SID,CID>::city_t(const city_t& city){
		m_id= city.m_id;
		v= city.v;
}

template <class BID, class SID, class CID> 
city_t<BID,SID,CID>& city_t<BID,SID,CID>::operator=(const city_t& city){
		if(this!=&city){
			m_id= city.m_id;
			v= city.v;
		}
		return *this;	
} 
template <class BID, class SID, class CID>
const CID& city_t<BID,SID,CID>::getCityID() const{
		return m_id;
}

template <class BID, class SID, class CID> 
void city_t<BID,SID,CID>::setCityID(const CID& id){
		m_id=id;
}

template <class BID, class SID, class CID>  
void city_t<BID,SID,CID>::addStreet(const street_t<BID,SID>& street){
		v.insert(v.end(),street);
}

template <class BID, class SID, class CID> 
const street_t<BID,SID>& city_t<BID,SID,CID>::getStreet(const SID& id)const{
	int i;
	for(i=0;i<v.size();i++){
		if(v[i].getStreetID()==id){
			return v[i];
		}
	}//add exeption handler
}

#endif