#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_
#include "Vehicle.h"

class Motorcycle : private Vehicle {
public:
private:
	bodyType type;
	bool digitalSpeedometer;
};

enum bodyType {classic, chopper, cruiser, quad};
#endif
