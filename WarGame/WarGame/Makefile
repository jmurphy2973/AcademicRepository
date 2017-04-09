# Author: John J. Murphy
# Date: 17 November 2016
# Description: This is the makefile for Assignment 4. WarGame


CXX = fantacymain.cpp 
 CXX += utilities.cpp 
 CXX += utilities.hpp  
 CXX += Universe.cpp
 CXX += Universe.hpp
 CXX += Creatures.cpp
 CXX += Creatures.hpp
 CXX += Barbarian.cpp
 CXX += Barbarian.hpp
 CXX += BlueMen.cpp
 CXX += BlueMen.hpp
 CXX += HarryPotter.cpp
 CXX += HarryPotter.hpp
 CXX += Medusa.cpp
 CXX += Medusa.hpp
 CXX += Vampire.cpp
 CXX += Vampire.hpp
 CXX += WarriorQueueNode.hpp
 CXX += WarriorQInterface.cpp
 CXX += WarriorQInterface.hpp
 CXX += LoserStackNode.hpp
 CXX += LoserStackInterface.cpp
 CXX += LoserStackInterface.hpp
               
CXXFLAGS = -std=c++0x

WarGame:
	g++ ${CXX} ${CXXFLAGS} -o WarGame

clean:
	rm *.o WarGame
