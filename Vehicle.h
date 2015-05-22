#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <list>
#include <iostream>
#include <string>

enum engineType:unsigned  { diesel, petrol, hybrid, electric };
enum bodyType:unsigned  { classic, chopper, cruiser, quad };
enum vehicleType:unsigned { motorcycle, car, lorry };

class Vehicle {
public:
	Vehicle(vehicleType);
	Vehicle(vehicleType,
		unsigned long long,
		std::string,
		unsigned int,
		unsigned int,
		unsigned int);

	void Rental();
	void Restoration();

	vehicleType GetType();
	bool Accesible() const;
	unsigned long long int GetIndex() const;
	std::string GetId() const;
	unsigned int GetEngineSize() const;	
	unsigned int GetNGears() const;
	unsigned int GetPower() const;

	void SetEngineSize(unsigned int);
	void SetNGears(unsigned int);
	void SetPower(unsigned int);

	virtual void SaveVehicle(std::ostream&) = 0;
	virtual void LoadVehicle(std::istream&) = 0;

protected:
	vehicleType vType;
	unsigned long long index;
	std::string id;
	bool accesible;
	unsigned int engineSize;
	unsigned int nGears;
	unsigned int power;
	
};

#endif //VEHICLE_H_