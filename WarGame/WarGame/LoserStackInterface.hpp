/*****************************************************
** Program Filename: singleLinkStackInt.hpp
** Author: John J. Murphy
** Date: 11/6/2016
** Description: This is .hpp file declares the variables
** and behaviors of the singleLinkStack and how it
** interacts with the member linked list stuctures.
** Input:
** Output:
******************************************************/
#ifndef LOSERSTACKINTERFACE_HPP
#define LOSERSTACKINTERFACE_HPP

#include<iostream>
#include<cstdlib>
#include<string>
#include"LoserStackNode.hpp"

using namespace std;

class LoserStackInterface
{
protected:
	LoserStackNode *phead;
	LoserStackNode *n;

public:
	LoserStackInterface();
	~LoserStackInterface();
	void runStacknode();
	void push(Creatures*);
	
	/* Pop function is not required for implementation of Loser Stack */
	//int pop();
	
	LoserStackNode get_phead(){ return *phead; };
	void PrintFrontToBack(LoserStackNode*); /* For Testing */
};
#endif