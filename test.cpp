#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "Data.hpp"
#include "Astar.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Data d;
	//BOOST_CHECK(d.isOlist());
	d.setOlist();
	BOOST_CHECK(d.isOlist());
	
	Data* d1=new Data();
	Data d2;
	Data d3;
	Data d4;
	Data d5;
	
	d1->setF(20);
	BOOST_CHECK_EQUAL(d1->getF(),20);
	
	d2.setF(2);
	d3.setF(200);
	d4.setF(85);
	d5.setF(65);
	
	std::vector<Data*> v;
	
	Astar astar(d1, &d2);
	astar.addMap(d1);
	astar.addO(d1,1,1);
	astar.addO(&d2,1,1);
	astar.addO(&d3,1,1);
	astar.addO(&d4,1,1);
	astar.addO(&d5,1,1);
	
	astar.cleanOlist();
	astar.afficheOlist();
	
	Data d6;
	d6.setF(152);
	
	//test heuristic
	Point<float> p(2,0);
	float y=astar.heuristic(p);
	BOOST_CHECK_EQUAL(y,20);

}
