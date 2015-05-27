#ifndef VEHICLE_COLLECTION_H_
#define VEHICLE_COLLECTION_H_
#include <list>
#include <iostream>
#include "Vehicle.h"
#include "Observer.h"
#include "RentObserver.h"
#include "Motorcycle.h"
#include "Car.h"
#include "Lorry.h"

class VehiclesCollection {
	friend class ConsoleInterface;
public:
	VehiclesCollection();
	~VehiclesCollection();

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
	bool RmVehicle(unsigned long long) throw(std::string);
	bool Rental(unsigned long long) throw(std::string);
	bool Restoration(unsigned long long) throw(std::string);
	void AllVehicles();
	void SaveData(std::ostream&);
	void LoadData(std::istream&);
	unsigned long long GetCounter();

protected:
	unsigned long long counter;
	std::list<Vehicle*> vehicles;
	std::list<Observer*> observers;
};

#endif
