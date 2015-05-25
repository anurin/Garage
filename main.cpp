#include "ConsoleInterface.h"
#include "RentObserver.h"

int main() {
	std::ofstream observerFile("observer.txt", std::ios::app);
	RentObserver *observer = new RentObserver(5, observerFile);
	VehicleCollection *vc = new VehicleCollection;
	ConsoleInterface i;
	i.MainMenu(vc);
	return 0;
}