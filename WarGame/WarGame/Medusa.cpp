/*****************************************************
** Program Filename: Medusa.cpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .cpp file defines the
** behavior and variables of the Medusa Creatures
** Input:
** Outputs:
******************************************************/
#include <iostream>
#include <string>

#include "Creatures.hpp"
#include "Medusa.hpp"



/**********************************************************
** Function: int Barbarian::HarryPotter()
** Description: Constructor for creatures class
** Parameters: Number of Die, Size of Die
** Pre-Conditions: Attack = 0; Defense = 0
** Post-Conditions: Initialize variables of object
** Return: This is a constructor. No value returned.
**********************************************************/
Medusa::Medusa()
{
	/* Initialize Variables */
	numAttackDie = 2;
	sizeAttackDie = 6;
	numDefDie = 1;
	sizeDefDie = 6;
	valCurStrength = 8;
	startStrength = 8;

	/* Initialize Variables unique to Class */
	name = "Medusa";
	armorVal = 3;


	/* Test cout statement */
	//cout << "You have instantiated variable as a " << name << endl;
}


/**********************************************************
** Function: int Medusa::Attack()
** Description: Specialized Medusa Attack function for object
** in this Derived Class. Specialize to include Glare Attack.
** Parameters: None
** Pre-Conditions: Attack = 0; Defense = 0
** Post-Conditions: Integer representing the Attack value
** Return: sumOfDie - Represents strength of Attack.
**********************************************************/

int Medusa::Attack()
{
	cout << " Status of Attack/Defense";
	//srand(time(NULL));
	int sumOfDie = 0;
	for (int i = 0; i < numAttackDie; i++)
	{
		int dieRole = rand() % sizeAttackDie + 1;
		sumOfDie += dieRole;
	}
	cout << endl;
	cout << "The attack of the " << this->get_Name() << " was " << sumOfDie << endl;

	if (sumOfDie == 12)
	{
		cout << "Medusa has turned the Defender to Stone and Automatically Wins!" << endl;
	}

	return sumOfDie;
}
