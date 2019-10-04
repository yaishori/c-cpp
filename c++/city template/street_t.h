#include "building_t.h"
#include <vector>
using namespace std;

#ifndef H_STREET
#define H_STREET

template <class BID, class SID> 
class street_t { 
public:
	~street_t(){;}
	street_t(){;}

	street_t(const street_t& street);

	street_t& operator=(const street_t& street);

	const SID& getStreetID() const;
	void setStreetID(const SID& id);
	void addBuilding2Street(const building_t<BID>&);
	const building_t<BID>& getBuilding(const BID& id)const;

private: 
    SID m_id;
    vector <building_t<BID> > v;  
};

template <class BID, class SID> 
street_t<BID,SID>::street_t(const street_t& street){
		m_id= street.m_id;
		v= street.v;
}

template <class BID, class SID> 
street_t<BID,SID>& street_t<BID,SID>::operator=(const street_t& street){
		if(this!=&street){
			m_id= street.m_id;
			v= street.v;
		}
		return *this;	
} 
template <class BID, class SID> 
const SID& street_t<BID,SID>::getStreetID() const{
		return m_id;
}

template <class BID, class SID> 
void street_t<BID,SID>::setStreetID(const SID& id){
		m_id=id;
}

template <class BID, class SID> 
void street_t<BID,SID>::addBuilding2Street(const building_t<BID>& building){
		v.insert(v.end(),building);
}

template <class BID, class SID> 
const building_t<BID>& street_t<BID,SID>::getBuilding(const BID& id)const{
	int i;
	for(i=0;i<v.size();i++){
		if(v[i].getBuildingID()==id){
			return v[i];
		}
	}//add exeption handler
}

#endif