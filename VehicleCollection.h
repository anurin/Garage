#ifndef VEHICLE_COLLECTION_H_
#define VEHICLE_COLLECTION_H_
#include <list>
#include <iostream>
#include "Vehicle.h"
#include "Observer.h"
#include "Motorcycle.h"
#include "Car.h"
#include "Lorry.h"

class VehicleCollection {
public:
	VehicleCollection();

	void AddObserver(Observer*);
	void RmObserver(Observer*);
	void Notify(Vehicle *);

	void AddVehicle(vehicleType typeOfVehicle,
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
				bool canTransportLiquid);
	void RmVehicle(unsigned long long);
	void ShowAllVehicles();
	void SaveData(std::ostream&);
	void LoadData(std::istream&);
	unsigned long long GetCounter();

protected:
	unsigned long long counter;
	std::list<Vehicle*> vehicles;
	std::list<Observer*> observers;
};

#endif