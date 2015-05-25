#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#include "VehiclesCollection.h"


class ConsoleInterface{
public:
	ConsoleInterface();

	bool MainMenu(VehicleCollection *);
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