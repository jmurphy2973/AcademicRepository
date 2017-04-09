/*****************************************************
** Program Filename: Barbarian.cpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .cpp file defines the 
** behavior and variables of the Barbarian Creatures
** Input: 
** Outputs:
******************************************************/
#include <iostream>
#include <string>

#include "Creatures.hpp"
#include "Barbarian.hpp"



/**********************************************************
** Function: int Barbarian::Barbarian()
** Description: Constructor for creatures class
** Parameters: Number of Die, Size of Die
** Pre-Conditions: Attack = 0; Defense = 0
** Post-Conditions: Initialize variables of object
** Return: This is a constructor. No value returned.
**********************************************************/
Barbarian::Barbarian()
{
	/* Initialize Variables */
	numAttackDie = 2;
	sizeAttackDie = 6;
	numDefDie = 2;
	sizeDefDie = 6;
	valCurStrength = 12;

	/* Initialize Variables unique to Class */
	name = "Barbarian";
	armorVal = 0;


	/* Test cout statement */
	//cout << "You have instantiated variable as a " << name << endl;
}
