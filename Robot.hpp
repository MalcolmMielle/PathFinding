#ifndef ROBOT_HPP_
#define ROBOT_HPP_
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

class Robot{
	protected : 
	float _dim_wheel;
	Forme<float>* _shape;

	public : 
	Robot() : _dim_wheel(0),  _shape(new Rectangle<float>(0, 0, Point<float>())){};
	Robot(int dim, int dw, Point<float> start) : _dim_wheel(dw), _shape(new Rectangle<float>(dim, dim, start)){};
	virtual ~Robot(){
		delete _shape;
	}
	
	/***************************/
	
	float getDimWheel(){return _dim_wheel;}
	const Forme<float>& getShape() const {return *_shape;}
	virtual void move(const Point<float>& p){_shape->move(p);}
	
	virtual void move(float xx, float yy){_shape->move(Point<float>(xx, yy));}
	
	/*************************/
	
	virtual bool collide(const Robot& rob) const {
		bool b = (*this)._shape->collide(rob.getShape());
		return b;
	}
		
	virtual bool collide(const Obstacle& ob) const {
		bool b = (*this)._shape->collide(ob.getShape());
		return b;
	}
	
	virtual void affiche(){
		std::cout << "I AM A ROBOT ";
		_shape->affiche();
	}

};
#endif
