/*****************************************************
** Program Filename: Universe.hpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .hpp file declares the
** behavior and variables of the Universe.
** Input:
** Output:
******************************************************/
#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

#include<iostream>
#include<string>
#include<time.h>
#include<cstdlib>

#include"Creatures.hpp"
#include"Barbarian.hpp"
#include"BlueMen.hpp"
#include"HarryPotter.hpp"

class Universe
{
public:
	Universe();
	~Universe();
	void SelectCombatants();		/* Used to assign type of creature engaged in combat with each other */
	string EngageInBattle();		/* To output the name of the Combatant who wins */
	
	string EngageInTotalWar();
	//int CalcDamage(int inAttack, int inDefense);

	

private:
	Creatures *Combatant1;
	Creatures *Combatant2;
	int combatWins1;
	int combatWins2;
	int creaturesInUniv;
	
};
#endif

