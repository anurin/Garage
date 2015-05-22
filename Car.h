#ifndef CAR_H_
#define CAR_H_
#include "Vehicle.h"

class Car : public Vehicle {
public:
	Car();
	Car(unsigned long long nIndex,
		std::string newId,
		unsigned int sizeOfEngine,
		unsigned int numberOfGears,
		unsigned int powerOfVehicle,
		unsigned int sizeOfBoot,
		unsigned int numberOfPlaces,
		engineType typeOfEngine);
	
	void SaveVehicle(std::ostream&);
	void LoadVehicle(std::istream&);

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
