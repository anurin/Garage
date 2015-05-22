#ifndef OBSERVER_H_
#define OBSERVER_H_
#include "Vehicle.h"

class Observer {
public:
	virtual void Update(Vehicle *) = 0;
};

#endif