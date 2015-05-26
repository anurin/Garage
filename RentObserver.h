#ifndef RENT_OBSERVER_H_
#define RENT_OBSERVER_H_
#include "Observer.h"
#include <ostream>
#include <istream>

class RentObserver : public Observer {
public:
	RentObserver(int, std::ostream&);
	virtual ~RentObserver();
	bool IsRentingPossible() const;
	void Update(Vehicle *);
protected:
	int counter;
	const int maxCounter;
	std::ostream& savingStream;
};

#endif