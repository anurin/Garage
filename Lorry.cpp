#include "Lorry.h"

Lorry::Lorry()
:Vehicle(lorry)
{}

Lorry::Lorry(unsigned long long nIndex,
	std::string newId,
	unsigned int sizeOfEngine, 
	unsigned int numberOfGears, 
	unsigned int powerOfVehicle, 
	unsigned int capacityOfLorry, 
	bool canTransportLiquid)
:
Vehicle(lorry, nIndex, newId, sizeOfEngine, numberOfGears, powerOfVehicle),
capacity(capacityOfLorry),
liquidSubstance(canTransportLiquid)
{}

void Lorry::SaveVehicle(std::ostream &dataFile){
	char temp[9] = "";
	std::stringstream ss;
	ss << id;
	ss >> temp;
	dataFile.write(reinterpret_cast<const char *>(&vType), sizeof(unsigned int));
	dataFile.write(reinterpret_cast<const char *>(&temp), sizeof(temp));
	dataFile.write(reinterpret_cast<const char *>(&index), sizeof(unsigned long long));
	dataFile.write(reinterpret_cast<const char *>(&accesible), sizeof(bool));
	dataFile.write(reinterpret_cast<const char *>(&engineSize), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&nGears), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&power), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&capacity), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&liquidSubstance), sizeof(bool));
}

void Lorry::LoadVehicle(std::istream &dataFile){
	char temp[9];
	dataFile.read(reinterpret_cast<char *>(&temp), sizeof(temp));
	dataFile.read(reinterpret_cast<char *>(&index), sizeof(unsigned long long));
	dataFile.read(reinterpret_cast<char *>(&accesible), sizeof(bool));
	dataFile.read(reinterpret_cast<char *>(&engineSize), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&nGears), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&power), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&capacity), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&liquidSubstance), sizeof(bool));
	std::stringstream ss;
	ss << temp;
	ss >> id;
}

unsigned Lorry::GetCapacity() const {
	return capacity;
}

bool Lorry::CanTransportLiquids() const {
	return liquidSubstance;
}

void Lorry::SetCapacity(unsigned a) {
	capacity = a;
}

void Lorry::SetLiquidSubstance(bool a) {
	liquidSubstance = a;
}