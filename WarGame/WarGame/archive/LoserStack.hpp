/*****************************************************
** Program Filename: LoserStackNode.hpp
** Author: John J. Murphy
** Date: 11/16/2016
** Description: This is .hpp file declares the variables
** contained in the LoserStack struct. This Stack
** manages the line-ups for each team.
** Input:
** Output:
******************************************************/
#ifndef LOSERSTACKNODE_HPP
#define LOSERSTACKNODE_HPP

#include<iostream>
#include<cstdlib>
#include"Creatures.hpp"

struct LoserStackNode {
	Creatures	*dataLoser;
	LoserStackNode* next;
	LoserStackNode* previous;
};
#endif
