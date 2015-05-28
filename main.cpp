#include "ConsoleInterface.h"
#include "RentObserver.h"
#include "CountObserver.h"

int main() {
	std::ofstream observerFile("observer.txt", std::ios::app);
	RentObserver rObserver(observerFile);
	CountObserver cObserver(3);
	VehiclesCollection vc;
	vc.AddObserver(&cObserver);
	vc.AddObserver(&rObserver);
	ConsoleInterface i;
	i.MainMenu(&vc);
	observerFile.close();
	return 0;
}
