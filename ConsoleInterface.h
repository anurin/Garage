#include <iostream>
#include <string>
#include <vector>

class ConsoleInterface{
public:
	//ConsoleInterface();

	void ShowMainMenu();
	void VehicleAddition();
	void VehicleRemoval();
protected:
	std::vector<std::string> labels;
};