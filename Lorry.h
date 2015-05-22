#ifndef LORRY_H_
#define LORRY_H_
#include "Vehicle.h"

class Lorry : public Vehicle {
public:
	Lorry();
	Lorry(unsigned long long nIndex,
		std::string newId,
		unsigned int sizeOfEngine, 
		unsigned int numberOfGears, 
		unsigned int powerOfVehicle, 
		unsigned int capacityOfLorry, 
		bool canTransportLiquid);

	void SaveVehicle(std::ostream&);
	void LoadVehicle(std::istream&);

	unsigned GetCapacity() const;
	bool CanTransportLiquids() const;

	void SetCapacity(unsigned);
	void SetLiquidSubstance(bool);
private:
	unsigned int capacity;
	bool liquidSubstance;
};
#endif
