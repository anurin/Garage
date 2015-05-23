#include "Vehicle.h"

Vehicle::Vehicle(vehicleType v)
:vType(v)
{}

Vehicle::Vehicle(vehicleType v, unsigned long long nIndex, std::string newId, unsigned int sizeOfEngine = 0, unsigned int numberOfGears = 0, unsigned int powerOfVehicle = 0)
	:
	index(nIndex),
	vType(v),
	id(newId),
	accesible(true),
	engineSize(sizeOfEngine),
	nGears(numberOfGears),
	power(powerOfVehicle)
{}

void Vehicle::RentVehicle() {
	accesible = false;
}

void Vehicle::RestoreVehicle() {
	accesible = true;
}

vehicleType Vehicle::GetType() {
	return vType;
}

bool Vehicle::Accesible() const {
	return accesible;
}

unsigned long long int Vehicle::GetIndex() const {
	return index;
}

std::string Vehicle::GetId() const {
	return id;
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
