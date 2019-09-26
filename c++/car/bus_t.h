#include "car_t.h"

class bus_t:public car_t{

public:
	~bus_t();
	bus_t();
	bus_t(const int cap);

private:
	unsigned int numSeats;
	unsigned int numLines;
	
	bus_t(const car_t &car);

};