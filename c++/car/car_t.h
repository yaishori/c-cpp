#include <string>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

class car_t{

public:
	car_t();
	car_t(const int cap);
	car_t(const car_t &car);
	car_t& operator=(const car_t& car);
	bool operator<(car_t& car)const;
	bool typecmp(car_t& car)const;

protected:
	~car_t();
	string getGear() const{
		return gear;
	}

	string getName() const{
		return name;
	}

	setGear(string myGear){
		delete gear;
		gear=myGear;
	}

	setName(string myName){
		delete name;
		name=myName;
	}




private:
	static int globalID;
	static int defaultCap;
	const unsigned int id;
	unsigned int capacity;
	string gear;
	string name; 

};