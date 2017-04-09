/*****************************************************
** Program Filename: Universe.cpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .cpp file defines universe in
** which the creatures battle.
** Input: 2 Creatures are Created and Destroyed.
** Output: 1 Creature is output to main as the Winner.
******************************************************/

#include<iostream>
#include<string>
#include<time.h>
#include<cstdlib>

#include"Universe.hpp"
#include"Creatures.hpp"
#include"Barbarian.hpp"
#include"BlueMen.hpp"
#include"HarryPotter.hpp"
#include"Medusa.hpp"
#include"Vampire.hpp"
#include"utilities.hpp"
#include"WarriorQInterface.hpp"

using namespace std;

/**********************************************************
** Function: int Universe::Universe()
** Description: Constructor for Universe class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Initialize two combatants and engage them in
** battle.
** Return: This is a constructor. No value returned.
**********************************************************/
Universe::Universe()
{
	creaturesInUniv = 5;
	combatWins1 = 0;
	combatWins2 = 0;
	std::string *combatCreatures;
}


/**********************************************************
** Function: int Universe::~Universe()
** Description: Destructor for Universe class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Cleans class of dynamically allocated 
** memory.
** Return: This is a constructor. No value returned.
**********************************************************/
Universe::~Universe()
{
	delete Combatant1;
	delete Combatant2;

//	Combatant1 = NULL;
//	Combatant2 = NULL;
}


/**********************************************************
** Function: int Universe::SelectCombatants()
** Description: Function allows user to identify the two
** creatures who will engage in battle. 
** Parameters: None
** Pre-Conditions: No Combatants in the Universe. 
** Post-Conditions: Initialize two creatures who with Battle
** to the death.
** Return: Void function instantiates the combatants. 
**********************************************************/
void Universe::SelectCombatants()
{
	int sel1;
	int sel2;

	/* Create Array to be used as the source for the items listed in the
	** menu. */


	std::string *combatCreatures;		/* PROGRAMMERS NOTE: Possibly delete */
	combatCreatures = new std::string[creaturesInUniv];		

	/* Add creature names to Array. */
	combatCreatures[0] = "Vampire";
	combatCreatures[1] = "Barbarian";
	combatCreatures[2] = "Blue Men";
	combatCreatures[3] = "Medusa";
	combatCreatures[4] = "Harry Potter";

	/* Introduction to Game */
	cout << "\n\nWelcome to the Universe of Fantasy Combat! " << endl;
	cout << "Please select your Creatures to Battle.\n" << endl;

	/* Print menu of items and ask for user to enter first selection. */
	sel1 = optionsMenu(5, combatCreatures);

	/* Selection for second creature must be put through two input validations
	** sel1 goes through these input validations inherinately as part of the 
	** optionsMenu(int, string*) function */
	sel2 = get_int(1, "\nPlease enter your second creature: ");
	cin.ignore();
	sel2 = checkMenuInput(sel2, creaturesInUniv);


	/* Logic to instantiate Combatant1 to as the appropriate object */

	switch (sel1){

		case 1:
		{
			/* Logic for Vampire */
			Combatant1 = new Vampire();
		}
			break;
		case 2:
		{
			Combatant1 = new Barbarian();
		}
			break;
		case 3:
		{
			// Logic for Blue Men
			Combatant1 = new BlueMen();
		}
			break;
		case 4:
		{
			// Logic for Medusa
			Combatant1 = new Medusa();
		}
			break;
		case 5:
		{
			Combatant1 = new HarryPotter();
		}

	}

	/* Logic to instantiate Combatant2 to as the appropriate object */
	switch (sel2){

		case 1:
		{
			/* Logic for Vampire */
			Combatant2 = new Vampire();
		}
			break;
		case 2:
		{
			/* Logic for Barbarian */
			Combatant2 = new Barbarian();
		}
			break;
		case 3:
		{
			/* Logic for Blue Men */
			Combatant2 = new BlueMen();
		}
			break;
		case 4:
		{
			/* Logic for Medusa */
			Combatant2 = new Medusa();
		}
			break;
		case 5:
		{
			/* Logic for Harry Potter */
			Combatant2 = new HarryPotter();
		}

	}



	delete[]combatCreatures;
	combatCreatures = NULL;
}


