#include <iostream>
#include "VehicleCollection.h"
#include "Motorcycle.h"
#include "Car.h"
#include "Lorry.h"

VehicleCollection::VehicleCollection()
:
counter(0){}

void VehicleCollection::AddObserver(Observer *obs) {
	observers.push_back(obs);
}

void VehicleCollection::RmObserver(Observer *obs) {
	observers.remove(obs);
}

void VehicleCollection::Notify(unsigned long long a){
	std::list<Observer*>::iterator it;
	for (it = observers.begin(); it != observers.end(); it++)
		(*it)->Update(a);
}

void VehicleCollection::AddVehicle(vehicleType typeOfVehicle,
							std::string newId,
							unsigned int sizeOfEngine,
							unsigned int numberOfGears,
							unsigned int powerOfVehicle,
							bodyType typeOfBody,
							bool digitalsSpeedo,
							unsigned int sizeOfBoot,
							unsigned int numberOfPlaces,
							engineType typeOfEngine,
							unsigned int capacityOfLorry,
							bool canTransportLiquid){
	Vehicle* v;
	if (typeOfVehicle == motorcycle)
		v = new Motorcycle(++counter, newId, sizeOfEngine, numberOfGears, powerOfVehicle, 
						typeOfBody, digitalsSpeedo);
	if (typeOfVehicle == car)
		v = new Car(++counter, newId, sizeOfEngine, numberOfGears, powerOfVehicle,
						sizeOfBoot, numberOfPlaces, typeOfEngine);
	if (typeOfVehicle == lorry)
		v = new Lorry(++counter, newId, sizeOfEngine, numberOfGears, powerOfVehicle,
						capacityOfLorry, canTransportLiquid);
	vehicles.push_back(v);
}

void VehicleCollection::RmVehicle(unsigned long long a) {
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++) {
		if ((*it)->GetIndex() == a){
			delete (*it);
			vehicles.remove(*it);
			break;
		}
	}
}

void VehicleCollection::ShowAllVehicles() {
	std::list<Vehicle*>::iterator it;
	std::cout << "ID" << "TYP" << "wszystko inne" << std::endl;
	for (it = vehicles.begin(); it != vehicles.end(); it++)
		std::cout << (*it)->GetType() << " " <<  (*it)->GetPower() << std::endl;
}

void VehicleCollection::SaveData() {
	std::ofstream saving("data.bin", std::ios::binary);
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++)
		(*it)->SaveVehicle(saving);
	saving.close();
}

void VehicleCollection::LoadData() {
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++)
		delete (*it);
	vehicles.clear();
	std::ifstream loading("data.bin", std::ios::binary);
	vehicleType vT;
	while (loading.read(reinterpret_cast<char *>(&vT), sizeof(unsigned int))){
		if (vT == motorcycle) {
			Motorcycle *newM = new Motorcycle;
			newM->LoadVehicle(loading);
			vehicles.push_back(newM);
		}
		if (vT == car) {
			Car *newC = new Car;
			newC->LoadVehicle(loading);
			vehicles.push_back(newC);
		}
		if (vT == lorry) {
			Lorry *newL = new Lorry;
			newL->LoadVehicle(loading);
			vehicles.push_back(newL);
		}
	}
	loading.close();
}