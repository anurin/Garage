#ifndef VEHICLE_COLLECTION_H_
#define VEHICLE_COLLECTION_H_
#include <list>
#include <fstream>
#include "Vehicle.h"



class VehicleCollection {
public:
	VehicleCollection();

	void AddObserver(Observer*);
	void RmObserver(Observer*);
	void Notify(unsigned long long);

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
	void SaveData();
	void LoadData();
	unsigned long long GetCounter();

protected:
	unsigned long long counter;
	std::list<Vehicle*> vehicles;
	std::list<Observer*> observers;
};

#endif