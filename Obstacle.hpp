#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_
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

class Obstacle{
	protected : 
	Forme<float>* _shape;
	
	public : 
	Obstacle() :  _shape(new Rectangle<float>(0, 0, Point<float>())){};
	Obstacle(int dim, Point<float> where) :  _shape(new Rectangle<float>(dim, dim, where)){};
	Obstacle(int dim, int dim2, Point<float> where) :  _shape(new Rectangle<float>(dim, dim2, where)){};
	
	~Obstacle(){
		std::cout << "DESTROY OBSTACLES"<<std::endl;
		delete _shape;
	}
	
	const Forme<float>& getShape() const {return *_shape;}
	
	void affiche(){
		_shape->affiche();
	}
};
#endif
	
