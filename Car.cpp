#include "Car.h"

Car::Car()
:Vehicle(car)
{}

Car::Car(unsigned long long nIndex,
	std::string newId,
	unsigned int sizeOfEngine,
	unsigned int numberOfGears, 
	unsigned int powerOfVehicle, 
	unsigned int sizeOfBoot, 
	unsigned int numberOfPlaces, 
	engineType typeOfEngine)
:
Vehicle(car, nIndex, newId, sizeOfEngine, numberOfGears, powerOfVehicle),
bootSize(sizeOfBoot),
nPlaces(numberOfPlaces),
engine(typeOfEngine)
{}

void Car::SaveVehicle(std::ostream &dataFile){
	dataFile.write(reinterpret_cast<const char *>(&vType), sizeof(unsigned int));
	dataFile.write(reinterpret_cast<const char *>(&index), sizeof(unsigned long long));
	dataFile.write(reinterpret_cast<const char *>(&accesible), sizeof(bool));
	dataFile.write(reinterpret_cast<const char *>(&engineSize), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&nGears), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&power), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&bootSize), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&nPlaces), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&engine), sizeof(unsigned));
}

void Car::LoadVehicle(std::istream &dataFile){
	dataFile.read(reinterpret_cast<char *>(&index), sizeof(unsigned long long));
	dataFile.read(reinterpret_cast<char *>(&accesible), sizeof(bool));
	dataFile.read(reinterpret_cast<char *>(&engineSize), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&nGears), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&power), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&bootSize), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&nPlaces), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&engine), sizeof(unsigned));
}

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