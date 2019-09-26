#include "car_t.h"

int car_t::globalID =0;
int car_t::defaultCap=1500;

car_t::car_t():id(globalID++){
	capacity =defaultCap;
	name="";
	gear="";
}

car_t::car_t(const int cap)id(globalID++){
	capacity=cap;
	name="";
	gear="";
}


bool car_t:: operator<(car_t& car)const{
	return(capacity<car.capacity);
}

bool car_t::typecmp(car_t& car)const{
	return(name.compare(car.name));
}

car_t::~car_t(){
	
}

