#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include "Vehicle.h"

BOOST_AUTO_TEST_SUITE(Vehicle_Tests)

BOOST_AUTO_TEST_CASE(Constructor){
	Vehicle v;
	BOOST_CHECK(v.Enable());
	BOOST_CHECK_EQUAL(v.GetEngineSize(), 0);
	BOOST_CHECK_EQUAL(v.GetNGears(), 0);
	BOOST_CHECK_EQUAL(v.GetPower(), 0);
}

BOOST_AUTO_TEST_CASE(Constructor_with_Values){
	Vehicle v(1400, 4, 140);
	BOOST_CHECK(v.Enable());
	BOOST_CHECK_EQUAL(v.GetEngineSize(), 1400);
	BOOST_CHECK_EQUAL(v.GetNGears(), 4);
	BOOST_CHECK_EQUAL(v.GetPower(), 140);
}

BOOST_AUTO_TEST_CASE(Set_Function){
	Vehicle v;
	v.SetEngineSize(1400);
	v.SetNGears(4);
	v.SetPower(140);
	BOOST_CHECK(v.Enable());
	BOOST_CHECK_EQUAL(v.GetEngineSize(), 1400);
	BOOST_CHECK_EQUAL(v.GetNGears(), 4);
	BOOST_CHECK_EQUAL(v.GetPower(), 140);
}


BOOST_AUTO_TEST_SUITE_END()