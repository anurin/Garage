#ifndef COUNTER_OBSERVER_H_
#define COUNTER_OBSERVER_H_
#include "Observer.h"

class CounterObserver : Observer {
public:
	virtual void Update();
};

#endif