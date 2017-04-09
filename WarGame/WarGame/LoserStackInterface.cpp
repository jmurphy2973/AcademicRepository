/*****************************************************
** Program Filename: singleLinkStackInt.cpp
** Author: John J. Murphy
** Date: 11/6/2016
** Description: This is class provides an interface to
** linked list. (singe linked Stacknode, and doubly
** linked Queuenode.)
** Input:
** Output:
******************************************************/
#include<iostream>
#include<cstdlib>

#include"LoserStackInterface.hpp"
#include"utilities.hpp"
#include"LoserStackNode.hpp"


/**********************************************************
** Function: LoserStackInterface::LoserStackInterface()
** Description: Constructor for LoserStackInterface class
** Parameters: None
** Pre-Conditions: phead, ptail - uninitialized
** Post-Conditions: phead = NULL, ptail = NULL
** Return: This is a constructor. No value returned.
**********************************************************/
LoserStackInterface::LoserStackInterface()
{
	phead = NULL;
	//ptail = NULL;
}


/**********************************************************
** Function: LoserStackInterface::~LoserStackInterface()
** Description: Deallocates Memory used by list
** Parameters: None
** Pre-Conditions: phead - point to memory
** Post-Conditions: phead - destroyed, ptail 0 destroyed
** Return: This is a destructor. No value returned.
**********************************************************/
LoserStackInterface::~LoserStackInterface()
{
	/* Destructor Logic Starts at the beginning of the list */
	/* Create iterator node - set to pointer at head of list */
	LoserStackNode *pdestroyNode = phead;
	while (pdestroyNode != NULL)
	{
		/* Create garbage node */
		LoserStackNode *garbage = pdestroyNode;

		pdestroyNode = pdestroyNode->next;

		/* Delete garbage node */
		delete garbage;

	}
}

/******************************************************************
** Function: LoserStackInterface::PrintFrontToBack(LoserStackNode* head)
** Description: Prints Stack from front to back.
** Parameters: pointer to the head pointer of the linked list.
** Pre-Conditions: head - points to head of list.
** Post-Conditions: Printed List to Console
** Return: void
*******************************************************************/
void LoserStackInterface::PrintFrontToBack(LoserStackNode* head)
{
	LoserStackNode* pTemp = head;

	while (pTemp != NULL)
	{
		cout << pTemp->dataLoser->get_Name() << "-" << pTemp->dataLoser->get_indivName() << endl;
		pTemp = pTemp->next;
	}
	cout << endl;
}

/******************************************************************
** Function: void LoserStackInterface::push(int inputval)
** Description: Adds input to the top of the list.
** Parameters: inputval (integer)
** Pre-Conditions: Single Linked List
** Post-Conditions: Single Linked List (stack) with additional element.
** Return: void
*******************************************************************/
void LoserStackInterface::push(Creatures* inputval)
{
	/* Add data to front of list */
	if (phead == NULL)
		phead = new LoserStackNode(inputval);
	else
	{
		/* Remember: Top of stack is last number entered. This should add to the front of the list. */
		LoserStackNode *ptemp = phead;
		phead = new LoserStackNode(inputval);

		phead->next = ptemp;
	}

}
