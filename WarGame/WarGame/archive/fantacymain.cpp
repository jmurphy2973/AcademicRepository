
/*****************************************************
** Program Filename: fantacymain.cpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is this main function that 
** initiates Battle within th Universe.
** Input: None
** Output: Winner of the Battle.
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
#include"WarriorQInterface.hpp"

using namespace std;

int main()
{
	srand(time(NULL));
	
	/******************** Test 1 Start **************************/

	//Universe fantacyWorld;
	//fantacyWorld.SelectCombatants();

	//cout << fantacyWorld.EngageInBattle() << endl;

	/******************** Test 1 End **************************/





	/******************** Test 2 Start **************************/

	/* Test of WarriorQueueNode - Functionality and Memory Leaks */
	//std::string *combatCreatures;		/* PROGRAMMERS NOTE: Possibly delete */
	//combatCreatures = new std::string[5];

	///* Add creature names to Array. */
	//combatCreatures[0] = "Vampire";
	//combatCreatures[1] = "Barbarian";
	//combatCreatures[2] = "Blue Men";
	//combatCreatures[3] = "Medusa";
	//combatCreatures[4] = "Harry Potter";

	//WarriorQInterface TeamMurphy;
	//TeamMurphy.buildWarriorQueue(combatCreatures, 5);

	//delete[]combatCreatures;
	//combatCreatures = NULL;

	/********************** Test 2 End *************************/


	/******************** Test 3 Start **************************/

	Universe TotalWar;
	TotalWar.EngageInTotalWar();

	//cout << fantacyWorld.EngageInBattle() << endl;

	/******************** Test 3 End **************************/

	cin.get();
	cin.get();

	return 0;
}