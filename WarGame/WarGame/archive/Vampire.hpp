/*****************************************************
** Program Filename: Vampire.hpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .hpp file declares the
** behavior and variables of the Vampire sub-class.
** Input:
** Output: Attack or Defense values to be transferred
** to Universe
******************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include <string>

#include"Creatures.hpp"

using namespace std;

class Vampire :public Creatures
{
public:
	/* Constructor of the Vampire Class */
	Vampire();
	~Vampire(){};
	/* Overloaded function to be called if Vampire Charms his 
	** way out of an Attack. Otherwise Creatures::Defend(int) 
	** is called*/
	int Defend();

	/*Function Sets the number of die.*/
	void set_numDie(int num){ numAttackDie = num; };
	/*Sets the name of the Vampire*/
	void set_Name(string inputName){ name = inputName; };

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
