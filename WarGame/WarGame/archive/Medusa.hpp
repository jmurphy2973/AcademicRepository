/*****************************************************
** Program Filename: Medusa.hpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .hpp file declares the
** behavior and variables of the Medusa sub-class.
** Input:
** Output: Attack or Defense values to be transferred
** to Universe
******************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP


#include <iostream>
#include <string>

#include"Creatures.hpp"

using namespace std;

class Medusa :public Creatures
{
public:
	/* Constructor of the Medusa Class */
	Medusa();
	~Medusa(){};
	/*Function Sets the number of die.*/
	void set_numDie(int num){ numAttackDie = num; };
	/*Sets the name of the Barbarian*/
	void set_Name(string inputName){ name = inputName; };
	int Attack();

	/* Pure Virtual Functions */
	/* Gets the name of Creature */
	string get_Name(){ return name; };
	/* Gets the amount of ARMOR */
	int get_Armor(){ return armorVal; };


private:
	string name;
	int armorVal;


};
#endif
