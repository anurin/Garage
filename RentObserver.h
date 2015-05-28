#ifndef RENT_OBSERVER_H_
#define RENT_OBSERVER_H_
#include "Observer.h"
#include <ostream>
#include <istream>

class RentObserver : public Observer {
public:
	RentObserver(std::ostream&);
	virtual ~RentObserver();
	void Update(Vehicle *);
protected:
	std::ostream& savingStream;
};

#endif
