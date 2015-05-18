#include "Vehicle.h"

int Vehicle::counter = 0;

Vehicle::Vehicle()
:
index(++counter),
engineSize(0),
bootSize(0),
nGears(0),
power(0)
{}

Vehicle::Vehicle(int sizeOfEngine = 0, int sizeOfBoot = 0, int numberOfGears = 0, int powerOfVehicle = 0)
:
index(++counter),
engineSize(sizeOfEngine),
bootSize(sizeOfBoot),
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

int Vehicle::GetIndex() const {
	return index;
}

int Vehicle::GetEngineSize() const {
	return engineSize;
}

int Vehicle::GetBootSize() const {
	return bootSize;
}

int Vehicle::GetNGears() const {
	return nGears;
}

int Vehicle::GetPower() const {
	return power;
}