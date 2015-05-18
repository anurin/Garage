#ifndef RENT_OBSERVER_H_
#define RENT_OBSERVER_H_
#include "Observer.h"

class RentObserver : Observer{
public:
	virtual void Update();
protected:
	unsigned nRental;
};

#endif