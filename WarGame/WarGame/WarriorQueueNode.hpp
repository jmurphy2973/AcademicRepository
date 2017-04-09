/*****************************************************
** Program Filename: WarriorQueueNode.hpp
** Author: John J. Murphy
** Date: 11/16/2016
** Description: This is .hpp file declares the variables
** contained in the WarriorQueueNode struct. This Queue 
** manages the line-ups for each team. 
** Input:
** Output:
******************************************************/
#ifndef WARRIORQUEUENODE_HPP
#define WARRIORQUEUENODE_HPP

#include<iostream>
#include<cstdlib>
#include"Creatures.hpp"

struct WarriorQueueNode{
	Creatures	*dataWarrior;
	WarriorQueueNode* next;
	WarriorQueueNode* previous;
};
#endif