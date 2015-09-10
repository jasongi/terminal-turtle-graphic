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
#include <math.h>
#include <stdio.h>
#include "draw.h"
#include "write_log.h"

void exeInstructions(LinkedList *instructionList)
{
	/*declarations*/
	double x, y, angle, degrees;
	int fg, bg;
	char pattern;
	FILE *w;
	Instruction *tempInstr;
	PlotFunc plotter;
	/*initialising varialbes*/
	x = DEFAULTX;
	y = DEFAULTY;
	angle = DEFAULTANGLE;
	fg = DEFAULTFG;
	bg = DEFAULTBG;
	pattern = DEFAULTPATTERN;
	setFgColour(fg);																				/*sets bg and fg colour to defaults*/
	setBgColour(bg);
	clearScreen();																					/*clears the screen ready to draw*/
	w = startFile();																				/*opens the log*/
	if (w == NULL)
		perror("error opening folder");																/*checks that the log opened*/
	else
	{
		tempInstr = returnFirstElement(instructionList);											/*gets the element at the 'front' of the list*/
		while (tempInstr != NULL)																	/*checks to see if the current instruction exists
																									(this will be null when the list is empty*/
		{
			switch (tempInstr->type)																/*calls the appropriate functions for the type*/
			{
			case ROTATE:		degrees = *((double*)tempInstr->magnitude);
								rotate(degrees, &angle);
								break;
							
			case MOVE:			moveOrDraw(NULL, &y, &x, &pattern, &angle, tempInstr, w, "MOVE");
								break;
							
			case DRAW:			plotter = &drawPlotter;
								moveOrDraw(plotter, &y, &x, &pattern, &angle, tempInstr, w, "DRAW");
								break;
									
			case FG:			fg = *((int*)tempInstr->magnitude);
								setFgColour(fg);
								break;
							
			case BG:			bg = *((int*)tempInstr->magnitude);
								setBgColour(bg);
								break;
							
			case PATTERN:		pattern = *((char*)tempInstr->magnitude);
								break;
			case VOIDENTRY:
			default:			break;																/*nothing happens when there's invalid entry*/
			}
			removeFirst(instructionList);															/*deallocates the instruction*/
			tempInstr = returnFirstElement(instructionList);										/*sets the instruction to the new front of the list*/
		}
		closeFile(w);																				/*closes the file*/
		setFgColour(DEFAULTFG);
		setBgColour(DEFAULTBG);
		penDown();																					/*puts the cursor at the bottom of terminal*/
	}
	freeList(instructionList);																		/*deallocates the list*/
}
	
void rotate(double magnitude, double *angle)														/*this functions adds the magnitude to the angle
																									then makes sure it is bettwen 0 & 360*/
{
	*angle += magnitude;
	if (*angle > 360)
		*angle -= 360;
	else if (*angle < 0)
		*angle += 360;
}
void moveOrDraw (PlotFunc plotter, double *y, double *x, char *pattern, double *angle, Instruction *tempInstr, FILE *w, char *type)
/*this function calculates the write/draw function into x1 x2 y1 y2, then writes it to a file and if it is a draw, actually draws the line*/
{
	double tempY, tempX, length, tmpCos, tmpSin;
	length = *(double*)(tempInstr->magnitude);
	tempY = *y;
	tempX = *x;
	tmpCos = cos((*angle)*(PI/180));
	tmpSin = sin((*angle-180)*(PI/180));															/* the '-180 after the sin is because
																									the positive Y axis is where the negetive
																									one usually is*/
	*y += length*tmpSin;
	*x += length*tmpCos;
	writeEntry(w, type, tempX, tempY, *x, *y);
	if (tempInstr->type == DRAW)
	{
		line((int)(tempX+0.5), (int)(tempY+0.5), (int)(*x+0.5), (int)(*y+0.5), plotter, (void*)(pattern));
	}
}
void drawPlotter(void *data)																		/*prints the character that data points to*/
{
	char pattern;
	pattern = *((char*)data);
	printf("%c", pattern);
}
