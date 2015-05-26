#include "Motorcycle.h"

Motorcycle::Motorcycle()
:Vehicle(motorcycle)
{}

Motorcycle::Motorcycle(unsigned long long nIndex,
	std::string newId,
	unsigned int sizeOfEngine,
	unsigned int numberOfGears,
	unsigned int powerOfVehicle,
	bodyType typeOfBody,
	bool digitalsSpeedo)
:
Vehicle(motorcycle, nIndex, newId, sizeOfEngine, numberOfGears, powerOfVehicle),
body(typeOfBody),
digitalSpeedometer(digitalsSpeedo)
{}

void Motorcycle::SaveVehicle(std::ostream &dataFile){
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
	dataFile.write(reinterpret_cast<const char *>(&body), sizeof(unsigned));
	dataFile.write(reinterpret_cast<const char *>(&digitalSpeedometer), sizeof(bool));
}

void Motorcycle::LoadVehicle(std::istream &dataFile){
	char temp[9];
	dataFile.read(reinterpret_cast<char *>(&temp), sizeof(temp));
	dataFile.read(reinterpret_cast<char *>(&index), sizeof(unsigned long long));
	dataFile.read(reinterpret_cast<char *>(&accesible), sizeof(bool));
	dataFile.read(reinterpret_cast<char *>(&engineSize), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&nGears), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&power), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&body), sizeof(unsigned));
	dataFile.read(reinterpret_cast<char *>(&digitalSpeedometer), sizeof(bool));
	std::stringstream ss;
	ss << temp;
	ss >> id;
}

bodyType Motorcycle::GetBody() const {
	return body;
}

bool Motorcycle::IsDigitalSpeedo() const {
	return digitalSpeedometer;
}

void Motorcycle::SetBody(bodyType a){
	body = a;
}

void Motorcycle::SetDigitalSpeedo(bool a){
	digitalSpeedometer = a;
}