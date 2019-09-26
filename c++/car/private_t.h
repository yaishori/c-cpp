#include <string.h> 
#include <iostream> 
#include "car.h"
using namespace std;

class private_t : public car_t{
public:
	void accelerate();
	void reduceSpeed();
	int getSpeed();
	private_t();
	private_t(unsigned int cap);
	private_t(const private_t& priv);
	~private_t();


private:
	int speed;
};