/*****************************************************
** Program Filename: WarriorQInterface.cpp
** Author: John J. Murphy
** Date: 11/17/2016
** Description: This is class provides an interface to
** WarriorQueue Data Structure.
** Input:
** Output:
******************************************************/
#include<iostream>
#include<cstdlib>
#include<string>

#include"WarriorQInterface.hpp"
#include"utilities.hpp"
#include"WarriorQueueNode.hpp"

#include"Creatures.hpp"
#include"Barbarian.hpp"
#include"BlueMen.hpp"
#include"HarryPotter.hpp"
#include"Medusa.hpp"
#include"Vampire.hpp"


/**********************************************************
** Function: WarriorQInterface::WarriorQInterface()
** Description: Constructor for LinkListInterface class
** Parameters: None
** Pre-Conditions: phead, ptail - uninitialized
** Post-Conditions: phead = NULL, ptail = NULL
** Return: This is a constructor. No value returned.
**********************************************************/
WarriorQInterface::WarriorQInterface(string nName)
{
	phead = NULL;
	ptail = NULL;
	Warrior = NULL;
	curSize = 0;

	teamName = nName;
}

/**********************************************************
** Function: dbLinkListInterface::~dbLinkListInterface()
** Description: Deallocates Memory used by list
** Parameters: None
** Pre-Conditions: phead, ptail - point to memory
** Post-Conditions: phead - destroyed, ptail 0 destroyed
** Return: This is a destructor. No value returned.
**********************************************************/
WarriorQInterface::~WarriorQInterface()
{
	/* Destructor Logic Starts at the beginning of the list */
	/* Create iterator node - set to pointer at head of list */
	WarriorQueueNode *pdestroyNode = phead;
	while (pdestroyNode != NULL)
	{
		/* Create garbage node */
		WarriorQueueNode *garbage = pdestroyNode;

		pdestroyNode = pdestroyNode->next;

		/* Delete garbage node */
		delete garbage->dataWarrior; /* Required: To free memory related to the Creature Pointer data element in the 
									 ** WarriorQueueNode Data Structure */
		delete garbage;

	}
	
}

/******************************************************************
** Function: WarriorQInterface::PrintFrontToBack(WarriorQueueNode* head)
** Description: Prints Warrior Line-up from front to back.
** Parameters: pointer to the head pointer of the linked list.
** Pre-Conditions: head - points to head of list.
** Post-Conditions: Printed List to Console
** Return: void
*******************************************************************/
void WarriorQInterface::PrintFrontToBack(WarriorQueueNode* head)
{
	WarriorQueueNode* pTemp = head;

	while (pTemp != NULL)
	{
		/* cout statement prints variable name (creature type) to screen */
		cout << pTemp->dataWarrior->get_Name() << "-" << pTemp->dataWarrior->get_indivName() << endl;

		/* PROGRAMMERS NOTE: MUST ADD - cout statement prints variable indivName (user specified name of creature) to the screen */
		pTemp = pTemp->next;
	}
	cout << endl;

}


/******************************************************************
** Function: WarriorQInterface::WarriorQInterface(WarriorQueueNode* tail)
** Description: Prints Warrior Line-up from back to front.
** Parameters: pointer to the tail pointer of the linked list.
** Pre-Conditions: tail - points to tail of list.
** Post-Conditions: Printed List to Console
** Return: void
*******************************************************************/
void WarriorQInterface::PrintBackToFront(WarriorQueueNode* tail)
{
	WarriorQueueNode* pTemp = tail;

	while (pTemp != NULL)
	{
		/* cout statement prints variable name (creature type) to screen */
		cout << pTemp->dataWarrior->get_Name() << "-" << pTemp->dataWarrior->get_indivName() << endl;

		/* PROGRAMMERS NOTE: MUST ADD - cout statement prints variable indivName (user specified name of creature) to the screen */
		pTemp = pTemp->previous;
	}
	cout << endl;
}


/******************************************************************
** Function: Creatures* WarriorQInterface::pop()
** Description: Removes data to the end of the list.
** Parameters: none
** Pre-Conditions: Queue of Team Line-Up
** Post-Conditions: Queue of Team Line-Up - less one Warrior.
** Return: Creatures* - pointer to the creature popped from Queue.
*******************************************************************/
Creatures* WarriorQInterface::pop()  /* PROGRAMMERS NOTE: Must Review Logic - Does this make sense? */
{

	Creatures* val2Remove = phead->dataWarrior;

	/* If Else Statement to protect against NULL tail pointer */

		/* Removed Value Identified */
		WarriorQueueNode *ptemp = phead;
		/* Store next memory location of list in phead and delete ptemp */
		phead = ptemp->next;
		if (phead != NULL)
		{
			phead->previous = NULL;
		}

		delete ptemp;

		curSize--;
		return val2Remove;
	
}


/******************************************************************
** Function: void WarriorQInterface::push(int inputval)
** Description: Adds input to the end of the Line-Up Queue.
** Parameters: inputval (integer)
** Pre-Conditions: Double Linked List - Warrior Line-Up
** Post-Conditions: Double Linked List with additional node element
** Return: void
*******************************************************************/
void WarriorQInterface::push(Creatures* inputval)
{
	/* Create first Node and set the head and Tail Pointers equal to it */

	if (phead == NULL)
	{
		/* Creates new node */
		n = new WarriorQueueNode;
		/* Sets Data Element */
		n->dataWarrior = inputval;
		/* Sets previous pointer to NULL */
		n->previous = NULL;
		/* Head and Tail Pointers point to the same node. */
		phead = n;
		ptail = n;
		//ptail->next = NULL;
	}
	else
	{
		n = new WarriorQueueNode;
		/* Sets data stored in node to inputval */
		n->dataWarrior = inputval;
		
		ptail->next = n;
		n->previous = ptail;

		ptail = n;

		ptail->next = n;
		//ptail->next = NULL;
	}
	curSize++;
}

