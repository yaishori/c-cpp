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

car_t::car_t(const car_t &car){
	capacity=car.capacity;
}

car_t& car_t:: operator=(const car_t& car){
		if(this!=&car){
			capacity=car.capacity;
		}
		return *this;
}

bool car_t:: operator<(car_t& car)const{
	return(capacity<car.capacity);
}

bool car_t::typecmp(car_t& car)const{
	return(name.compare(car.name));
}

car_t::~car_t(){
	
}

