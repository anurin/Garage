#include "Vehicle.h"

unsigned long long Vehicle::counter = 0;

Vehicle::Vehicle()
:
index(++counter),
enable(true),
engineSize(0),
nGears(0),
power(0)
{}

Vehicle::Vehicle(unsigned int sizeOfEngine = 0, unsigned int numberOfGears = 0, unsigned int powerOfVehicle = 0)
:
index(++counter),
enable(true),
engineSize(sizeOfEngine),
nGears(numberOfGears),
power(powerOfVehicle)
{}

void Vehicle::AddObserver(Observer *obs) {
	observers.push_back(obs);
}

void Vehicle::DelObserver(Observer *obs) {
	observers.remove(obs);
}

void Vehicle::NotifyObservers(){
	std::list<Observer*>::iterator it;
	for (it = observers.begin(); it != observers.end(); it++){
		(*it)->Update();
	}
}

bool Vehicle::Enable() const {
	return enable;
}

unsigned long long int Vehicle::GetIndex() const {
	return index;
}

unsigned int Vehicle::GetEngineSize() const {
	return engineSize;
}

unsigned int Vehicle::GetNGears() const {
	return nGears;
}

unsigned int Vehicle::GetPower() const {
	return power;
}

void Vehicle::SetEngineSize(unsigned int a) {
	engineSize = a;
}


void Vehicle::SetNGears(unsigned int a) {
	nGears = a;
}

void Vehicle::SetPower(unsigned int a) {
	power = a;
}