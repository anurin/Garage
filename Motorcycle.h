#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_
#include "Vehicle.h"

enum bodyType { classic, chopper, cruiser, quad };

class Motorcycle : public Vehicle {
public:
	Motorcycle();
	Motorcycle(unsigned int sizeOfEngine, unsigned int numberOfGears, unsigned int powerOfVehicle, bodyType typeOfBody, bool digitalsSpeedo);

	bodyType GetBody() const;
	bool IsDigitalSpeedo() const;

	void SetBody(bodyType);
	void SetDigitalSpeedo(bool);

protected:
	bodyType body;
	bool digitalSpeedometer;
};

#endif
