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
	std::string *combatCreatures = NULL;
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
	//cin.ignore();
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
** Function: int Universe::EngageInBattle(Creatures *Combatant1, Creatures *Combatant2) - Function was 
** modified from Assignment 3 to accept arguments
** Description: Function executes logic for two
** creatures to engage in battle.
** Parameters: Creatures *Combatant1, Creatures *Combatant2
** Pre-Conditions: Two Creatures, @Current Strength - Not
** necessarily 100%.
** Post-Conditions: Death and demoralization of one of the
** two Creatures and Praise to the WINNER.
** Return: Return String: Winning Creature
**********************************************************/
Creatures* Universe::EngageInBattle(Creatures *Combatant1, Creatures *Combatant2)
{
	int attacker;
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
		attacker = rand() % 2 + 1;
		
		string nameAttacker = "";
		string nameDefender = "";
		string indNameAttacker = "";
		string indNameDefender = "";

		int sizeAttack = 0;
		bool runStandard = true;
		

		if (attacker == 1)
		{
			nameAttacker = Combatant1->get_Name();
			nameDefender = Combatant2->get_Name();

			indNameAttacker = Combatant1->get_indivName();
			indNameDefender = Combatant2->get_indivName();
		}
		else
		{
			nameAttacker = Combatant2->get_Name();
			nameDefender = Combatant1->get_Name();	

			indNameAttacker = Combatant2->get_indivName();
			indNameDefender = Combatant1->get_indivName();
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

				//cout << "\nOpponent 1: " << nameAttacker << " has attacked Opponent 2: " << Combatant2->get_Name() << "\n" << endl;
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
				//cout << "\nOpponent 2: " << nameAttacker << " has attacked Opponent 1: " << Combatant1->get_Name() << "\n" << endl;

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
/*				cout << "\n\n  Status of Opponent 1:" << Combatant1->get_Name() << endl;
				cout << "Current Strength: " << strengthOp1 << endl;
				cout << "Current Number of Die: " << Combatant1->get_Die() << "\n" << endl;



				cout << "\n\n  Status of Opponent 2:" << Combatant2->get_Name() << endl;
				cout << "Current Strength: " << strengthOp2 << endl;
				cout << "Current Number of Die: " << Combatant2->get_Die() << "\n" << endl;*/
			
			}
		}
		else
		{
			if (attacker == 1)
				int defense = Combatant2->Defend();
			else
				int defense = Combatant1->Defend();
		}
		//cin.get();
	}

	/* Return Winning Creature: Will return to winner to Queue from EngageInWar Function 
	** Can push Loser to Loser Stack from EngageInBattle function. 
	** If result of Battle is a Draw. Both Creatures are killed and will be pushed to the Loser
	** pile. NULL will be returned to EngageInWar Function */

	if (MedusaAutoWin){
		cout << "\n\nMedusa has used her Glare. Her Opponent has turned to Stone.\n\n\n Meduse has Automatically Won this Battle!" << endl;
		if (attacker == 1){
			ListLosers.push(Combatant2);
			return Combatant1;
		}
		else
			return Combatant2;
	}
	else if (strengthOp2 <= 0 && strengthOp1 <= 0){
		ListLosers.push(Combatant1);
		ListLosers.push(Combatant2);
		cout << "\n\nBattle is a DRAW!" << endl;
		return NULL;
	}
	else if (strengthOp2 <= 0){
		cout << "\n\nOpponent 1: " + Combatant1->get_Name() + " is the WINNER of this Battle!" << endl;
		ListLosers.push(Combatant2);
		return Combatant1;
	}
	else if (strengthOp1 <= 0){
		cout << "\n\nOpponent 2: " + Combatant2->get_Name() + " is the WINNER of this Battle!" << endl;
		ListLosers.push(Combatant1);
		return Combatant2;
	}
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
	int scoreTeam1 = 0;
	int scoreTeam2 = 0; 

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
	getline(cin, name1);
	cin.ignore();
	cout << "\n\nPlease provide the name of Team 2: ";
	getline(cin, name2);
	cin.ignore();

	/* Instantiate Two Seperate Teams and Allow User to assign a Team Name */
	WarriorQInterface teamOne(name1);
	teamOne.buildWarriorQueue(combatCreatures, 5);

	WarriorQInterface teamTwo(name2);
	teamTwo.buildWarriorQueue(combatCreatures, 5);

	WarriorQueueNode team1Head = teamOne.get_head();
	WarriorQueueNode team2Head = teamTwo.get_head();

	WarriorQueueNode team1Tail = teamOne.get_tail();
	WarriorQueueNode team2Tail = teamTwo.get_tail();

	cout << "\n\nTeam " << teamOne.get_teamName() << " and Team " << teamTwo.get_teamName() << " will engage in Battle!\n" << endl;

	/* Print Team Line-Ups */
	cout << "\n\nTeam " << teamOne.get_teamName() << " Line-Up:\n" << endl;
	teamOne.PrintFrontToBack(&team1Head);
	

	cout << "\n\nTeam " << teamTwo.get_teamName() << " Line-Up:\n" << endl;
	teamTwo.PrintFrontToBack(&team2Head);


	/* War Logic */
	//Creatures *WarriorTeam1 = NULL;
	//Creatures *WarriorTeam2 = NULL;

	/* Battle Logic */
	bool contWar = true;
	Creatures *WarriorTeam1 = NULL;
	Creatures *WarriorTeam2 = NULL;
	string winner = "Draw";

	int size1 = -1;
	int size2 = -1;

	int cnt = 1;
	while (contWar)
	{
		size1 = teamOne.get_curSize();
		size2 = teamTwo.get_curSize();

		if (size1 == 0 || size2 == 0)
		{
			contWar = false;
		}
		else
		{
			WarriorTeam1 = teamOne.pop();
			WarriorTeam2 = teamTwo.pop();

			if (WarriorTeam1 != NULL || WarriorTeam2 != NULL)
			{
				Creatures* winner = EngageInBattle(WarriorTeam1, WarriorTeam2);

				if (winner != NULL){


					if (winner == WarriorTeam1){ 
						cout << "\nTeam "<< teamOne.get_teamName() <<" will be given 2 team pts" << endl;
						cout << "Winner of Round " << cnt << ": ";
						scoreTeam1 += 2; /* Add a value of 2 for Winning */
						scoreTeam2 -= 1; /* Subtract a value of 1 for losing */
						cin.ignore();
						cout << winner->get_Name() << "-" << winner->get_indivName() << endl;

						teamOne.add(winner);
						winner->restore_Strength();
					}
					else if (winner == WarriorTeam2){

						cout << "\nTeam " << teamTwo.get_teamName() << " will be given 2 team pts" << endl;
						cout << "Winner of Round " << cnt << ": ";
						scoreTeam2 += 2; /* Add a value of 2 for Winning */
						scoreTeam1 -= 1; /* Subtract a value of 1 for losing */
						cin.ignore();
						cout << winner->get_Name() << "-" << winner->get_indivName() << endl;


						teamTwo.add(winner);
						winner->restore_Strength();
					}
					else{
						cout << "NO POINTs ALLOCATED - Test: This should never display" << endl;
					}

				}
				else{
					cout << "Both Warriors have been killed and added to the loser pile. Both teams will lose 1 point." << endl;
					scoreTeam1 -= 1; /* Add a value of 2 for Winning */
					scoreTeam2 -= 1; /* Subtract a value of 1 for losing */
				}

				cin.get();
			}
			cin.get();
			contWar = true;
		}


		cnt++;
	}

	
	
	/* Print Team Line-Ups */

	if (teamOne.get_curSize() != 0)
	{
		cout << "\n\nTeam " << teamOne.get_teamName() << " Line-Up After War:" << endl;
		team1Head = teamOne.get_head();
		teamOne.PrintFrontToBack(&team1Head);
		cout << endl;
	}
	else
	{
		cout << "\n\nTeam " << teamOne.get_teamName() << " Line-Up After War:" << endl;
		cout << "All Team Players have been Killed!" << endl;
	}

	if (teamTwo.get_curSize() != 0)
	{
		cout << "\nTeam " << teamTwo.get_teamName() << " Line-Up After War:" << endl;
		team2Head = teamTwo.get_head();
		teamTwo.PrintFrontToBack(&team2Head);
		cout << "\n" << endl;
	}
	else
	{
		cout << "\nTeam " << teamTwo.get_teamName() << " Line-Up After War:" << endl;
		cout << "All Team Players have been Killed!\n" << endl;
	}




	/* Winner is purly based on highest scoring team */
	if (scoreTeam1 > scoreTeam2)
	{
		cout << "\n"<< teamOne.get_teamName() << " is the Winner of the War!" << endl;
		cout << "Score of Team " << teamOne.get_teamName() << ": "<< scoreTeam1 << endl;
		cout << "Score of Team " << teamTwo.get_teamName() << ": " << scoreTeam2 << endl;
	}
	else if (scoreTeam2 > scoreTeam1)
	{
		cout << "\n" << teamTwo.get_teamName() << " is the Winner of the War!" << endl;
		cout << "Score of Team " << teamTwo.get_teamName() << ": " << scoreTeam2 << endl;
		cout << "Score of Team " << teamOne.get_teamName() << ": " << scoreTeam1 << endl;
	}
	else
	{
		cout << "\n Both teams ended with the same score. No team wins!" << endl;
		cout << "Score of Team " << teamOne.get_teamName() << ": " << scoreTeam1 << endl;
		cout << "Score of Team " << teamTwo.get_teamName() << ": " << scoreTeam2 << endl;
	}

	

	char YesNo = 'P';
	while (YesNo != '1' && YesNo != '2')
	{
		cout << "\n\nWould you like to print the Losers Pile? \n" << endl;
		cout << "" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No. \n" << endl;
		cout << "Make Selection: " << endl;

		cin >> YesNo;

		cout << "\n\n" << endl;

	}

	if (YesNo == '1')
	{
		LoserStackNode pLoserHead = ListLosers.get_phead();
		cout << "\n List of Losers: \n" << endl;
		ListLosers.PrintFrontToBack(&pLoserHead);
	}


	delete[]combatCreatures;
	combatCreatures = NULL;

	return winningTeam;
}

