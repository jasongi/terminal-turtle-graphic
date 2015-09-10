#include <stdio.h>
#include "read_instr.h"
#include "linked_list.h"
#include "draw.h"
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
int main(int argc, char *argv[])
{	
	int state; 												/*the exit state*/
	if (argc != 2)											/*checks to see if there is two arguments 
															given*/
	{
		printf("wrong amount of args");
		state = 1;
	}
	else
	{
		LinkedList *list; 									/*declares a linked list to pass between 
															functions*/
		list = readInstructions(argv[1]); 					/*sends the first arg to readInstructions*/
		if (list != NULL) 									/*checks to see that the list has things 
															in it*/
		{
			exeInstructions(list); 							/*passes list to draw program*/
			state = 0; 										/*if it got this far, it was (pretty much) 
															a successful excecution*/
		}
		else												/* only executes if the file is empty or 
															corrupt/incorrectly formatted or failed 
															to read*/
			perror("Error reading file specified");
			state = 2;					
	}
	return state;
}
