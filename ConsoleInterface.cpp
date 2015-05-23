#include "ConsoleInterface.h"

ConsoleInterface::ConsoleInterface() {
	std::string s;
	s = "\nGarage Management\n";
	labels.push_back(s);
	s = "(1) Show data base\n";
	labels.push_back(s);
	s = "(2) Add vehicle\n";
	labels.push_back(s);
	s = "(3) Remove vehicle\n";
	labels.push_back(s);
	s = "(4) Rent vehicle\n";
	labels.push_back(s);
	s = "(5) Restore vehicle\n";
	labels.push_back(s);
	s = "(6) Load data\n";
	labels.push_back(s);
	s = "(7) Save data\n";
	labels.push_back(s);
	s = "Choose action:\n";
	labels.push_back(s);
}

void ConsoleInterface::MainMenu(VehicleCollection *vc) {
	while(true) {
		for (int i = 0; i < 8; i++)
			std::cout << labels[i];
		int nm;
		std::cin >> nm;
		if (std::cin.fail() || nm < 1 || nm > 7){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
			continue;
		}
		switch (nm){
			case 1:
				ShowData(vc);
			   break;
			case 2:
				VehicleAddition(vc);
				break;
			case 3:
				VehicleRemoval(vc);
				break;
			case 4:
				VehicleRental(vc);
				break;
			case 5:
				VehicleRestoration(vc);
				break;
			case 6:
				LoadingData(vc);
				break;
			case 7:
				SavingData(vc);
				break;
		}
	}
}

void ConsoleInterface::ShowData(VehicleCollection *vc) {
	std::list<Vehicle*>::iterator it;
	for (it = vc->vehicles.begin(); it != vc->vehicles.end(); it++) {
		std::cout << "(" << (*it)->GetIndex() << ")   ";
		std::cout << (*it)->GetId() << "  ";
		if ((*it)->GetType() == 0)
			std::cout << "Motorcycle  ";
		if ((*it)->GetType() == 1)
			std::cout << "Car  ";
		if ((*it)->GetType() == 2)
			std::cout << "Lorry  ";
		if ((*it)->Accesible())
			std::cout << "E";
		else
			std::cout << "D";
		std::cout << std::endl;
	}
}