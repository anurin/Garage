#ifndef CAR_H_
#define CAR_H_
#include "Vehicle.h"

class Car : public Vehicle {
public:
	Car();
	Car(unsigned int sizeOfEngine, unsigned int numberOfGears, unsigned int powerOfVehicle, unsigned int sizeOfBoot, unsigned int numberOfPlaces, engineType typeOfEngine);
	
	unsigned int GetBootSize() const;
	unsigned GetNPlaces() const;
	engineType GetEngine() const;

	void SetBootSize(unsigned int);
	void SetNPlaces(unsigned);
	void SetEngine(engineType);
private:
	unsigned bootSize;
	unsigned nPlaces;
	engineType engine;
};
#endif
