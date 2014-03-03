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

	//Drawing the map >>
	
	std::vector<Data*> m;
	for(int i=0;i<30;i++){
		Data* d= new Data();
		m.push_back(d);
	}
	
	BOOST_CHECK_EQUAL(m.size(), 30);
	int place= 3;
	
	for(int i=0;i<4;i++){
		m[place+(i*5)]->setWalkable(false);
	}
	for(size_t i=0;i<m.size();i++){
		m[i]->setX(i);
		m[i]->setPoint(i,5);
	}
	
	Data d(0,5,true);
	Data d2(4,5,true);
	
	BOOST_CHECK(d==*m[0]);
	
	Astar a(d, d2, m, 5);
	//BOOST_CHECK(m[0]->getPoint()==*(a.realPosition(m[0])));
	
	a.drawMap();
	a.affiche();
	a.pathFinding();
	
	std::cout << "THE FINAL "<< std::endl;
	
	a.affichePath();
	a.drawMap();
	
	
	std::vector<Data*> v;
	a.setMap(v);
	
	



}
