#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <list>
#include "RentObserver.h"
#include "CounterObserver.h"

class Vehicle {
public:
	Vehicle();
	Vehicle(unsigned int, unsigned int, unsigned int);

	void AddObserver(Observer *);
	void DelObserver(Observer *);
	void NotifyObservers();

	void Rental();
	void Restoration();

	bool Enable() const;
	unsigned long long int GetIndex() const;
	unsigned int GetEngineSize() const;	
	unsigned int GetNGears() const;
	unsigned int GetPower() const;

	void SetEngineSize(unsigned int);
	void SetNGears(unsigned int);
	void SetPower(unsigned int);
protected:
	unsigned long long index;
	bool enable;
	unsigned int engineSize;
	unsigned int nGears;
	unsigned int power;

	static unsigned long long counter;
	std::list<Observer*> observers;
};

enum engineType {diesel, lead, hybrid, electric};

#endif //VEHICLE_H_