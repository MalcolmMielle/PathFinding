CPP=g++    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=`pkg-config --cflags --libs opencv` #Linker
BOOSTFLAG=-lboost_unit_test_framework

###########TEST UNITAIRES######################

ptt : ptt.o Astar.o
	${CPP} $(CFLAGS) -g -Wall -o ptt ptt.o Astar.o ${BOOSTFLAG}
	
envt : envt.o Astar.o Environnement.o
	${CPP} $(CFLAGS) -g -Wall -o envt envt.o Astar.o Environnement.o ${BOOSTFLAG}
	
map : map.o Astar.o
	${CPP} $(CFLAGS) -g -Wall -o map map.o Astar.o ${BOOSTFLAG}
	
robot : robottest.o Astar.o Environnement.o
	${CPP} $(CFLAGS) -g -Wall -o robot robottest.o Astar.o Environnement.o ${BOOSTFLAG}
	
map.o : maptest.cpp
	${CPP} $(CFLAGS) -g -Wall -o map.o -c maptest.cpp ${BOOSTFLAG}
	
ptt.o : test.cpp
	${CPP} $(CFLAGS) -g -Wall -o ptt.o -c test.cpp ${BOOSTFLAG}
	
envt.o : envt.cpp 
	${CPP} $(CFLAGS) -g -Wall -o envt.o -c envt.cpp ${BOOSTFLAG}
	
robottest.o : robottest.cpp
	${CPP} $(CFLAGS) -g -Wall -o robottest.o -c robottest.cpp ${BOOSTFLAG}
	
Astar.o : Astar.cpp
	${CPP} $(CFLAGS) -g -Wall -o Astar.o -c Astar.cpp ${BOOSTFLAG}
	
Environnement.o : Environnement.cpp
	${CPP} $(CFLAGS) -g -Wall -o Environnement.o -c Environnement.cpp ${BOOSTFLAG}




##################VARIABLES GLOBAL##########################"	
	
#Global.o : Global.cpp
#	${CPP} $(CFLAGS) -g -Wall -o Global.o -c Global.cpp ${LDFLAGS} ${BOOSTFLAG}	
	
clean:
	rm -f *.o
	rm -f *~
