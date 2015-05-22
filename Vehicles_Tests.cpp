#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include "Motorcycle.h"
#include "Car.h"
#include "Lorry.h"

BOOST_AUTO_TEST_SUITE(Vehicles)
/*
BOOST_AUTO_TEST_CASE(Motorcycle_Constructor){
	Motorcycle m;
	BOOST_CHECK(m.Accesible());
	BOOST_CHECK_EQUAL(m.GetEngineSize(), 0);
	BOOST_CHECK_EQUAL(m.GetNGears(), 0);
	BOOST_CHECK_EQUAL(m.GetPower(), 0);
	BOOST_CHECK_EQUAL(m.GetBody(), classic);
	BOOST_CHECK(!m.IsDigitalSpeedo());
}

BOOST_AUTO_TEST_CASE(Motorcycle_Constructor_with_Values){
	Motorcycle m(900, 5, 100, chopper, true) ;
	BOOST_CHECK(m.Accesible());
	BOOST_CHECK_EQUAL(m.GetEngineSize(), 900);
	BOOST_CHECK_EQUAL(m.GetNGears(), 5);
	BOOST_CHECK_EQUAL(m.GetPower(), 100);
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

BOOST_AUTO_TEST_CASE(Car_Constructor){
	Car c;
	BOOST_CHECK(c.Accesible());
	BOOST_CHECK_EQUAL(c.GetEngineSize(), 0);
	BOOST_CHECK_EQUAL(c.GetNGears(), 0);
	BOOST_CHECK_EQUAL(c.GetPower(), 0);
	BOOST_CHECK_EQUAL(c.GetBootSize(), 0);
	BOOST_CHECK_EQUAL(c.GetNPlaces(), 5);
	BOOST_CHECK_EQUAL(c.GetEngine(), petrol);
}

BOOST_AUTO_TEST_CASE(Car_Constructor_with_Values){
	Car c(2000, 6, 160, 400, 5, diesel);
	BOOST_CHECK(c.Accesible());
	BOOST_CHECK_EQUAL(c.GetEngineSize(), 2000);
	BOOST_CHECK_EQUAL(c.GetNGears(), 6);
	BOOST_CHECK_EQUAL(c.GetPower(), 160);
	BOOST_CHECK_EQUAL(c.GetBootSize(), 400);
	BOOST_CHECK_EQUAL(c.GetNPlaces(), 5);
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

BOOST_AUTO_TEST_CASE(Lorry_Constructor) {
	Lorry l;
	BOOST_CHECK(l.Accesible());
	BOOST_CHECK_EQUAL(l.GetEngineSize(), 0);
	BOOST_CHECK_EQUAL(l.GetNGears(), 0);
	BOOST_CHECK_EQUAL(l.GetPower(), 0);
	BOOST_CHECK_EQUAL(l.GetCapacity(), 0);
	BOOST_CHECK(!l.CanTransportLiquids());
}

BOOST_AUTO_TEST_CASE(Lorry_Constructor_with_Values) {
	Lorry l(3000, 6, 300, 20000, true);
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
*/
BOOST_AUTO_TEST_SUITE_END()