#include "CountObserver.h"

CountObserver::CountObserver(int a)
: counter(0), maxCounter(a)
{}

CountObserver::~CountObserver(){};

void CountObserver::Update(Vehicle *){
	counter++;
	}

bool CountObserver::IsRentingPossible() const{
	if(counter == maxCounter)
		return false;
	else
		return true;
}
