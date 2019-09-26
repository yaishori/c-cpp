#include "car_t.h"

class bus_t:public car_t{

public:
	~bus_t();
	bus_t();
	bus_t(const int cap);
	bus_t(const car_t &car);

private:
	unsigned int numSeats;
	unsigned int numLines;

};