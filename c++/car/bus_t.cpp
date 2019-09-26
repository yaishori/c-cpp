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

bus_t::bus_t(const bus_t &bus):car_t(bus){
	numLines=bus.numLines;
	numSeats=bus.numSeats;
}

bus_t& bus_t:: operator=(const bus_t& bus){
		if(this!=&bus){
			capacity=bus.capacity;
			numLines=bus.numLines;
			numSeats=bus.numSeats

		}
		return *this;
}

bus_t::~bus_t(){
	
}