/******************************************************************
** Function: void WarriorQInterface::closeList(int inputval)
** Description: Adds input to the end of the list and sets a tail
** pointer to NULL.
** Parameters: inputval (integer)
** Pre-Conditions: Double Linked List
** Post-Conditions: Double Linked List with tail pointer of NULL
** Return: void
*******************************************************************/
void WarriorQInterface::closeList(Creatures* inputval)
{
	/*Create first Node and set the head and Tail Pointers equal to it */

	/* If only element in queue and will be only Warrior on Team Node
	** must be closed with previous element equal to NULL and next element
	** equal to NULL */

	if (phead == NULL && ptail == NULL)
	{
		/* Creates new node */
		n = new WarriorQueueNode;
		/* Sets Data Element */
		n->dataWarrior = inputval;
		/* Sets previous pointer to NULL */
		n->previous = NULL;
		/* Sets next pointer to NULL - To close Queue */
		//n->next = NULL;
		/* Head and Tail Pointers point to the same node. */
		phead = n;
		ptail = n;
		ptail->next = NULL; //PROGRAMMERS NOTE:DELETE IF REQUIRED.
	}
	else
	{
		/* Create first Node and set the head and Tail Pointers equal to it */
		n = new WarriorQueueNode;
		/* Sets data stored in node to inputval */
		n->dataWarrior = inputval;
		n->previous = ptail;
		ptail->next = n;
		ptail = n;
		ptail->next = NULL;
	}
	curSize++;

}


/******************************************************************
** Function: void WarriorQInterface::add(Creatures* inputval)
** Description: Adds input to the end of the Line-Up Queue.
** Parameters: inputval (integer)
** Pre-Conditions: Double Linked List - Warrior Line-Up
** Post-Conditions: Double Linked List with additional node element
** Return: void
*******************************************************************/
void WarriorQInterface::add(Creatures* inputval)
{
	/* Traverse from front to back */
	WarriorQueueNode* pTemp = new WarriorQueueNode;
	pTemp->dataWarrior = inputval;
	pTemp->next = NULL;
	pTemp->previous = NULL;

	if (phead == NULL){
		pTemp->previous = NULL;
		pTemp->next = NULL;
		phead = pTemp;
		ptail = pTemp;
		n = pTemp;
	}
	else{
		WarriorQueueNode *last = phead;

		/*******Test******/
		//phead = last->next;
		//phead->previous = NULL;
		/*******Test******/

		while (last->next != NULL)
		{
			last = last->next;
		}

			/* Add the new node on to the last node in the list */
		last->next = pTemp;
		ptail = pTemp;
	}
	curSize++;
}
/******************************************************************
** Function: void WarriorQInterface::buildWarriorQueue()
** Description: Executes Logic for Interface for WarriorQueueNode Data
** structure.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Double Linked List Queue - Represents Warrior 
** Line-Up.
** Return: void
*******************************************************************/
void WarriorQInterface::buildWarriorQueue(std::string *creaturesInUniverse, int numAvailCreatures)
{
	bool runCont = true;

	/* Create Array to be used as the source for the items listed in the
	** menu. */
	
	//int cnt = 0;
	//while (runCont)
	//{
	bool runWhile = true;
	int cnt = 0;

	while (runWhile)
	{

		cout << "Add new Warrior to Team "<< this->teamName <<" line-up: \n" << endl;

		/* Start Logic: required to instantiate an instance of the appropiate creature **
		** Selection of Creature to Add to Queue based on integer selected			 **/
		
		int creature2Add = optionsMenu(numAvailCreatures, creaturesInUniverse);

		switch (creature2Add){

			case 1:
			{
				/* Logic for Vampire */
				Warrior = new Vampire();
			}
				break;
			case 2:
			{
				Warrior = new Barbarian();
			}
				break;
			case 3:
			{
				// Logic for Blue Men
				Warrior = new BlueMen();
			}
				break;
			case 4:
			{
				// Logic for Medusa
				Warrior = new Medusa();
			}
				break;
			case 5:
			{
				Warrior = new HarryPotter();
			}
		}

		/* Assign Unique Name to Creature */
		string tempName;
		cout << "Please enter a Name for your Creature: ";		
		cin >> tempName;
		//getline(cin, tempName);

		Warrior->set_indivName(tempName);


		/* End Logic: for creating Warriors */

				/* Logic to Control the number of values entered into the Doubly Linked List*/
				char YesNo = 'P';
				while (YesNo != '1' && YesNo != '2')
				{
					cout << "\n\nWould you Like to continue adding Warriors? \n" << endl;
					cout << "" << endl;
					cout << "1. Continue Adding Warriors" << endl;
					cout << "2. Line-up Complete. Continue to War-Game. \n" << endl;
					cout << "Make Selection: " << endl;
					
					cin >> YesNo;

					cout << "\n\n" << endl;

				}
				if (YesNo == '1')
					runWhile = true;
				else
					runWhile = false;

				/* Adds to List with push function. Adds last value and sets tail to null. */
				if (runWhile)
					this->push(Warrior);
				else
					this->closeList(Warrior);
				cnt++;
			}
/* PROGRAMMERS NOTE: For Testing Purposes */

	/*cout << "\nTeam " << teamName << " Line-Up: \n" << endl;
			WarriorQueueNode theHead = this->get_head();
			this->PrintFrontToBack(&theHead);*/
	

}