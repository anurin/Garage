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
	s = "Has digital speedo? (y/n):\n";
	labels.push_back(s);
	s = "Boot size:\n";
	labels.push_back(s);
	s = "Number of places:\n";
	labels.push_back(s);
	s = "Engine type:\n(1) diesel\n(2) petrol\n(3) hybrid\n(4) electric\n";
	labels.push_back(s);
	s = "Capacity:\n";
	labels.push_back(s);
	s = "Can transport liquids? (y/n):\n";
	labels.push_back(s);
	s = "Choose the position to remove:\n";
	labels.push_back(s);
	s = "Entered data is incorrect.\n";
	labels.push_back(s);
	s = "The position has been removed.\n";
	labels.push_back(s);
	s = "Choose the position to rent:\n";
	labels.push_back(s);
	s = "The vehicle has been rented.\n";
	labels.push_back(s);
	s = "Choose the position to restore:\n";
	labels.push_back(s);
	s = "The vehicle has been restored.n";
	labels.push_back(s);
	s = "Type file name to load data:\n";
	labels.push_back(s);
	s = "Data has been loaded.\n";
	labels.push_back(s);
	s = "Type file name to save data:\n";
	labels.push_back(s);
	s = "Error! There is no such file!\n";
	labels.push_back(s);
	s = "Vehicle has been added.\n";
	labels.push_back(s);
}

void ConsoleInterface::MainMenu(VehicleCollection *vc) {
	while(true) {
		for (int i = 0; i < 9; i++)
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
	std::cout << "Index      |" << "ID       |" << "Type      |" << "Accesibleness???   |" << std::endl;
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
	std::cout << labels[9];
	int nm;
	std::cin >> nm;
	if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }

	std::string id;
	unsigned int sizeOfEngine;
	unsigned int numberOfGears;
	unsigned int powerOfVehicle;

	std::cout << labels[10];
	std::cin >> id;
	ClearBuf();
	std::cout << labels[11];
	std::cin >> sizeOfEngine;
	if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
	std::cout << labels[12];
	std::cin >> numberOfGears;
	if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
	std::cout << labels[13];
	std::cin >> powerOfVehicle;
	if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }

	switch (nm){
	case 1:
		bodyType typeOfBody;
		unsigned int tempBody;
		char tempDigitalSpeedo;
		bool digitalSpeedo;
		std::cout << labels[14];
		std::cin >> tempBody;
		if (std::cin.fail() || tempBody < 1 || tempBody > 4){ ClearBuf(); return false; }
		typeOfBody = static_cast<bodyType>(--tempBody);
		std::cout << labels[15];
		std::cin >> tempDigitalSpeedo;
		if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
		if (tempDigitalSpeedo == 'y')
			digitalSpeedo = true;
		else if (tempDigitalSpeedo == 'n')
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
		std::cout << labels[16];
		std::cin >> bootSize;
		if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
		std::cout << labels[17];
		std::cin >> nPlaces;
		if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
		std::cout << labels[18];
		std::cin >> tempEngine;
		if (std::cin.fail() || tempBody < 1 || tempBody > 4){ ClearBuf(); return false; }
		engine = static_cast<engineType>(--tempEngine);
		vc->AddVehicle(car, id, sizeOfEngine, numberOfGears, powerOfVehicle, classic, false, bootSize, nPlaces, engine, 0, 0);
		break;
	case 3:
		unsigned capacity;
		bool liquidSubstance;
		char tempLiquidSubstance;
		std::cout << labels[19];
		std::cin >> capacity;
		if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
		std::cout << labels[20];
		std::cin >> tempLiquidSubstance;
		if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
		if (tempDigitalSpeedo == 'y')
			liquidSubstance = true;
		else if (tempDigitalSpeedo == 'n')
			liquidSubstance = false;
		else
			return false;
		vc->AddVehicle(lorry, id, sizeOfEngine, numberOfGears, powerOfVehicle, classic, false, 0, 0, diesel, capacity, liquidSubstance);
		break;
	}
	std::cout << labels[41];
	return true;
}

bool ConsoleInterface::VehicleRemoval(VehicleCollection *vc){
	ShowData(vc);
	unsigned long long nm;
	auto isException = false;
	std::cout << labels[20];
	std::cin >> nm;
	if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
	try{
		vc->RmVehicle(nm);
	}
	catch (std::string s){
		std::cout << s;
		isException = true;
	}
	if(!isException)
		std::cout << labels[22];
	return true;
}

bool ConsoleInterface::VehicleRental(VehicleCollection *vc){
	ShowData(vc);
	unsigned long long nm;
	auto isException = false;
	std::cout << labels[23];
	std::cin >> nm;
	if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
	try {
		vc->Rental(nm);
	}
	catch(std::string s) {
		std::cout << s;
		isException = false;
	}
	if (!isException)
		std::cout << labels[24];
	return true;
}

bool ConsoleInterface::VehicleRestoration(VehicleCollection *vc){
	ShowData(vc);
	unsigned long long nm;
	auto isException = false;
	std::cout << labels[25];
	std::cin >> nm;
	if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
	try {
		vc->Restoration(nm);
	}
	catch (std::string s){
		std::cout << s;
		isException = true;
	}
	if (!isException)	
		std::cout << labels[26];
	return true;
}

bool ConsoleInterface::LoadingData(VehicleCollection *vc) {
	std::string fileName;
	std::cout << labels[27];
	std::cin >> fileName;
	if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
	for (unsigned i = 0; i < fileName.size(); i++){
		if (!isalpha(fileName[i])){
			std::cout << labels[21];
			return false;
		}
	}
	std::ifstream file(fileName, std::ios::binary);
	if (!file.good()){ std::cout << labels[29]; return false; }
	vc->LoadData(file);
	std::cout << labels[28];
	return true;
}

bool ConsoleInterface::SavingData(VehicleCollection *vc) {
	std::string fileName;
	std::cout << labels[27];
	std::cin >> fileName;
	if (std::cin.fail()){ std::cout << labels[21]; ClearBuf(); return false; }
	for (unsigned i = 0; i < fileName.size(); i++){
		if (!isalpha(fileName[i])){
			std::cout << labels[20];
			return false;
		}
	}
	std::ofstream file(fileName, std::ios::binary);
	if (!file.good()){ std::cout << labels[29]; return false; }
	vc->SaveData(file);
	std::cout << labels[28];
	return true;
}



void ConsoleInterface::ClearBuf() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
}

