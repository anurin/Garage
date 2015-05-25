#include "VehiclesCollection.h"

VehicleCollection::VehicleCollection()
:
counter(0){}

void VehicleCollection::AddObserver(Observer *obs) {
	observers.push_back(obs);
}

void VehicleCollection::RmObserver(Observer *obs) {
	observers.remove(obs);
}

void VehicleCollection::Notify(Vehicle *v){
	std::list<Observer*>::iterator it;
	for (it = observers.begin(); it != observers.end(); it++)
		(*it)->Update(v);
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

void VehicleCollection::RmVehicle(unsigned long long a) throw(std::string){
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++) {
		if ((*it)->GetIndex() == a){
			delete (*it);
			vehicles.remove(*it);
			break;
		}
	}
	std::string s = "There is no such index.\n";
	throw s;
}

bool VehicleCollection::Rental(unsigned long long a) throw(std::string){
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++) {
		if ((*it)->GetIndex() == a && (*it)->Accesible()){
			(*it)->RentVehicle();
			Notify(*it);
			return true;
		}
	}
	std::string s = "There is no such index or the vehicle has been already rented.\n";
	throw s;
	return false;
}

bool VehicleCollection::Restoration(unsigned long long a) throw(std::string){
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++){
		if ((*it)->GetIndex() == a && !(*it)->Accesible()){
			(*it)->RestoreVehicle();
			Notify(*it);
			return true;
		}
	}
	std::string s = "There is no such index or the vehicle has been already restored.\n";
	throw s;
	return false;
}

//do zmiany
void VehicleCollection::AllVehicles() {
	std::list<Vehicle*>::iterator it;
	std::cout << "ID" << "TYP" << "wszystko inne" << std::endl;
	for (it = vehicles.begin(); it != vehicles.end(); it++)
		std::cout << (*it)->GetType() << " " <<  (*it)->GetPower() << std::endl;
}

void VehicleCollection::SaveData(std::ostream& saving) {
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++)
		(*it)->SaveVehicle(saving);
}

void VehicleCollection::LoadData(std::istream& loading) {
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++)
		delete (*it);
	vehicles.clear();

	vehicleType vT;
	while (loading.read(reinterpret_cast<char *>(&vT), sizeof(unsigned int))){
		if (vT == motorcycle) {
			Motorcycle *newM = new Motorcycle;
			newM->LoadVehicle(loading);
			vehicles.push_back(newM);
			if (newM->GetIndex() > counter)
				counter = newM->GetIndex() + 1;
		}
		if (vT == car) {
			Car *newC = new Car;
			newC->LoadVehicle(loading);
			vehicles.push_back(newC);
			if (newC->GetIndex() > counter)
				counter = newC->GetIndex() + 1;
		}
		if (vT == lorry) {
			Lorry *newL = new Lorry;
			newL->LoadVehicle(loading);
			vehicles.push_back(newL);
			if (newL->GetIndex() > counter)
				counter = newL->GetIndex() + 1;
		}
	}
}