/*****************************************************
** Program Filename: Vampire.cpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .cpp file defines the
** behavior and variables of the Vampire Creatures
** Input:
** Outputs:
******************************************************/
#include <iostream>
#include <string>

#include "Creatures.hpp"
#include "Vampire.hpp"



/**********************************************************
** Function: int Vampire::Vampire()
** Description: Constructor for creatures class
** Parameters:
** Pre-Conditions: Attack = 0; Defense = 0
** Post-Conditions: Initialize variables of object
** Return: This is a constructor. No value returned.
**********************************************************/
Vampire::Vampire()
{
	/* Initialize Variables */
	numAttackDie = 1;
	sizeAttackDie = 12;
	numDefDie = 1;
	sizeDefDie = 6;
	valCurStrength = 18;
	startStrength = 18;

	/* Initialize Variables unique to Class */
	name =  "Vampire";
	armorVal = 1;


	/* Test cout statement */
	//cout << "You have instantiated variable as a " << name << endl;
}


/**********************************************************
** Function: int Vampire::Defend()
** Description: Special defense function of an object in
** the Vampire Class.
** Parameters:
** Pre-Conditions: Un-rolled dice.
** Post-Conditions: Dice rolled and output of defense.
** Return: Integer representing strength of defense.
**********************************************************/
int Vampire::Defend()
{
	cout << "The Vampire has charmed his way out of being attacked!" << endl;
	cout << "The Battle Continues..." << endl;

	return 0;
}
