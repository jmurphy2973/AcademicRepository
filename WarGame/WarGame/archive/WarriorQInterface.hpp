/*****************************************************
** Program Filename: WarriorQInterface.hpp
** Author: John J. Murphy
** Date: 11/17/2016
** Description: This is .hpp file declares the variables
** and behaviors of the WarriorQInterface and how the
** Fantasy War Game interacts with the Data Structure.
** Input:
** Output:
******************************************************/
#ifndef WARRIORQINTERFACE_HPP
#define WARRIORQINTERFACE_HPP

#include<iostream>
#include<cstdlib>
#include<string>
#include"WarriorQueueNode.hpp"

using namespace std;

class WarriorQInterface
{
private:
	//std::string *creaturesInUniverse;
	//Creatures *Warrior;
	string teamName;

protected:
	WarriorQueueNode *phead;
	WarriorQueueNode *ptail;
	WarriorQueueNode *n;

	Creatures *Warrior;

public:
	WarriorQInterface(string);
	~WarriorQInterface();
	void buildWarriorQueue(string*, int);
	void push(Creatures*);
	void closeList(Creatures*); /* PROGRAMMERS NOTE: May need to edit to make more versitile - Called on last entry by user */
	Creatures* pop();
	WarriorQueueNode get_head() { return *phead; };
	WarriorQueueNode get_tail() { return *ptail; };
	void PrintFrontToBack(WarriorQueueNode* head); /* For Testing */
	void PrintBackToFront(WarriorQueueNode* tail); /* For Testing */

	string get_teamName(){ return teamName; };
	void set_teamName(string inputName){ teamName = inputName; };
};
#endif