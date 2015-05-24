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
	s = "Choose type of vehicle\n(1) Motorcycle\n(2) Car\n(3) Lorry\n";
	labels.push_back(s);
	s = "ID:\n";
	labels.push_back(s);
	s = "Engine size:\n";
	labels.push_back(s);
	s = "Number of gears:\n";
	labels.push_back(s);
	s = "Power of vehicle:\n";
	labels.push_back(s);
	s = "Body type:\n(1) classic\n(2) chopper\n(3) cruiser\n(4) quad\n";
	labels.push_back(s);
	s = "Has digital speedo? (T/N):\n";
	labels.push_back(s);
	s = "Boot size:\n";
	labels.push_back(s);
	s = "Number of places:\n";
	labels.push_back(s);
	s = "Engine type:\n(1) diesel\n(2) petrol\n(3) hybrid\n(4) electric\n";
	labels.push_back(s);
	s = "Capacity:\n";
	labels.push_back(s);
	s = "Can transport liquids? (T/N):\n";
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

bool ConsoleInterface::VehicleAddition(VehicleCollection *vc){
	std::cout << labels[8];
	int nm;
	std::cin >> nm;
	if (std::cin.fail()){ ClearBuf(); return false; }

	std::string id;
	unsigned int sizeOfEngine;
	unsigned int numberOfGears;
	unsigned int powerOfVehicle;

	std::cout << labels[9];
	std::cin >> sizeOfEngine;
	if (std::cin.fail()){ ClearBuf(); return false; }
	std::cout << labels[10];
	std::cin >> numberOfGears;
	if (std::cin.fail()){ ClearBuf(); return false; }
	std::cout << labels[11];
	std::cin >> powerOfVehicle;
	if (std::cin.fail()){ ClearBuf(); return false; }

	switch (nm){
	case 1:
		bodyType typeOfBody;
		unsigned int tempBody;
		char tempDigitalSpeedo;
		bool digitalSpeedo;
		std::cout << labels[12];
		std::cin >> tempBody;
		if (std::cin.fail() || tempBody < 1 || tempBody > 4){ ClearBuf(); return false; }
		typeOfBody = static_cast<bodyType>(--tempBody);
		std::cout << labels[13];
		std::cin >> tempDigitalSpeedo;
		if (std::cin.fail()){ ClearBuf(); return false; }
		if (tempDigitalSpeedo == 'T')
			digitalSpeedo = true;
		else if (tempDigitalSpeedo == 'N')
			digitalSpeedo = false;
		else
			return false;
		vc->AddVehicle(motorcycle, id, sizeOfEngine, numberOfGears, powerOfVehicle, typeOfBody, digitalSpeedo, 0, 0, petrol, 0, false);
		break;
	case 2:
		unsigned int bootSize;
		unsigned int nPlaces;
		engineType engine;
		unsigned int tempEngine;
		std::cout << labels[14];
		std::cin >> bootSize;
		if (std::cin.fail()){ ClearBuf(); return false; }
		std::cout << labels[15];
		std::cin >> nPlaces;
		if (std::cin.fail()){ ClearBuf(); return false; }
		std::cout << labels[16];
		std::cin >> tempEngine;
		if (std::cin.fail() || tempBody < 1 || tempBody > 4){ ClearBuf(); return false; }
		engine = static_cast<engineType>(--tempEngine);
		vc->AddVehicle(car, id, sizeOfEngine, numberOfGears, powerOfVehicle, classic, false, bootSize, nPlaces, engine, 0, 0);
		break;
	case 3:
		unsigned capacity;
		bool liquidSubstance;
		char tempLiquidSubstance;
		std::cout << labels[17];
		std::cin >> capacity;
		if (std::cin.fail()){ ClearBuf(); return false; }
		std::cout << labels[18];
		std::cin >> tempLiquidSubstance;
		if (std::cin.fail()){ ClearBuf(); return false; }
		if (tempDigitalSpeedo == 'T')
			liquidSubstance = true;
		else if (tempDigitalSpeedo == 'N')
			liquidSubstance = false;
		else
			return false;
		vc->AddVehicle(lorry, id, sizeOfEngine, numberOfGears, powerOfVehicle, classic, false, 0, 0, diesel, capacity, liquidSubstance);
		break;
	}
	return true;
}

void ConsoleInterface::ClearBuf() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
}