	#include "RentObserver.h"

RentObserver::RentObserver(int a, std::ostream& f)
:counter(0), maxCounter(a), savingStream(f)
{}

RentObserver::~RentObserver(){}

void RentObserver::Update(Vehicle *v){
	savingStream << v->GetId() << " ";
	if (v->Accesible()){
		savingStream << "restored";
	}
	else{
		savingStream << "rented";
		counter++;
	}
	savingStream << std::endl;

}

bool RentObserver::IsRentingPossible() const{
	if (counter < maxCounter)
		return true;
	else
		return false;
}