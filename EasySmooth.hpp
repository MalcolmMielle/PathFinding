#ifndef SMOOTHER_SIMPLE_HPP_
#define SMOOTHER_SIMPLE_HPP_
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

class EasySmooth : public Smoother{
	protected :
	
	public : 
	virtual void smoothIt(std::deque<Data*> _way) {};
	
};
#endif
