#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <sstream>
#include "Motorcycle.h"
#include "Car.h"
#include "Lorry.h"

BOOST_AUTO_TEST_SUITE(Vehicles_Tests)

BOOST_AUTO_TEST_CASE(Motorcycle_Constructor_with_Values){
	Motorcycle m(0, "ADA 2311", 30, 30, 40, chopper, true);
	BOOST_CHECK(m.Accesible());
	BOOST_CHECK_EQUAL(m.GetEngineSize(), 30);
	BOOST_CHECK_EQUAL(m.GetNGears(), 30);
	BOOST_CHECK_EQUAL(m.GetPower(), 40);
	BOOST_CHECK_EQUAL(m.GetBody(), chopper);
	BOOST_CHECK(m.IsDigitalSpeedo());
}

BOOST_AUTO_TEST_CASE(Motorcycle_Set) {
	Motorcycle m;
	m.SetBody(quad);
	m.SetDigitalSpeedo(true);
	BOOST_CHECK_EQUAL(m.GetBody(), quad);
	BOOST_CHECK(m.IsDigitalSpeedo());
}


BOOST_AUTO_TEST_CASE(Car_Constructor_with_Values){
	Car c(0, "adasdasda", 3000, 2, 3000, 4000, 4, diesel);
	BOOST_CHECK(c.Accesible());
	BOOST_CHECK_EQUAL(c.GetEngineSize(), 3000);
	BOOST_CHECK_EQUAL(c.GetNGears(), 2);
	BOOST_CHECK_EQUAL(c.GetPower(), 3000);
	BOOST_CHECK_EQUAL(c.GetBootSize(), 4000);
	BOOST_CHECK_EQUAL(c.GetNPlaces(), 4);
	BOOST_CHECK_EQUAL(c.GetEngine(), diesel);
}

BOOST_AUTO_TEST_CASE(Car_Set){
	Car c;
	c.SetBootSize(1000);
	c.SetNPlaces(4);
	c.SetEngine(hybrid);
	BOOST_CHECK_EQUAL(c.GetBootSize(), 1000);
	BOOST_CHECK_EQUAL(c.GetNPlaces(), 4);
	BOOST_CHECK_EQUAL(c.GetEngine(), hybrid);
}

BOOST_AUTO_TEST_CASE(Lorry_Constructor_with_Values) {
	Lorry l(0, "halabanacha", 3000, 6, 300, 20000, true);
	BOOST_CHECK(l.Accesible());
	BOOST_CHECK_EQUAL(l.GetEngineSize(), 3000);
	BOOST_CHECK_EQUAL(l.GetNGears(), 6);
	BOOST_CHECK_EQUAL(l.GetPower(), 300);
	BOOST_CHECK_EQUAL(l.GetCapacity(), 20000);
	BOOST_CHECK(l.CanTransportLiquids());
}

BOOST_AUTO_TEST_CASE(Lorry_Set) {
	Lorry l;
	l.SetCapacity(30000);
	l.SetLiquidSubstance(true);
	BOOST_CHECK_EQUAL(l.GetCapacity(), 30000);
	BOOST_CHECK(l.CanTransportLiquids());
}

BOOST_AUTO_TEST_CASE(Vehicle_Saving) {
	std::stringstream s;
	Motorcycle m(0, "ADA 2311", 30, 30, 40, chopper, true);
	Motorcycle mResult;
	m.SaveVehicle(s);
	unsigned a;
	s.read(reinterpret_cast<char *>(&a), sizeof(unsigned int));
	mResult.LoadVehicle(s);
	BOOST_CHECK(mResult.Accesible());
	BOOST_CHECK_EQUAL(mResult.GetEngineSize(), 30);
	BOOST_CHECK_EQUAL(mResult.GetNGears(), 30);
	BOOST_CHECK_EQUAL(mResult.GetPower(), 40);
	BOOST_CHECK_EQUAL(mResult.GetBody(), chopper);
	BOOST_CHECK(mResult.IsDigitalSpeedo());
}

BOOST_AUTO_TEST_SUITE_END()