#include "VehiclesCollection.h"

VehiclesCollection::VehiclesCollection()
:
counter(0){}

VehiclesCollection::~VehiclesCollection() {
	std::list<Vehicle *>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++)
		delete (*it);
}

void VehiclesCollection::AddObserver(Observer *obs) {
	observers.push_back(obs);
}

void VehiclesCollection::RmObserver(Observer *obs) {
	observers.remove(obs);
}

void VehiclesCollection::Notify(Vehicle *v){
	std::list<Observer*>::iterator it;
	for (it = observers.begin(); it != observers.end(); it++)
		(*it)->Update(v);
}

void VehiclesCollection::AddVehicle(vehicleType typeOfVehicle,
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

bool VehiclesCollection::RmVehicle(unsigned long long a) throw(std::string){
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++) {
		if ((*it)->GetIndex() == a){
			delete (*it);
			vehicles.remove(*it);
			std::cout << "The vehicle has been removed.\n";
			return true;
		}
	}
	std::string s = "There is no such index.\n";
	throw s;
	return false;
}

bool VehiclesCollection::Rental(unsigned long long a) throw(std::string){
	RentObserver* temp = static_cast<RentObserver *>(observers.front());
	if (!temp->IsRentingPossible()){
		std::string s = "Limit has been reached.\n";
		throw s;
		return false;
	}
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++) {
		if ((*it)->GetIndex() == a && (*it)->Accesible()){
			(*it)->RentVehicle();
			Notify(*it);
			std::cout << "The vehicle has been rented.\n";
			return true;
		}
	}
	std::string s = "There is no such index or the vehicle has been already rented.\n";
	throw s;
	return false;
}

bool VehiclesCollection::Restoration(unsigned long long a) throw(std::string){
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++){
		if ((*it)->GetIndex() == a && !(*it)->Accesible()){
			(*it)->RestoreVehicle();
			Notify(*it);
			std::cout << "The vehicle has been restored.\n";
			return true;
		}
	}
	std::string s = "There is no such index or the vehicle has been already restored.\n";
	throw s;
	return false;
}

void VehiclesCollection::SaveData(std::ostream& saving) {
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++)
		(*it)->SaveVehicle(saving);
}

void VehiclesCollection::LoadData(std::istream& loading) {
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