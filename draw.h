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
#include "linked_list.h"
#include "effects.h"
/* PI (for the sin/cos values) */
#define PI 3.141592
/* default values */
#define DEFAULTX 0.0
#define DEFAULTY 0.0
#define DEFAULTANGLE 0.0
#define DEFAULTFG 7
#define DEFAULTBG 0	
#define DEFAULTPATTERN 43 /*the '+' symbol*/
void exeInstructions(LinkedList *instructionList);
void rotate(double magnitude, double *angle);
void moveOrDraw (PlotFunc plotter, double *y, double *x, char *pattern, double *angle, Instruction *tempInstr, FILE *w, char *type);
void drawPlotter(void *data);
