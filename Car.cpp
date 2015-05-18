#include "Car.h"

Car::Car()
:
Vehicle(),
nPlaces(5),
engine(lead)
{}

Car::Car(unsigned int sizeOfEngine = 0, unsigned int numberOfGears = 0, unsigned int powerOfVehicle = 0, unsigned int sizeOfBoot = 0, unsigned int numberOfPlaces = 5, engineType typeOfEngine = lead)
:
Vehicle(sizeOfEngine, numberOfGears, powerOfVehicle),
bootSize(sizeOfBoot),
nPlaces(numberOfPlaces),
engine(typeOfEngine)
{}

unsigned int Car::GetBootSize() const {
	return bootSize;
}

unsigned Car::GetNPlaces() const {
	return nPlaces;
}

engineType Car::GetEngine() const {
	return engine;
}

void Car::SetBootSize(unsigned int a) {
	bootSize = a;
}

void Car::SetNPlaces(unsigned a) {
	nPlaces = a;
}

void Car::SetEngine(engineType a) {
	engine = a;
}