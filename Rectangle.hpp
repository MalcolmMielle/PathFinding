#ifndef REC_HPP
#define REC_HPP

#include "Point.hpp"
#include "Forme.hpp"

/***On ne peut pas declarer un template dans un .cpp..."****/
template <typename T>
class Rectangle : public Forme<T>
{
	private : 
	T _longueur;
	T _largeur; //horizontal
	public : 
	//Constructeur
	Rectangle() : Forme<T>(), _longueur(0), _largeur(0){};
	Rectangle (int lon, int lar, Point<T>cen) : Forme<T>(cen){
		_longueur=lon;
		_largeur=lar;
	};
	virtual ~Rectangle(){};
	T getLargeur() const {return _largeur;}
	T getLongueur() const {return _longueur;}
	virtual bool collide (const Forme<T>& f) const {
		return f.collide(*this);
	}
	virtual bool collide (const Rectangle<T>& f) const ;
	virtual void affiche() const ;
};


template <typename T>
inline bool Rectangle<T>::collide (const Rectangle<T>& rec1) const {
//Quand ils se touchent, il n'y a pas collision
	//Rectangle<T>* rec1 = dynamic_cast<Rectangle<T> *>(&f);
	if( this->_centre.getX() >= rec1.getCentre().getX() + rec1.getLargeur()      // trop à droite
    	|| this->_centre.getX() + _largeur <= rec1.getCentre().getX() // trop à gauche
    	|| (this->_centre.getY() >= rec1.getCentre().getY() + rec1.getLongueur()) // trop en bas
    	|| (this->_centre.getY() + _longueur <= rec1.getCentre().getY())) { // trop en haut
	    	return false; 
	}
   	else{
	    	return true;
	}
	return false;
}

template <typename T>
inline void Rectangle<T>::affiche() const {
	std::cout << "Le rectangle est de centre " << this->_centre.getX() << ", " <<this->_centre.getY()<< " de longueur " << _longueur << " de largeur" << _largeur << std::endl;
	
}

#endif
