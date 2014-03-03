#include "Environnement.hpp"

void Environnement::create(std::vector<Obstacle*>& obs, std::vector<Robot*>& rob){




}

void Environnement::create(){
	std::cout<<"CREATION"<<std::endl;
	
	Point<float> p;
	bool b;
	std::vector<Data*> deck;
	
	//clear if previous
	eraseRobots();
	eraseObstacles();

	
	
	//Creation du robot

	_rob.push_back(new Robot(_map.getDim(), _map.getDimW(), _map.getStart()));

	
	for(size_t i =0;i<_map.getMap().size();i++){
		_map.vec2real(i,p);
		if(_map.get(i)==1){		
			std::cout<<"BOU "<<i<<std::endl;
			//Put the obstacles in the list
			_obs.push_back(new Obstacle(1, p));//Crer des carrés
			b=false;
			//push on the map now
		}
		else{
			b=true;
		}
		//push in the map for the Astar
		
		deck.push_back(new Data(i,_map.getLength(),b));	
	}
	std::cout << "Taille "<<_obs.size()<<std::endl;
	
	//initAstar
	Data d_start(_map.real2vec(_map.getStart()), _map.getLength(), false);
	_astar.setStart(d_start);
	
	Data d_end(_map.real2vec(_map.getEnd()), _map.getLength(), true);
	_astar.setEnd(d_end);
	
	_astar.setMap(deck, _map.getLength(), _map.getWidth());
	
		std::cout<<"LFHSEKJHJDLHFKDHFLKSsdfFDDFSDFDSFDSFSDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
	_astar.affichePath();
	
}


void Environnement::path(){




}


void Environnement::smooth(){




}
