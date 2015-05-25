#include "ConsoleInterface.h"
#include "RentObserver.h"

int main() {
	std::ofstream observerFile("observer.txt", std::ios::app);
	RentObserver *observer = new RentObserver(5, observerFile);
	VehicleCollection *vc = new VehicleCollection;
	vc->AddObserver(observer);
	ConsoleInterface i;
	i.MainMenu(vc);
	observerFile.close();
	delete observer;
	delete vc;
	return 0;
}