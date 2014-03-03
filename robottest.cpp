#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "Data.hpp"
#include "Astar.hpp"
#include "Robot.hpp"
#include "Obstacle.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "Environnement.hpp"
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Robot rob;
	Robot r1(2,2,Point<float>(0,0));
	Robot r2(2,2,Point<float>(1,0));
	
	BOOST_CHECK(r1.collide(r2));
	
	Obstacle ob(2,Point<float>(1,0));
	BOOST_CHECK(r1.collide(ob));
	r1.affiche();
	
	r1.move(Point<float>(-0.9,0));
	BOOST_CHECK(r1.collide(ob));
	r1.affiche();
	
	r1.move(Point<float>(-1,0));
	BOOST_CHECK_EQUAL(r1.collide(ob), false);
	r1.affiche();	
	
	r1.move(1,0.5);
	BOOST_CHECK(r1.collide(ob));
	r1.affiche();
	
	r1.move(0,1.5);
	BOOST_CHECK_EQUAL(r1.collide(ob), false);
	r1.affiche();
	
	
	

}
