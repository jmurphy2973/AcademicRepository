/*****************************************************
** Program Filename: HarryPotter.cpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .cpp file defines the
** behavior and variables of the HarryPotter as a
** Creature.
** Input:
** Outputs:
******************************************************/
#include <iostream>
#include <string>

#include "Creatures.hpp"
#include "HarryPotter.hpp"



/**********************************************************
** Function: int HarryPotter::HarryPotter()
** Description: Constructor for creatures class
** Parameters: Number of Die, Size of Die
** Pre-Conditions: Attack = 0; Defense = 0
** Post-Conditions: Initialize variables of object
** Return: This is a constructor. No value returned.
**********************************************************/
HarryPotter::HarryPotter()
{
	/* Initialize Variables */
	HPdeathCnt = 0;
	numAttackDie = 2;
	sizeAttackDie = 6;
	numDefDie = 2;
	sizeDefDie = 6;
	valCurStrength = 10;  /* Will change to 20 on 1st death. */
	

	/* Initialize Variables unique to Class */
	name = "Harry Potter";
	armorVal = 0;


	/* Test cout statement */
	//cout << "You have instantiated variable as a " << name << endl;
}
