#ifndef MAPSENT_HPP_
#define MAPSENT_HPP_
#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>

class Map{
	protected : 
	std::deque<int> _map;
	int _length;
	int _width;
	Point<float> _robot;
	Point<float> _arrival;
	int _dimRob;
	int _dimWe;
	
	public : 
	Map() : _length(0), _width(0){};
	Map(const std::deque<int>& m , int l, int w, const Point<float>& s, const Point<float>& e, int dim, int dimW) : _map(m), _length(l), _width(w), _robot(s), _arrival(e), _dimRob(dim), _dimWe(dimW){};
	
	/********************************************/
	int getLength(){return _length;}
	int getWidth(){return _width;}
	std::deque<int>& getMap(){return _map;}
	int get(int i){return _map[i];}
	int get(int xx, int yy){int where=(xx+(_length*yy));return _map[where];}
	void set(int where, int what){_map[where]=what;}
	void set(int xx, int yy, int what){int where=xx+(_length*yy);_map[where]=what;}
	void loadNew(std::deque<int> m, int l, int w){_map=m;_length=l;_width=w;}
	
	Point<float>& getStart(){return _robot;}
	Point<float>& getEnd(){return _arrival;}
	void setStart(const Point<float>& r){_robot=r;}
	void setEnd(const Point<float>& a){_arrival=a;}
	int getDim(){return _dimRob;}
	void setDim(int i){_dimRob=i;}
	int getDimW(){return _dimWe;}
	void setDimW(int i){_dimWe=i;}
	
	
	void vec2real(int i, Point<float>& p) const {return p=Point<float>(i%(_length), i/(_length));}
	int real2vec(const Point<float>& p) const {return (p.getY()*_length)+p.getX();}
	
	
	
	
	
	/*********************************************/
	void affiche() const {
		for(int i=0;i<_width;i++){
			for(int j=0;j<_length;j++){
				std::cout<<_map[j+(i*_length)]<<" ";
			}
			std::cout<<std::endl;
		}
	}
};

#endif
