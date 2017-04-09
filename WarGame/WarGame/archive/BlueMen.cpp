/*****************************
** Program Filename : BlueMen.cpp
** Author : John J.Murphy
** Date : 11 / 4 / 2016
* * Description : This is.cpp file defines the
** behavior and variables of the Blue Men Creatures
** Input :
******************************************************/
#include <iostream>
#include <string>

#include "Creatures.hpp"
#include "BlueMen.hpp"

/**********************************************************
** Function: int BlueMen::BlueMen()
** Description: Constructor for creatures class
** Parameters: Number of Die, Size of Die
** Pre-Conditions: Attack = 0; Defense = 0
** Post-Conditions: Initialize variables of object
** Return: This is a constructor. No value returned.
**********************************************************/
BlueMen::BlueMen()
{
	/* Initialize Variables */

	numAttackDie = 2;
	sizeAttackDie = 10;
	numDefDie = 3;
	sizeDefDie = 6;
	valCurStrength = 12;

	/* Initialize Variables unique to Class */
	name = "Blue Men";
	armorVal = 3;
	

	/* Test cout statement */
	//cout << "You have instantiated variable as a " << name << endl;
}


/**********************************************************
** Function: void BlueMen::DieChange(int strength)
** Description: Unique Funtion for BlueMen Class called 
** each time the strength is updated. 
** Parameters: int strength
** Pre-Conditions: Strength, Old numDefDie
** Post-Conditions: Strength, New numDefDie
** Return: void
**********************************************************/
void BlueMen::dieChange(int strength)
{
	if (strength == 12)
	{
		numDefDie = 3;
		cout << "Number of die for Blue Men Defender remains: " << numDefDie << endl;
	}
	else if (strength < 12 && strength >= 8)
	{
		numDefDie = 2;
		cout << "Number of die for Blue Men Defender was reduced to: " << numDefDie << endl;
	}
	else if (strength < 8 && strength >= 4)
	{
		numDefDie = 1;
		cout << "Number of die for Blue Men Defender was reduced to: " << numDefDie << endl;
	}
	else
		numDefDie = 0;	/* Defender is dead at this point anyway *
						** No output required for else statement
						** due to the looming death of the Blue
						** Men. */
}
