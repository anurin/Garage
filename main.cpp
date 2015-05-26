#include "ConsoleInterface.h"
#include "RentObserver.h"

int main() {
	std::ofstream observerFile("observer.txt", std::ios::app);
	RentObserver observer(5, observerFile);
	VehiclesCollection vc;
	vc.AddObserver(&observer);
	ConsoleInterface i;
	i.MainMenu(&vc);
	observerFile.close();
	return 0;
}