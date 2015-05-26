#include "ConsoleInterface.h"

ConsoleInterface::ConsoleInterface() {
	std::string s;
	s = "\nGarage Management\n(0) Exit\n";	//0
	labels.push_back(s);
	s = "(1) Show data base\n";		//1
	labels.push_back(s);
	s = "(2) Add vehicle\n";		//2
	labels.push_back(s);
	s = "(3) Remove vehicle\n";		//3
	labels.push_back(s);
	s = "(4) Rent vehicle\n";		//4
	labels.push_back(s);
	s = "(5) Restore vehicle\n";	//5
	labels.push_back(s);
	s = "(6) Load data\n";			//6
	labels.push_back(s);
	s = "(7) Save data\n";			//7
	labels.push_back(s);
	s = "Choose action:\n";			//8
	labels.push_back(s);
	s = "Choose type of vehicle\n(1) Motorcycle\n(2) Car\n(3) Lorry\n";	//9
	labels.push_back(s);
	s = "ID (8 characters):\n";		//10
	labels.push_back(s);
	s = "Engine size:\n";			//11
	labels.push_back(s);
	s = "Number of gears:\n";		//12
	labels.push_back(s);
	s = "Power of vehicle:\n";		//13
	labels.push_back(s);
	s = "Body type:\n(1) classic\n(2) chopper\n(3) cruiser\n(4) quad\n";	//14
	labels.push_back(s);
	s = "Has digital speedo? (y/n):\n";		//15
	labels.push_back(s);
	s = "Boot size:\n";				//16
	labels.push_back(s);
	s = "Number of places:\n";		//17
	labels.push_back(s);
	s = "Engine type:\n(1) diesel\n(2) petrol\n(3) hybrid\n(4) electric\n";	//18
	labels.push_back(s);
	s = "Capacity:\n";				//19
	labels.push_back(s);
	s = "Can transport liquids? (y/n):\n";		//20
	labels.push_back(s);
	s = "Choose the position to remove:\n";		//21
	labels.push_back(s);
	s = "Entered data is incorrect.\n";			//22
	labels.push_back(s);
	s = "The position has been removed.\n";		//23
	labels.push_back(s);
	s = "Choose the position to rent:\n";		//24
	labels.push_back(s);
	s = "The vehicle has been rented.\n";		//25
	labels.push_back(s);
	s = "Choose the position to restore:\n";	//26
	labels.push_back(s);
	s = "The vehicle has been restored.\n";		//27
	labels.push_back(s);
	s = "Type file name to load data:\n";		//28
	labels.push_back(s);
	s = "Data has been loaded.\n";				//29
	labels.push_back(s);
	s = "Type file name to save data:\n";		//30
	labels.push_back(s);
	s = "Data has been saved.\n";				//31
	labels.push_back(s);
	s = "Error! Incorrect file name!\n";		//32
	labels.push_back(s);
	s = "Vehicle has been added.\n";			//33
	labels.push_back(s);
}

