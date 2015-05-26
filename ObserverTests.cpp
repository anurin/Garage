#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <sstream>
#include "VehiclesCollection.h"
#include "RentObserver.h"

BOOST_AUTO_TEST_SUITE(Observer_Tests)

BOOST_AUTO_TEST_CASE(RentObserver_Saving_Data){
	VehiclesCollection vc;
	vc.AddVehicle(motorcycle, "ADA 2311", 30, 30, 40, chopper, true, 0, 0, diesel, 0, true);
	std::stringstream s;
	RentObserver *r = new RentObserver(3, s);
	vc.AddObserver(r);
	vc.Rental(1);
	std::string a;
	std::string b;
	std::string c;
	s >> a >> b >> c;
	BOOST_CHECK_EQUAL(a, "ADA");
	BOOST_CHECK_EQUAL(b, "2311");
	BOOST_CHECK_EQUAL(c, "rented");
	BOOST_CHECK(r->IsRentingPossible());
	vc.Restoration(1);
	s >> a >> b >> c;
	BOOST_CHECK_EQUAL(a, "ADA");
	BOOST_CHECK_EQUAL(b, "2311");
	BOOST_CHECK_EQUAL(c, "restored");
}

BOOST_AUTO_TEST_SUITE_END()