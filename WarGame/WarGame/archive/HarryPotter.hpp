/****************************************************
** Program Filename: HarryPotter.hpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .hpp file declares the
** behavior and variables of the HarryPotter sub-class.
** Input:
** Output: Attack or Defense values to be transferred
** to Universe
******************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP


#include <iostream>
#include <string>

#include"Creatures.hpp"

using namespace std;

class HarryPotter :public Creatures
{
public:
	/* Constructor is in implementation file */
	HarryPotter();
	~HarryPotter(){};  
	/*Function Sets the number of die.*/
	void set_numDie(int num){ numAttackDie = num; };				
	/* Sets the name of Harry Potter */
	void set_Name(string inputName){ name = inputName; };
	/* (Virtual Function) Sets the value of Death Counter */
	void set_DeathCnt(int deathCnt){ HPdeathCnt = deathCnt; };
	/* (Virtual Function) Gets the value of Death Counter */
	int get_DeathCnt(){ return HPdeathCnt; };

	/* Pure Virtual Functions */
	string get_Name(){ return name; };	/* Gets the name Harry Potter */					
	int get_Armor(){ return armorVal; };	/* Gets the amount of ARMOR */					


private:
	string name;
	int HPdeathCnt; /* Counts number of deaths */
	int armorVal;


};
#endif
