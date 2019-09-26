#include "bus_t.h"


bus_t::bus_t(){
	car_t::setName("bus");
	car_t::setGear("standard");
	numLines=0;
	numSeats=0;
}

bus_t::bus_t(const int cap,unsigned int lines,unsigned int seats )car_t(cap){
	car_t::setName("bus");
	car_t::setGear("standard");
	numLines=lines;
	numSeats=seats;
}



bus_t::~bus_t(){
	
}

