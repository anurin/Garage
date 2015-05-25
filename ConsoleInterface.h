#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "VehiclesCollection.h"

class ConsoleInterface{
public:
	ConsoleInterface();

	void MainMenu(VehicleCollection *);
	void ShowData(VehicleCollection *);
	bool VehicleAddition(VehicleCollection *);
	bool VehicleRemoval(VehicleCollection *);
	bool VehicleRental(VehicleCollection *);
	bool VehicleRestoration(VehicleCollection *);
	bool LoadingData(VehicleCollection *);
	bool SavingData(VehicleCollection *);
	void ClearBuf();
protected:
	std::vector<std::string> labels;
};