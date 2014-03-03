#ifndef FORME_HPP
#define FORME_HPP

#include "Point.hpp"

//Afin d'éviter la double inclusion, on crée une fausse classe rectangle dans forme.
template <typename T>
class Rectangle;


template <typename T>
class Forme
{
	protected :
	Point<T> _centre;
	
	public :
	//Constructeur
	Forme() : _centre( Point<int>() ){};
	Forme(const Point<T>& cen) : _centre(cen){};
	virtual ~Forme(){};
	const Point<T>& getCentre() const {return _centre;}
	//Methodes
		//Pour les references et les temporaires...
	void setCentre(const Point<T>& p){_centre=p;}
	Point<T> getCentre(){return _centre;};
	void move(const Point<T>& p);
	/*bool collide (Forme<T>& f){
		Rectangle<T> p =dynamic_cast<Rectangle<T>& >(f);
		return this->collide(p);
		
	}*/
	virtual bool collide (const Forme<T>& f) const {
		return f.collide(*this);
	}
	virtual bool collide (const Rectangle<T>& f) const {std::cout<<"Je suis une forme "<<std::endl;return false;}
	virtual void affiche() const {std::cout << "I am "<< _centre.getX() << " "<< _centre.getY()<<std::endl;}

};

template <typename T>
inline void Forme<T>::move(const Point<T>& p){
	AddP<T> add;
	_centre=add(_centre,p);
}


#endif




