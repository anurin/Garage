#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <list>
#include "Observer.h"
#include "RentObserver.h"

class Vehicle {
public:
	Vehicle();
	Vehicle(int, int, int, int);

	void AddObserver(Observer *);
	void DelObserver(Observer *);
	void NotifyObservers();

	void Rental();
	void Restoration();

	bool Enable() const;
	int GetIndex() const;
	int GetEngineSize() const;
	int GetBootSize() const;
	int GetNGears() const;
	int GetPower() const;
protected:
	int index;
	bool enable;
	int engineSize;
	int bootSize;
	int nGears;
	int power;

	static int counter;
	std::list<Observer*> observers;
};

enum engineType {diesel, lead, hybrid, electric};

#endif //VEHICLE_H_