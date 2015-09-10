#ifndef DEFINED													/*so that things aren't included twice*/
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
/*constants*/
#define VOIDENTRY 0
#define ROTATE 1
#define MOVE 2
#define DRAW 3
#define FG 4
#define BG 5
#define PATTERN 6

typedef struct {
void *magnitude;
int type;
} Instruction;

typedef struct LinkedListNode{
Instruction *instruction;
struct LinkedListNode *next; 
} LinkedListNode;

typedef struct {
LinkedListNode *head;
LinkedListNode *tail; 
} LinkedList;

LinkedList *createList();
void insertLast(LinkedList *lL, Instruction *inInstruction);
void removeFirst(LinkedList *lL);
Instruction *returnFirstElement(LinkedList *lL);
void freeList(LinkedList *lL);
#define DEFINED													/*for the ifndef statement*/
#endif
