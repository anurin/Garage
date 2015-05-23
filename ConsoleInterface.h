#include <iostream>
#include <string>
#include <vector>
#include "VehiclesCollection.h"

class ConsoleInterface{
public:
	ConsoleInterface();

	void MainMenu(VehicleCollection *);
	void ShowData(VehicleCollection *);
	void VehicleAddition(VehicleCollection *);
	void VehicleRemoval(VehicleCollection *);
	void VehicleRental(VehicleCollection *);
	void VehicleRestoration(VehicleCollection *);
	void LoadingData(VehicleCollection *);
	void SavingData(VehicleCollection *);
protected:
	std::vector<std::string> labels;
};