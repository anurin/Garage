#include "Lorry.h"

Lorry::Lorry()
:
Vehicle(),
capacity(0),
liquidSubstance(false)
{}

Lorry::Lorry(unsigned int sizeOfEngine = 0, unsigned int numberOfGears = 0, unsigned int powerOfVehicle = 0, unsigned int capacityOfLorry = 0, bool canTransportLiquid = false)
:
Vehicle(sizeOfEngine, numberOfGears, powerOfVehicle),
capacity(capacityOfLorry),
liquidSubstance(canTransportLiquid)
{}

unsigned Lorry::GetCapacity() const {
	return capacity;
}

bool Lorry::CanTransportLiquids() const {
	return liquidSubstance;
}

void Lorry::SetCapacity(unsigned a) {
	capacity = a;
}

void Lorry::SetLiquidSubstance(bool a) {
	liquidSubstance = a;
}