bool ConsoleInterface::MainMenu(VehicleCollection *vc) {
	while(true) {
		for (int i = 0; i < 9; i++)
			std::cout << labels[i];
		int nm;
		std::cin >> nm;
		if (std::cin.fail() || nm < 0 || nm > 7){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}
		switch (nm){
			case 0:
				return true;
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
	std::cout << "Index |" << "ID       |" << "Type       |" << "Accessibility|" << std::endl;
	std::list<Vehicle*>::iterator it;
	for (it = vc->vehicles.begin(); it != vc->vehicles.end(); it++) {
		std::cout << "(" << (*it)->GetIndex() << ")   ";
		std::cout << std::setw(10) << (*it)->GetId() << "  ";
		if ((*it)->GetType() == 0)
			std::cout << std::setw(11) << "Motorcycle ";
		if ((*it)->GetType() == 1)
			std::cout << std::setw(11) << "Car ";
		if ((*it)->GetType() == 2)
			std::cout << std::setw(11) << "Lorry ";
		if ((*it)->Accesible())
			std::cout << std::setw(13) << "E";
		else
			std::cout << std::setw(13) << "D";
		std::cout << std::endl;
	}
}

bool ConsoleInterface::VehicleAddition(VehicleCollection *vc){
	std::cout << labels[9];
	int nm;
	std::cin >> nm;
	if (std::cin.fail() || nm > 4 || nm < 1){ std::cerr<< labels[22]; ClearBuf(); return false; }

	std::string id;
	unsigned int sizeOfEngine;
	unsigned int numberOfGears;
	unsigned int powerOfVehicle;

	std::cout << labels[10];
	std::cin >> id;
	if (id.size() > 8) { std::cout << labels[22]; return false; }
	ClearBuf();
	std::cout << labels[11];
	std::cin >> sizeOfEngine;
	if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
	std::cout << labels[12];
	std::cin >> numberOfGears;
	if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
	std::cout << labels[13];
	std::cin >> powerOfVehicle;
	if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }

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
		if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
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
		if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
		std::cout << labels[17];
		std::cin >> nPlaces;
		if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
		std::cout << labels[18];
		std::cin >> tempEngine;
		if (std::cin.fail() || tempEngine < 1 || tempEngine > 4){ std::cerr<< labels[22]; ClearBuf(); return false; }
		engine = static_cast<engineType>(--tempEngine);
		vc->AddVehicle(car, id, sizeOfEngine, numberOfGears, powerOfVehicle, classic, false, bootSize, nPlaces, engine, 0, false);
		break;
	case 3:
		unsigned capacity;
		bool liquidSubstance;
		char tempLiquidSubstance;
		std::cout << labels[19];
		std::cin >> capacity;
		if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
		std::cout << labels[20];
		std::cin >> tempLiquidSubstance;
		if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
		if (tempDigitalSpeedo == 'y')
			liquidSubstance = true;
		else if (tempDigitalSpeedo == 'n')
			liquidSubstance = false;
		else
			return false;
		vc->AddVehicle(lorry, id, sizeOfEngine, numberOfGears, powerOfVehicle, classic, false, 0, 0, diesel, capacity, liquidSubstance);
		break;
	}
	std::cout << labels[33];
	return true;
}

bool ConsoleInterface::VehicleRemoval(VehicleCollection *vc){
	ShowData(vc);
	unsigned long long nm;
	std::cout << labels[21];
	std::cin >> nm;
	if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
	try{
		vc->RmVehicle(nm);
	}
	catch (std::string s){
		std::cerr << s;
	}
	return true;
}

bool ConsoleInterface::VehicleRental(VehicleCollection *vc){
	ShowData(vc);
	unsigned long long nm;
	std::cout << labels[24];
	std::cin >> nm;
	if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
	try {
		vc->Rental(nm);
	}
	catch(std::string s) {
		std::cerr << s;
	}
	return true;
}

bool ConsoleInterface::VehicleRestoration(VehicleCollection *vc){
	ShowData(vc);
	unsigned long long nm;
	std::cout << labels[26];
	std::cin >> nm;
	if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
	try {
		vc->Restoration(nm);
	}
	catch (std::string s){
		std::cerr << s;
	}
	return true;
}

bool ConsoleInterface::LoadingData(VehicleCollection *vc) {
	std::string fileName;
	std::cout << labels[28];
	std::cin >> fileName;
	if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
	for (unsigned i = 0; i < fileName.size(); i++){
		if (!isalpha(fileName[i])){
			std::cout << labels[22];
			return false;
		}
	}
	std::ifstream file(fileName, std::ios::binary);
	if (!file.good()){ std::cerr << labels[32]; return false; }
	vc->LoadData(file);
	std::cout << labels[29];
	return true;
}

bool ConsoleInterface::SavingData(VehicleCollection *vc) {
	std::string fileName;
	std::cout << labels[30];
	std::cin >> fileName;
	if (std::cin.fail()){ std::cerr<< labels[22]; ClearBuf(); return false; }
	for (unsigned i = 0; i < fileName.size(); i++){
		if (!isalpha(fileName[i])){
			std::cerr << labels[22];
			return false;
		}
	}
	std::ofstream file(fileName, std::ios::binary);
	if (!file.good()){ std::cerr << labels[32]; return false; }
	vc->SaveData(file);
	std::cout << labels[31];
	return true;
}



void ConsoleInterface::ClearBuf() {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}

