	#include "RentObserver.h"

RentObserver::RentObserver(std::ostream& f)
:savingStream(f)
{}

RentObserver::~RentObserver(){}

void RentObserver::Update(Vehicle *v){
	savingStream << v->GetId() << " ";
	if (v->Accesible()){
		savingStream << "restored";
	}
	else{
		savingStream << "rented";
	}
	savingStream << std::endl;
}

