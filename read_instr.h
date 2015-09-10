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
#define LINEMAX 40 /*if there is a line bigger than this it will cause an error reading the line but the program will just skip drawing it*/
#include "linked_list.h"
LinkedList* readInstructions(char* filename);
Instruction* extractInstruction(char* inStr);
void intEntry(Instruction *newInstruction,char *str2);
void doubleEntry(Instruction *newInstruction,char *str2);
void caseConvert(char* inStr);
