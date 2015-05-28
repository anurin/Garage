#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <sstream>
#include "VehiclesCollection.h"
#include "RentObserver.h"
#include "CountObserver.h"

BOOST_AUTO_TEST_SUITE(Observer_Tests)

BOOST_AUTO_TEST_CASE(RentObserver_Saving_Data){
	VehiclesCollection vc;
	vc.AddVehicle(motorcycle, "ADA2311", 30, 30, 40, chopper, true, 0, 0, diesel, 0, true);
	std::stringstream s;
	RentObserver *r = new RentObserver(s);
	CountObserver *c = new CountObserver(3);
	vc.AddObserver(r);
	vc.AddObserver(c);
	vc.Rental(1);
	std::string a;
	std::string b;
	s >> a >> b;
	BOOST_CHECK_EQUAL(a, "ADA2311");
	BOOST_CHECK_EQUAL(b, "rented");
	BOOST_CHECK(c->IsRentingPossible());
	vc.Restoration(1);
	s >> a >> b;
	BOOST_CHECK_EQUAL(a, "ADA2311");
	BOOST_CHECK_EQUAL(b, "restored");
	delete r;
	delete c;
}

BOOST_AUTO_TEST_CASE(RentObserver_Rent_Counter){
	VehiclesCollection vc;
	vc.AddVehicle(car, "AHDY2343", 30, 30, 30, classic, false, 30, 39, hybrid, 0, false);
	std::stringstream s;
	RentObserver *r = new RentObserver(s);
	CountObserver *c = new CountObserver(1);
	vc.AddObserver(r);
	vc.AddObserver(c);
	vc.Rental(1);
	bool b = c->IsRentingPossible();
	BOOST_CHECK(!b);
	delete r;
	delete c;
}

BOOST_AUTO_TEST_SUITE_END()
