#include "Astar.hpp"

	
void Astar::quickSort(int left, int right){
	int i = left, j = right;
	Data* tmp;
	Data* pivot = _OpenList[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (_OpenList[i]->getF() < pivot->getF())
		 	 i++;
		while (_OpenList[j]->getF() > pivot->getF())
		 	 j--;
		if (i <= j) {
			  tmp = _OpenList[i];
			  _OpenList[i] = _OpenList[j];
			  _OpenList[j] = tmp;
			  i++;
			  j--;
		}
	};
	/* recursion */
	if (left < j)
	quickSort(left, j);
	if (i < right)
	quickSort(i, right);
}


void Astar::cleanOlist(){
	int size=_OpenList.size();
	(*this).quickSort(0,size-1);
}


void Astar::findUpdateAdjacent(){
	//Les point current sont xcur+1, xcur-1, xcur+length(+-1), xcur-length(+-1)
	
	
	std::cout<<_Map[_xcur]->getPoint().getX() << " " << _Map[_xcur]->getPoint().getY()<<std::endl;
	//std::cout<<"Googoogoog..."<<std::endl;
	for(int i=-1;i!=2;i++){
		for(int j=-1;j!=2;j++){
			//std::cout<<std::endl<<"on est a "<<_xcur+(i*_length)+j<< "avec "<< _Map[_xcur]->getPoint().getX()+j << " leng "<<  _length <<" avec "<<_Map[_xcur]->getPoint().getY()+i << " width " << _width<<std::endl;		
			
			if(_Map[_xcur]->getPoint().getY()+i<0 || _Map[_xcur]->getPoint().getY()+i>=_width || _Map[_xcur]->getPoint().getX()+j>=_length || _Map[_xcur]->getPoint().getX()+j<0){
				//std::cout<<"Out of boundery in searching the adjacent. Going to the next point"<<std::endl;

			}
			else if(i==0 && j==0){
				//std::cout<<"The point itself"<<std::endl;
			}
			
			else if(_Map[_xcur+(i*_length)+j]->isWalkable()==true){
				//std::cout<<"Gotcha..."<<" "<< i <<" "<< j<<std::endl;
							
				if(_Map[_xcur+(i*_length)+j]->isClist()==false){
					//std::cout<<" not in closed list ";
					//if not in the open list
					if( _Map[_xcur+(i*_length)+j]->isOlist()==false){	
						//std::cout << " not in open loop" <<std::endl;				
						
						//move to OpenList
						(*this).addO(_Map[_xcur+(i*_length)+j] , i, j);
						
						//Check if directly at the good place.
						if(_OpenList.size()>1){
							if(_OpenList[0]->getF()>_OpenList[1]->getF()){
								_newclean=1;
							}
						}																	
					}
					//if on the open list
					else{
						int h;
						if(i==0||j==0){
							h=10;
						}
						else{
							h=14;
						}
						//Check if the new path is better using G cost
						/************************************************************NEED BETTER*/
						if(_Map[_xcur+(i*_length)+j]->getG() > _Map[_xcur]->getG()+h){
						
							_Map[_xcur+(i*_length)+j]->setParent(_Map[_xcur]);
							
							_Map[_xcur+(i*_length)+j]->setG(_Map[_xcur]->getG()+h);
							
							_newclean=1; //resort forced of the open list
						}
					}
				}
			}
		}
	}
	//Do resort the OpenList if needed
	if(_newclean==1){
		(*this).cleanOlist();
		_newclean=0;
	}
	
}


void Astar::addO(Data* d, int i, int j){
	//Mise à jour de G
	if(i==0||j==0){
		d->setG(_Map[_xcur]->getG()+10);
	}
	else{
		d->setG(_Map[_xcur]->getG()+14);
	}
	//Point<float>* p=realPosition(d);
	d->setH(heuristic(d->getPoint()));
	d->setF();
	d->setOlist(); //flag to open list
	d->setParent(_Map[_xcur]); //Set the current point as the parent for the openlist point	
	_OpenList.push_front(d);
}
	
float Astar::heuristic(const Point<float>& p1) const {
	//std::cout<<"Heuri "<<(((_end.getPoint().getX()-p1.getX())*(_end.getPoint().getX()-p1.getX()))) +((_end.getPoint().getY()-p1.getY())*(_end.getPoint().getY()-p1.getY()))<<std::endl;
	return 10*sqrt( (((_end.getPoint().getX()-p1.getX())*(_end.getPoint().getX()-p1.getX()))) +((_end.getPoint().getY()-p1.getY())*(_end.getPoint().getY()-p1.getY())) ); 
}
	
	
	
	
//THE REAL DEAL
	
void Astar::pathFinding(){
	//std::cout<<"GOOOOOOO Pathfind me!"<<std::endl;
	//First add start in the closed list
	//Initialise start
	_xcur=_start.getX();
	//move the start in the closed list
	addC(_Map[_start.getX()]);//Point de départ est mis dans la liste fermée
	
	/*Affiche pour vérifier*/
	affiche_Verbose();
	//On travaille sur le point de départ
	
	findUpdateAdjacent();
	//On l'ajoute à la liste finale
	addC(_OpenList[0]);
	_xcur=_ClosedList[0]->getX();
	//_OpenList.pop_front();
	
	
	//
	
	while(_xcur!=_end.getX() && !_OpenList.empty()){
		//std::cout<<std::endl << "We are at "<< _xcur << std::endl;
		
		_OpenList.pop_front(); //On l'enlève de la liste ouverte
		
		if(!_OpenList.empty()){
			//std::cout<<"We are at : "<< _xcur<<std::endl;
			findUpdateAdjacent();
			
			//affiche_Verbose();
		
			addC(_OpenList[0]);	
			//updating current point
			_xcur=_ClosedList[0]->getX();
		}
		else{
			std::cout << "NO SOLUTION "<< std::endl;
		}	

		//affiche_Verbose();
		//scanf("%d",&i);
	}



}
