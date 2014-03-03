#ifndef DATA_PATHFINDING_H
#define DATA_PATHFINDING_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Point.hpp"

class Data{
	protected : 
	int _x;
	Point<float>_p;
	float _G;
	float _H;
	float _F;
	Data* _parent;
	bool _Clist;
	bool _Olist;
	bool _Walkable;
	
	public : 
	Data() : _x(0) , _p(Point<float>()), _G(0), _H(0), _F(0), _parent(NULL), _Clist(false), _Olist(false), _Walkable(true){};
	Data(int x, int l, bool w) : _x(x), _G(0), _H(0), _F(0), _parent(NULL), _Clist(false), _Olist(false), _Walkable(w){
		setPoint(x,l);
	}
	
	float getG(){return _G;}
	float getF(){return _F;}
	float getH(){return _H;}
	int getX() const {return _x;}
	Data* getParent() const {return _parent;}
	const Point<float>& getPoint() const {return _p;}
	
	void setF(){_F=_G+_H;}
	void setG(float g){_G=g;}
	void setH(float h){_H=h;}
	void setF(float f){_F=f;}
	void setWalkable(bool w){_Walkable=w;}
	void setX(int i){_x=i;}
	void setPoint(Point<float>& p2){_p=p2;}
	void setPoint(int i, int l){
		//std::cout<< "en vrai " << pos << " et "<< pos2 <<std::endl;
		_p = Point<float>(i%(l), i/(l));
	}
	
	bool isOlist(){return _Olist;}
	bool isClist(){return _Clist;}
	bool isWalkable(){return _Walkable;}
	
	void setParent(Data* d){_parent=d;}
	
	
	void setOlist(){
		_Olist=true;
	}
	
	void setClist(){
		_Clist=true;
	}
	
	void affiche() const {
		std::cout << "G : " << _G << " " << "H : " << _H << " " << "F : " << _F << std::endl;
	}
	
	
	bool operator==(Data& p){
		//std::cout<<p.getX() <<" " <<getX() <<std::endl;
		if(p.getX()==getX() && p.getPoint().getX()==getPoint().getX() && p.getPoint().getY()==getPoint().getY())
		{
			if(p.getParent()==getParent()){
				if(p.isWalkable()==isWalkable()){
					return true;
				}
			}
		}
		return false;
	}
	
	//Clacul du previous path

	
	
};
#endif
	
	
