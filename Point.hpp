#ifndef POINT_HPP_
#define POINT_HPP_
#include <iostream>

template <typename T>
class Point{
	private :
	T _x;
	T _y;
	
	public :
	//Constucteurs 
	Point() : _x(0), _y(0){};
	Point(T x, T y) : _x(x), _y(y){};

	//Methodes
	const T getX() const {return this->_x;}
	const T getY() const {return this->_y;}
	
	void setX(T x){this->_x=x;}
	void setY(T y){this->_y=y;}
	
	void operator=(const Point<T>& p){
		setX(p.getX());
		setY(p.getY());
	}
	
	bool operator==(Point<T>& p){
		std::cout<<p.getX() <<" " <<getX() <<std::endl;
		if(p.getX()==getX() && p.getY()==getY())
		{
			return true;
		}
		return false;
	}
};

//Const car : une référence non constante ne peux pas être initialisée par un objet temporaire. Or c'est précisément ce que doit renvoyer l'opérateur ()
template <typename T>
struct AddP{
	Point<T> operator()(const Point<T>& x,const Point<T>& y){
		return Point<T>(x.getX()+ y.getX(),x.getY()+y.getY());
	}
};
	
#endif
