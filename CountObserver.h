#ifndef COUNT_OBSERVER_H_
#define COUNT_OBSERVER_H_
#include "Observer.h"

class CountObserver : public Observer
{
public:
	CountObserver(int);
	virtual ~CountObserver();
	bool IsRentingPossible() const;
	void Update(Vehicle *);
protected:
	int counter;
	const int maxCounter;
};

#endif
