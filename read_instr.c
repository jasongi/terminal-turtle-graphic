#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_instr.h"
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
LinkedList* readInstructions(char *filename)
{	

	FILE *r; 													/*the r stands for read!*/
	LinkedList *instrList;
	Instruction *newInstruction;
	char tempStr[LINEMAX]; 										/*LINEMAX defined in read_instr.h*/
	r = fopen(filename, "r");
	if (r == NULL) 												/*checks to see if file opened 
																properly*/
		instrList = NULL;
	else
	{
		instrList = createList(); 								/*calls to function to create an empty
																LinkedList*/
		while ((fgets(tempStr, LINEMAX, r)) != NULL) 			/*fetches the next line in the file.
																if it is empty/blank it exists the
																loop*/
		{
			newInstruction = extractInstruction(tempStr);		/* passes the string to extract
																Instruction and gets back a
																*/
			insertLast(instrList,newInstruction);				/* inserts the instruction in the 
																list*/
		}
		if (ferror(r) != 0)										/*checks to see if there were any
																read errors, if so outputs the error*/
			perror("ERROR READING FILE: ");
		fclose(r);												/*closes the file*/
	}
	return instrList;
}
Instruction *extractInstruction(char *inStr)
{
	/*declarations of things*/
	void *magnitude;
	Instruction *newInstruction;
	char str1[LINEMAX];
	char str2[LINEMAX];
	
	newInstruction = (Instruction*)malloc(sizeof(Instruction));	/*allocating the instruction*/

		if (sscanf(inStr, "%s %s\n", str1, str2) == 2)			/*checks to see if inStr has the correct format*/
			{
			caseConvert(str1);
			if (strcmp(str1, "ROTATE") == 0)						/*all these ifs check to see which type the instruction is*/
			{
				doubleEntry(newInstruction, str2);
				newInstruction->type = ROTATE;
			}
			else if (strcmp(str1, "MOVE") == 0)
			{
				doubleEntry(newInstruction, str2);
				newInstruction->type = MOVE;
			}
			else if (strcmp(str1, "DRAW") == 0)
			{
				doubleEntry(newInstruction, str2);
				newInstruction->type = DRAW;
			}
	
			else if (strcmp(str1, "FG") == 0)
			{
				newInstruction->type = FG;
				intEntry(newInstruction, str2);
			}
			else if (strcmp(str1, "BG") == 0)
			{
				intEntry(newInstruction, str2);
				newInstruction->type = BG;
			}
			else if (strcmp(str1, "PATTERN") == 0)
			{
				magnitude = malloc(sizeof(char));
				*((char*)magnitude) = *str2;
				newInstruction->type = PATTERN;
				newInstruction->magnitude = magnitude;
			}
			else 
			{	
				newInstruction->type = VOIDENTRY;						
				newInstruction->magnitude = NULL;				/*This statement happens when there's no match for str1
																NOTE: both these 'other' cases still make an entry in the
																LinkedList, but the instruction does nothing
																in the SWTICH statement in draw.c as it
																and is then deleted*/
			}
		}
		else														/*same thing happens if there aren't two
																strings on the line, eg a blank file*/
		{
			newInstruction->magnitude = NULL;
			newInstruction->type = VOIDENTRY;
		}
	return newInstruction;
}

void intEntry(Instruction *newInstruction,char *str2) 			/*helper function to allocated magnitude, set it
																to a value and set it to the cast of the value in the string*/
{
	void *magnitude = malloc(sizeof(int));
	*((int*)magnitude) = atoi(str2);
	newInstruction->magnitude = magnitude;
}

void doubleEntry(Instruction *newInstruction,char *str2)		/*helper function to allocated magnitude, set it
																to a value and set it to the cast of the value in the string*/
{
	void *magnitude = malloc(sizeof(double));
	*((double*)magnitude) = strtod(str2, NULL);
	newInstruction->magnitude = magnitude;
}
void caseConvert(char *inStr)									/*converts a string to UPPERCASE (it can't contain symbols)*/
{
	int ii =0;
	while (*(inStr+ii) != '\0')
	{
		if (*(inStr+ii) > 90)
			*(inStr+ii) = *(inStr+ii) - 32;
		ii++;
	}
}
