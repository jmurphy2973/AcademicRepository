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
	startStrength = 10;

	/* Initialize Variables unique to Class */
	name = "Harry Potter";
	armorVal = 0;


	/* Test cout statement */
	//cout << "You have instantiated variable as a " << name << endl;
}



/**********************************************************
** Function: int HarryPotter::restore_Strength()
** Description: Updates the strength of the winning creature.
** Parameters:None
** Pre-Conditions: Some strength between 1 - 100% of the
** creatures initial strength before battle.
** Post-Conditions: Dice rolled and output of defense.
** Return: Integer representing strength of defense.
**********************************************************/
void HarryPotter::restore_Strength()
{
	int startingStrength;
	if (this->get_DeathCnt() == 0)
	{
		startingStrength = 10;
	}
	else
	{
		startingStrength = 20;
	}

	int curStrength = this->get_Strength();

	int strAvaToRest = startingStrength - curStrength;

	/* Generate Random Percentage of missing strength to be restored */
	double randPerc = rand() % 100 + 1;
	double randRatio = randPerc / 100;

	double str2Restore = randRatio * strAvaToRest;
	int strRestRound = round(str2Restore);

	int newStrength = curStrength + strRestRound;
	this->set_Strength(newStrength);

}