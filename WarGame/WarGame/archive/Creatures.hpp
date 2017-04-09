/*****************************************************
** Program Filename: Creatures.hpp
** Author: John J. Murphy
** Date: 11/4/2016
** Description: This is .hpp file declares the
** behavior and variables of the Creatures base Class
** Input:
** Output:
******************************************************/
#ifndef CREATURES_HPP
#define CREATURES_HPP
#include <iostream>
#include <string>

using namespace std;

class Creatures
{
public:
	/* Constructor for Creature Class */
	Creatures();
	virtual ~Creatures(){};	
	/* Attack, Defend functions are virtual. 
	** Special implementations of these functions
	** will be required for */
	
	virtual int Attack();

	/* Overload Defend Function for Vampire Class */
	virtual int Defend(int);
	virtual int Defend(){ return 0; }; /* Called when Vampire Charms his why
						  ** out of being Attacked. /	

	/* Only Called for Blue Men which will redefine this function */
	virtual void dieChange(int valCurStrength){}; 

	/* Only Called for Harry Potter which will redefine this function */
	virtual void set_DeathCnt(int deathCnt){};
	virtual int get_DeathCnt(){ return 0; };

	/* get_Name() function is Pure Virtual Function. */
	virtual string get_Name() = 0;
	virtual int get_Armor() = 0;
	


	int get_Strength(){ return valCurStrength; };
	void set_Strength(int setStr){ valCurStrength = setStr; };
	
	
	/* indivName Functions: User defined names of each selected creature*/
		/* Gets the Individual name of Creature assigned by Player */
		string get_indivName(){ return indivName; };
		/* Gets the Individual name of Creature assigned by Player */
		void set_indivName(string aName){ indivName = aName; };



	/* Virtual function will be unique for harry potter*/
	//virtual void updateStrength(); 

//	int getArmor(){ return valCurArmor; };
	
	//void setDamage(int inpDamage){ damage = inpDamage; }
	void UpdateStrength(int damageByAttack); /* Will update strength as damage is inflicted */
	int get_Die(){ return numDefDie; };
	


protected:

	int valCurStrength; 
	int damage;
	string indivName;

	/* Protected Variables set by the Derived Class */
	int numAttackDie;
	int sizeAttackDie;
	int numDefDie;
	int sizeDefDie;


private:	

};
#endif
