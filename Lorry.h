#ifndef LORRY_H_
#define LORRY_H_
#include "Vehicle.h"

class Lorry : private Vehicle {
public:
private:
	int capacity;
	engineType engine;
	bool liquidSubstance;
};
#endif
