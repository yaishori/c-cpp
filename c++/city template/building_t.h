#ifndef H_BUILD
#define H_BUILD

template <class BID> 
class building_t { 
public:
	~building_t(){;}
	building_t(){;}

	building_t(const building_t& building);

	building_t& operator=(const building_t& building);

	const BID& getBuildingID() const;
	void setBuildingID(const BID id);

private: 
    BID m_id;  
};

template <class BID> 
building_t<BID>::building_t(const building_t& building){
		m_id= building.m_id;
}

template <class BID> 
building_t<BID>& building_t<BID>::operator=(const building_t& building){
		if(this!=&building){
			m_id= building.m_id;
		}
		return *this;	
} 
template <class BID> const BID& building_t<BID>::getBuildingID() const{
		return m_id;
}

template <class BID> 
void building_t<BID>::setBuildingID(const BID id){
		m_id=id;
}

#endif