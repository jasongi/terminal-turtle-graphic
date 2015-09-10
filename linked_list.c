/* 
 *	a fun lil linked list file
 * 	cut out everything that wasn't needed
 * 	for this queue-type list like insertFirst and returnNElement (replaced with returnFirst)
 */
 
 /*  
    Copyright (C) 2012 Jason Giancono (jasongiancono@gmail.com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
LinkedList *createList()
{
	LinkedList *newLL = (LinkedList*)malloc(sizeof(LinkedList));					/*allocates a new list*/
	newLL->head = NULL;																/*points both head and tail to null*/
	newLL->tail = NULL;
	return newLL;
}

void insertLast(LinkedList *lL, Instruction *inInstruction)
{
	LinkedListNode *newLLN = (LinkedListNode*)malloc(sizeof(LinkedListNode));		/*allocates a new node*/
	newLLN->instruction = inInstruction;											
	if (lL->head == NULL)															/*only when the list is empty*/
	{
		lL->head = newLLN;
		lL->tail = newLLN;
		newLLN->next = NULL;
	}
	else																			/*when the list has one or more element*/
	{
		LinkedListNode *tempPtr = lL->tail;
		newLLN->next = NULL;
		lL->tail = newLLN;
		tempPtr->next = lL->tail;
	}
}
	

void removeFirst(LinkedList *lL)
{
	LinkedListNode *tempPtr = lL->head;
	if (tempPtr == NULL);															/*checks to see if list is empty*/
	else if (tempPtr == lL->tail)
	{
		if (tempPtr->instruction->magnitude != NULL)								/*need this to check for the elements made from
																					 *bad entries in the input file*/
			free(tempPtr->instruction->magnitude);
		free(tempPtr->instruction);
		free(tempPtr);
		lL->head = NULL;
		lL->tail = NULL;
	}
	else
	{
		lL->head = tempPtr->next;													/*makes head the next pointer in the list after the first*/
		if (tempPtr->instruction->magnitude != NULL)								/*need this to check for the elements made from
																					 *bad entries in the input file*/
			free(tempPtr->instruction->magnitude);
		free(tempPtr->instruction);
		free(tempPtr);
	}
}

Instruction *returnFirstElement(LinkedList *lL)
{
	Instruction *tempI;
	if (lL->head == NULL)															/*checks to see if list is empty*/
		tempI = NULL;
	else
		tempI = lL->head->instruction;
	return tempI;
}


void freeList(LinkedList *lL)
{
	LinkedListNode *tempPtr;
	tempPtr = lL->head;
	while (tempPtr != NULL);														/*checks to see if list is empty*/
	{
		removeFirst(lL);															/*removes first until it is 
																					 this isn't really used in this program,
																					 as things are removed before now but I wanna be safe*/
		tempPtr= lL->head;
	}
	free(lL);																		/*finally deallocates the list*/
}
