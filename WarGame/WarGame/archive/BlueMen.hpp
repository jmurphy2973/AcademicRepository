/*****************************************************
** Program Filename: BlueMen.hpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .hpp file declares the
** behavior and variables of the BlueMen sub-class.
** Input:
** Output: Attack or Defense values to be transferred
** to Universe
******************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP


#include <iostream>
#include <string>

#include"Creatures.hpp"

using namespace std;

class BlueMen :public Creatures
{
public:
	BlueMen();  /* Constructor is in implementation file */
	~BlueMen(){}; 	
	/*Function Sets the number of die.*/
	void set_numDie(int num){ numAttackDie = num; };	

	/*Sets the name of the class object*/
	void set_Name(string inputName){ name = inputName; };	

	/*Changes Number of Die of object based on varCurStength*/
	void dieChange(int strength);							

	/* Pure Virtual Functions */
	string get_Name(){ return name; };		/* Gets the name */
	int get_Armor(){ return armorVal; };	/* Gets Armor value*/


private:
	string name;
	int armorVal;

};
#endif
