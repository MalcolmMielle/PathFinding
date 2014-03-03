#ifndef ENVIRONNEMENT_HPP_
#define ENVIRONNEMENT_HPP_
#include <iostream>
#include "Forme.hpp"
#include "Rectangle.hpp"
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include "Data.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"
#include "Smoother.hpp"
#include "Astar.hpp"
#include "Map.hpp"

class Environnement{
	
	protected : 
	std::vector<Obstacle*> _obs;
	std::vector<Robot*> _rob;
	std::vector<Data*> _path;
	Smoother* _smoo;
	Astar _astar;
	Map _map;
	
	public : 
	Environnement(const std::vector<Obstacle*>& obs, const std::vector<Robot*>& rob, Smoother* sm, const Astar& as) : _obs(obs), _rob(rob), _smoo(sm), _astar(as){};
	Environnement(const Map& map, Smoother* sm, const Astar& as) : _smoo(sm), _astar(as), _map(map){};
	~Environnement(){
		std::cout << "ENVI DESTRUCTION"<<std::endl;
		eraseObstacles();
		eraseRobots();
		}
	/********************************************/
	void create(std::vector<Obstacle*>& obs, std::vector<Robot*>& rob);
	void create();
	void path();
	void smooth();
	/********************ACCESSEUR************************/
	const Map& getMap(){return _map;}
	const std::vector<Obstacle*>& getObs(){return _obs;}
	const std::vector<Robot*>& getRob(){return _rob;}
	const std::vector<Data*>& getPath(){return _path;}
	Smoother* getSmoo(){return _smoo;}
	Astar& getAstar() {return _astar;}
	void set(Smoother* s){_smoo=s;}
	void set(const Astar& a){
		//clean astar au cazou
		_astar.eraseM();
		_astar=a;}
	void set(std::vector<Data*> p){_path=p;}
	void set(Map m){_map=m;}

	/****************************************************/
	void eraseObstacles(){
		std::cout << "OUech gros "<< _obs.size()<<std::endl;
		for(typename std::vector<Obstacle*>::iterator it=_obs.begin();it!=_obs.end();){
			std::cout<<"DIE BITCH "<<std::endl;
			delete(*it);
			_obs.erase(it);
		}
	}
	
	void eraseRobots(){
		std::cout << "OUech gros "<< _obs.size()<<std::endl;
		for(typename std::vector<Robot*>::iterator it=_rob.begin();it!=_rob.end();){
			std::cout<<"DIE BITCH "<<std::endl;
			delete(*it);
			_rob.erase(it);
		}
	}
	
	void afficheObstacles(){
		std::cout << "OUech gros on est des obstacles"<< _obs.size()<<std::endl;
		for(typename std::vector<Obstacle*>::iterator it=_obs.begin();it!=_obs.end();){
			(**it).affiche();
			it++;
		}
	}
	
	void afficheRobots(){
		std::cout << "OUech gros on est des robots"<< _obs.size()<<std::endl;
		for(typename std::vector<Robot*>::iterator it=_rob.begin();it!=_rob.end();){
			(**it).affiche();
			it++;
		}
	}


};

#endif
