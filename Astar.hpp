#ifndef ASTAR_PATHFINDING_H
#define ASTAR_PATHFINDING_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include "Data.hpp"
#include "Point.hpp"

class Astar{
	protected : 
	std::deque<Data*> _OpenList;
	std::deque<Data*> _ClosedList;
	std::vector<Data*> _Map;
	int _length; //If 5element in the table then it's 5, not 4 !!
	int _width;
	Data _start;
	Data _end;
	int _xcur;
	int _newclean;
	
	public : 
	Astar(const Data& s, const Data& e) : _start(s), _end(e), _xcur(0), _newclean(0){};
	Astar(const Data& s, const Data& e, std::vector<Data*>& m, int l) :_Map(m), _length(l), _width(m.size()/l), _start(s), _end(e), _newclean(0){}
	
	~Astar(){
	
		//std::cout << "DESTRUCTION " <<std::endl;
		eraseM();
		//delete _start;
		//delete _end;
	}
	
	//Astar functions in cpp		
	/*************************************************/
	void findUpdateAdjacent();
	void quickSort(int left, int right); //Warning take care of the length before throwing a quick sort
	void cleanOlist();
	void pathFinding();
	void addO(Data* d, int i, int j);
	float heuristic(const Point<float>& p1) const;
	
	/************************************************/	
	
	void addMap(Data* d){
		_Map.push_back(d);
	}
	
	void addC(Data* d){
		d->setClist(); //flag to open list
		//d->setParent(_Map[_xcur]); //Set the current point as the parent for the openlist point	
		_ClosedList.push_front(d);
	}
	
	void setMap(std::vector<Data*> d, int l, int w){
		eraseM();
		_Map=d;
		_length=l;
		_width=w;
	}
	
	void setLength(int l){_length=l;}
	void setWidth(int w){_width=w;}
	void setStart(Data& d){_start=d;}
	void setEnd(Data& d){_end=d;}
	/*******AFFICHE*****/
	
	void afficheOlist() const {
		for(typename std::deque<Data*>::const_iterator it=_OpenList.begin();it!=_OpenList.end();){
			(**it).affiche();
			it++;
		}
		
	}
	
	void afficheOlistsmall() const {
		for(typename std::deque<Data*>::const_iterator it=_OpenList.begin();it!=_OpenList.end();){
			std::cout <<"x : "<<(**it).getPoint().getX()<<" y : "<<(**it).getPoint().getY()<< " paretn " << (**it).getParent()<<std::endl;
			it++;
		}
		
	}
	
	void afficheClistsmall() const {
		for(typename std::deque<Data*>::const_iterator it=_ClosedList.begin();it!=_ClosedList.end();){
			std::cout <<"x : "<<(**it).getPoint().getX()<<" y : "<<(**it).getPoint().getY()<< " paretn " << (**it).getParent()<<std::endl;
			it++;
		}
		
	}
	
	void afficheClist() const {
		for(typename std::deque<Data*>::const_iterator it=_ClosedList.begin();it!=_ClosedList.end();){
			(**it).affiche();
			it++;
		}
	}
	
	void drawMap() const {
		std::cout<<std::endl;
		int j=0;
		int flag;
		std::deque<Data*> v;
		Data* ros=_ClosedList[0];
		if(!_ClosedList.empty()){
			while(ros->getParent()!=NULL){
				std::cout <<"x : "<<ros->getPoint().getX()<<" y : "<<ros->getPoint().getY()<<std::endl;
				v.push_back(ros);
				ros=ros->getParent();
			}
			std::cout <<"x : "<<ros->getPoint().getX()<<" y : "<<ros->getPoint().getY()<<std::endl;	
		}
		
		std::cout<<std::endl;
		for(typename std::vector<Data*>::const_iterator it=_Map.begin();it!=_Map.end();){
		
			for(typename std::deque<Data*>::iterator ito=v.begin();ito!=v.end();){
				if((**ito).getX()==(**it).getX()){
					flag=1;
					
				}
				ito++;
			}

			if((**it).getPoint().getX()==_start.getPoint().getX() && (**it).getPoint().getY()==_start.getPoint().getY()){
				std::cout<<"R ";
			}
			else if((**it).getPoint().getX()==_end.getPoint().getX() && (**it).getPoint().getY()==_end.getPoint().getY()){
				std::cout<<"E ";
			}
			else if(flag==1){
				std::cout<<"9 ";
			}
			else if((**it).isWalkable()==true){
				std::cout<<"0 ";
			}
			else{
				std::cout<<"1 ";
			}
			j++;
			it++;
			flag=0;
			if(j>_length-1){
				std::cout<< " Changement" << j << std::endl;
				j=0;
			}
		}
	}
	
	void affiche() const {
		std::cout << "length " << _length << " start ";
		_start.affiche();
		std::cout << " at x : " <<  _start.getX()<< std::endl;
		std::cout<< "end";
		_end.affiche();
		std::cout << " at x : " <<  _end.getX()<< std::endl;
	}
	
	void affiche_Verbose(){
		std::cout << "closed list" <<std::endl;
		afficheClist();
		std::cout<<"open list "<<std::endl;
		afficheOlist();
		std::cout << "closed list small version" <<std::endl;
		afficheClistsmall();
		std::cout <<"open list small version"<<std::endl;
		afficheOlistsmall();
	}
	
	void affichePath() const{
		
		Data* ros=_ClosedList[0];
		if(!_ClosedList.empty()){
			while(ros->getParent()!=NULL){
				std::cout <<"x : "<<ros->getPoint().getX()<<" y : "<<ros->getPoint().getY()<<std::endl;
				ros=ros->getParent();
			}
			std::cout <<"x : "<<ros->getPoint().getX()<<" y : "<<ros->getPoint().getY()<<std::endl;	
		}		
	}
		

	void eraseM(){
		for(typename std::vector<Data*>::iterator it=_Map.begin();it!=_Map.end();){
			delete(*it);
			_Map.erase(it);
		}
		_OpenList.clear(); //Remet la taille des vecteur à zéro
		_ClosedList.clear();
	}
		
		
};



#endif

