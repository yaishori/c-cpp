#include "private.h"

private_t::private_t(){
	speed = 0;
	car_t::setName("private");
	car_t::setGear("automatic");
}

private_t::private_t(unsigned int cap):car_t(cap){	
	speed = 0;
	car_t::setName("private");
	car_t::setGear("automatic");	
}


private_t::~private_t(){
	
}

void private_t::accelerate(){
	speed+=10;
}

void private_t::reduceSpeed(){
	speed-=10;
}

int private_t::getSpeed(){
	return speed;
}