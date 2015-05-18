#include "Motorcycle.h"

Motorcycle::Motorcycle()
:
Vehicle(),
body(classic),
digitalSpeedometer(false)
{}

Motorcycle::Motorcycle(unsigned int sizeOfEngine = 0, unsigned int numberOfGears = 0, unsigned int powerOfVehicle = 0, bodyType typeOfBody = classic, bool digitalsSpeedo = false)
:
Vehicle(sizeOfEngine, numberOfGears, powerOfVehicle),
body(typeOfBody),
digitalSpeedometer(digitalsSpeedo)
{}

bodyType Motorcycle::GetBody() const {
	return body;
}

bool Motorcycle::IsDigitalSpeedo() const {
	return digitalSpeedometer;
}

void Motorcycle::SetBody(bodyType a){
	body = a;
}

void Motorcycle::SetDigitalSpeedo(bool a){
	digitalSpeedometer = a;
}