/**********************************************************
** Function: int Universe::EngageInBattle()
** Description: Function executes logic for two
** creatures to engage in battle.
** Parameters: None
** Pre-Conditions: Two Creatures, 100% Strength
** Post-Conditions: Death and demoralization of one of the
** two Creatures and Praise to the WINNER.
** Return: Return String: Name of the Winning Creature.
**********************************************************/
string Universe::EngageInBattle()
{
	std::string winner;
	
/* Step 1: Basic Battle logic */

	/* Logic of Battle Control: Fight until one of two opponents has 0 strength */
	
	/* Gets Starting Values of Creatures Strength */
	int strengthOp1 = Combatant1->get_Strength();
	int strengthOp2 = Combatant2->get_Strength();
	
	/* Defines the Automatic Win of the Medusa Glare to false */
	bool MedusaAutoWin = false;
	
	/* Continue Fighting until condition of one Creatures Strenght is 0 or less */
	while (strengthOp1 > 0 && strengthOp2 > 0)
	{
		int attacker = rand() % 2 + 1;
		string nameAttacker = "";
		string nameDefender = "";
		int sizeAttack = 0;
		bool runStandard = true;
		

		if (attacker == 1)
		{
			nameAttacker = Combatant1->get_Name();
			nameDefender = Combatant2->get_Name();
		}
		else
		{
			nameAttacker = Combatant2->get_Name();
			nameDefender = Combatant1->get_Name();	
		}

		/* Logic of Vampire to only be attacked 50% of time */
		if (nameDefender == "Vampire")
		{
			/* Generates Random Value between 1 and 2 */
			int randomVal = rand() % 2 + 1; 
			if (randomVal == 1)
				runStandard = true;
			else
				runStandard = false; /* indicates vampire charmed his way 
									 ** out of attack.*/
		}
		

		if (runStandard) /* Ran if Vampire is defender and did not charm */
		{				 /* his way out of an Attack. */
		
			if (attacker == 1)
			{

				cout << "\nOpponent 1: " << nameAttacker << " has attacked Opponent 2: " << Combatant2->get_Name() << "\n" << endl;
				/* Combatant 1: Attack */
				int comb1Attack = Combatant1->Attack();
				sizeAttack = comb1Attack;

				int comb2Defense = 0;

				if (nameAttacker == "Medusa" && sizeAttack == 12)
				{
					comb2Defense = 0;
				}
				else{
					/* Combatant 2: Defense */
					int comb2Defense = Combatant2->Defend(comb1Attack);
				}
				/* Calculation of Damage to Combatant2*/

				/* Logic for applying standard Attack and defense of two Creatures */

			}
			else
			{
				nameAttacker = Combatant2->get_Name();
				cout << "\nOpponent 2: " << nameAttacker << " has attacked Opponent 1: " << Combatant1->get_Name() << "\n" << endl;

				/* Combatant 1: Attack */
				int comb2Attack = Combatant2->Attack();
				sizeAttack = comb2Attack;

				int comb1Defense = 0;

				if (nameAttacker == "Medusa" && sizeAttack == 12)
				{
					comb1Defense = 0;
				}
				else{
					/* Combatant 2: Defense */
					comb1Defense = Combatant1->Defend(comb2Attack);
				}
			}

			if (nameAttacker == "Medusa" && sizeAttack == 12)
			{
				/* Defines the Automatic Win of the Medusa Glare to false */
				MedusaAutoWin = true;


				/* Both Strength's Set to 0 to escape the Loop. */
				strengthOp1 = 0;
				strengthOp2 = 0;
			}
			else
			{
				strengthOp1 = Combatant1->get_Strength();
				strengthOp2 = Combatant2->get_Strength();

				/* Output specified data after each iteration. */
				cout << "\n\n  Status of Opponent 1:" << Combatant1->get_Name() << endl;
				cout << "Current Strength: " << strengthOp1 << endl;
				cout << "Current Number of Die: " << Combatant1->get_Die() << "\n" << endl;



				cout << "\n\n  Status of Opponent 2:" << Combatant2->get_Name() << endl;
				cout << "Current Strength: " << strengthOp2 << endl;
				cout << "Current Number of Die: " << Combatant2->get_Die() << "\n" << endl;
			
			}
		}
		else
		{
			if (attacker == 1)
				int defense = Combatant2->Defend();
			else
				int defense = Combatant1->Defend();
		}
		cin.get();
	}

	if (MedusaAutoWin)
		winner = "\nMedusa has used her Glare. Her Opponent has turned to Stone.\n\n\n Meduse has Automatically Won this Battle!";
	else if (strengthOp2 <= 0 && strengthOp1 <= 0)
		winner = "Battle is a DRAW!";
	else if (strengthOp2 <= 0)
		winner = "Opponent 1: " + Combatant1->get_Name() + " is the WINNER of this Battle!";
	else if (strengthOp1 <= 0)
		winner = "Opponent 2: " + Combatant2->get_Name() + " is the WINNER of this Battle!";


	return winner;
}

/**********************************************************
** Function: int Universe::EngageInTotalWar()
** Description: Function executes logic for allow two player
** to select a team of Creatures (Warriors) to engage in battle
** with the Warrior Line-up of the other team.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Death of all Warriors on one or both of the
** teams. A score for both teams based on battles. Two Warrior
** Line-up Queues (min of one being empty) and a Loser Stack
** containing all of the Warriors who died in battle. 
** Return: Return String: Name of the Winning Team.
**********************************************************/
string Universe::EngageInTotalWar()
{
	string winningTeam = "NONE";

	std::string *combatCreatures;		/* PROGRAMMERS NOTE: Possibly delete */
	combatCreatures = new std::string[creaturesInUniv];

	/* Add creature names to Array. */
	combatCreatures[0] = "Vampire";
	combatCreatures[1] = "Barbarian";
	combatCreatures[2] = "Blue Men";
	combatCreatures[3] = "Medusa";
	combatCreatures[4] = "Harry Potter";

	/* Variables to be assigned to teams */
	string name1;
	string name2;

	cout << "Welcome to Total War! \n\n" << endl;
	cout << "There are two teams that will be engaging in war during this game..." << endl;
	cout << "Please provide the name of Team 1: ";
	cin >> name1;
	cin.ignore();
	cout << "\n\nPlease provide the name of Team 2: ";
	cin >> name2;
	cin.ignore();

	/* Instantiate Two Seperate Teams and Allow User to assign a Team Name */
	WarriorQInterface teamOne(name1);
	teamOne.buildWarriorQueue(combatCreatures, 5);

	WarriorQInterface teamTwo(name2);
	teamTwo.buildWarriorQueue(combatCreatures, 5);

	cout << "\n\n" << teamOne.get_teamName() << endl;
	cout << teamTwo.get_teamName() << endl;


	delete[]combatCreatures;
	combatCreatures = NULL;

	return winningTeam;
}

