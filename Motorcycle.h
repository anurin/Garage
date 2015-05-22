#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_
#include "Vehicle.h"

class Motorcycle : public Vehicle {
public:
	Motorcycle();
	Motorcycle(unsigned long long nIndex,
		std::string newId,
		unsigned int sizeOfEngine,
		unsigned int numberOfGears, 
		unsigned int powerOfVehicle, 
		bodyType typeOfBody, 
		bool digitalsSpeedo);

	void SaveVehicle(std::ostream&);
	void LoadVehicle(std::istream&);

	bodyType GetBody() const;
	bool IsDigitalSpeedo() const;

	void SetBody(bodyType);
	void SetDigitalSpeedo(bool);

protected:
	bodyType body;
	bool digitalSpeedometer;
};

#endif
