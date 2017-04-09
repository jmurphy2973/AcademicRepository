/**********************************************************
** Program File: Creatures.cpp
** Author: John J. Murphy
** Date: 4 November 2016
** Description: This is the implementation file for the
** Creature parent class of this program.
** Input: Creature
** Output: Attack value of defend value based on functions 
** called. Also maintains health status.
**
** Creatures.cpp is the implementation.
**********************************************************/
#include<iostream>
#include<string>
#include"Creatures.hpp"
#include"HarryPotter.hpp"
#include"Medusa.hpp"
#include"Barbarian.hpp"

using namespace std;

/**********************************************************
** Function: Creatures::Creatures(int, int) 
** Description: Constructor for creatures class
** Parameters: Armor, Strength
** Pre-Conditions: Attack = 0; Defense = 0
** Post-Conditions: Initialize variables of object
** Return: This is a constructor. No value returned.
**********************************************************/
Creatures::Creatures()
{
	/* Initialize Strength and Damage */
	valCurStrength = 0;
	//damage = 0;
	
	/* Initialize Creatures Die */
	numAttackDie = 0;
	sizeAttackDie = 0;
	numDefDie = 0;
	sizeDefDie = 0;
}


/**********************************************************
** Function: int Creatures::Attack()
** Description: Standard Attack function of an object in 
** the Creature Super-class. 
** Parameters: None
** Pre-Conditions: Attack = 0; Defense = 0
** Post-Conditions: Integer representing the Attack value
** Return: sumOfDie - Represents strength of Attack. 
**********************************************************/

int Creatures::Attack()
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

	return sumOfDie;
}


/**********************************************************
** Function: int Creatures::Defend()
** Description: Standard defense function of an object in
** the Creature Class.
** Parameters: 
** Pre-Conditions: Un-rolled dice. 
** Post-Conditions: Dice rolled and output of defense.
** Return: Integer representing strength of defense.
**********************************************************/

int Creatures::Defend(int inflicted)
{
	//srand(time(NULL));
	/* sumOfDie Logic is of the Defense value of the Creature */
	int sumOfDie = 0;
	for (int i = 0; i < numDefDie; i++)
	{
		int dieRole = rand() % sizeDefDie + 1;
		sumOfDie += dieRole;
	}

	/* Defence Role Output */
	cout << "The Defense of " << this->get_Name() << " was: " << sumOfDie << endl;

	/* inflicted variable is the value of the Attack from the Opponent */
	int valDamage = inflicted - sumOfDie;
	cout << endl;
	//cout << "The Damage was " << valDamage << " not including the armor of the Creature. \n"<< endl;

	UpdateStrength(valDamage);
	return valDamage;
}

/**********************************************************
** Function: int Creatures::UpdateStrength()
** Description: Updates the strength of the Creature who was 
** Attacked. This is called in the Defend(int) Function.
** Parameters:int damageByAttack (this is calc. in the 
** Defend(int) function.
** Pre-Conditions: Un-rolled dice.
** Post-Conditions: Dice rolled and output of defense.
** Return: Integer representing strength of defense.
**********************************************************/
void Creatures::UpdateStrength(int damageByAttack)
{
	cout << " Status of Defenders Damage/Strength " << endl;
	cout << "Starting Strength was: " << valCurStrength << ". " << endl;

	int valOfUpdate = damageByAttack - this->get_Armor();

	/* Output Status of Damage, Armor and total Damage inflicted */
	cout << "Damage to Defender: " << damageByAttack << endl;
	cout << "Armor of Defender:  " << this->get_Armor() << endl;
	cout << "Damage with Armor: " << valOfUpdate << "\n" <<endl;

	/* If statement to Control current strength to not allow it to Increase. */
	if (valOfUpdate <= 0)
	{
		cout << "No Damage was taken by Defender since defender " << endl;
		cout << "completely defended the attack!! " << endl;
		valCurStrength = valCurStrength;
		cout << "Strength remains: " << valCurStrength << endl;
	}
	else /* Reduces strength base on the attack size and the defenders Armor */
	{
		valCurStrength -= valOfUpdate;
		cout << "Strength of was updated to: " << valCurStrength << endl;
	}

	if (this->get_Name() == "Blue Men")
	{
		this->dieChange(valCurStrength);
	}
	else if (this->get_Name() == "Harry Potter")
	{
		int numDeaths = this->get_DeathCnt();
		if (valCurStrength <= 0 && numDeaths == 0)
		{
			/* */
			valCurStrength = 20;
			this->set_DeathCnt(1);

			cout << "\n\nHarry Potter Has die and come back to life with his strength reset to 20. " << endl;
			cout << "Harry's Current Death count is at " << this->get_DeathCnt() << " he has 0 lives remaining.\n" << endl;

		}
	}

}
