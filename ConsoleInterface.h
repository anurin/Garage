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

	bool MainMenu(VehiclesCollection *);
	void ShowData(VehiclesCollection *);
	bool VehicleAddition(VehiclesCollection *);
	bool VehicleRemoval(VehiclesCollection *);
	bool VehicleRental(VehiclesCollection *);
	bool VehicleRestoration(VehiclesCollection *);
	bool LoadingData(VehiclesCollection *);
	bool SavingData(VehiclesCollection *);
	void ClearBuf();
protected:
	std::vector<std::string> labels;
};