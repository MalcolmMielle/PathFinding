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
#include "Map.hpp"
#include "EasySmooth.hpp"
#include <boost/assign/std/deque.hpp>
using namespace boost::assign; // bring 'operator+=()' into scope


/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{

	//Test unitaire de Map//

	std::deque<int> map;
	map += 0,0,0,1,0,
	0,0,0,1,0,
	0,0,0,1,0,
	0,0,0,1,0,
	0,0,0,0,0,
	0,0,0,0,0;
	//std::cout<< map[0]<<" "<<map[1]<< " "<<map.size()<<std::endl;
	
	EasySmooth e;
	Data d;
	
	Astar a(d, d);
	
	Map mapp(map, 5, 6, Point<float>(0,0), Point<float>(4,0),1,1);
	mapp.affiche();
	
	mapp.set(2,2,3);
	mapp.set(0,15);
	BOOST_CHECK_EQUAL(mapp.get(0),15);
	BOOST_CHECK_EQUAL(mapp.get(2,2),3);
	mapp.affiche();
	
	Point<float> p;
	mapp.vec2real(11,p);
	BOOST_CHECK_EQUAL(p.getX(),1);
	BOOST_CHECK_EQUAL(p.getY(),2);
	
	int o;
	o=mapp.real2vec(Point<float>(1,2));
	BOOST_CHECK_EQUAL(o,11);
	
	
	/********************TEST DE ENVIRONNEMENT*****************/
	
	std::cout<<std::endl<<" ENVIRONE " <<std::endl;
	
	Environnement env(mapp, &e, a);
	//Obstacles
	env.getMap().affiche();
	//env.initAstar();
	env.create();
	env.getAstar().drawMap();
	
	//env.afficheR();
	//env.afficheO();
	
	env.getAstar().affiche();
	
	env.getAstar().pathFinding();
	env.getAstar().affichePath();
	env.getAstar().drawMap();
	//Environnement env;
	
	/****************SECONDE MAP*****************************/
	
	Astar a1(d, d);	

	
	
	
	map.clear();
	map += 0,0,1,0,0,0,0,
	0,0,1,0,0,0,0,
	0,0,1,0,0,1,0,
	1,0,0,0,0,0,0,
	0,0,0,1,1,0,0,
	1,0,0,0,0,0,0;
	
	mapp.loadNew(map, 7, 6);
	mapp.setStart(Point<float>(5,5));
	mapp.setEnd(Point<float>(1,0));
	Environnement env2(mapp, &e, a1);
	BOOST_CHECK_EQUAL(mapp.getLength(),7);
	BOOST_CHECK_EQUAL(mapp.getWidth(),6);
	
	env.set(mapp);
	//env.set(a1);
	env.create();
	env.getAstar().pathFinding();
	env.getAstar().affichePath();
	env.getAstar().drawMap();
	
	
	
	
	

}
