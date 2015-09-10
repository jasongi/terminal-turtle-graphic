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
#include "write_log.h"
FILE *startFile()
{
	FILE *log;
	log = fopen("graphics.log", "a");
	if (log != NULL)									/*checks to see if it opened*/
		fprintf(log, "---\n");							/*cause can't write to unopened*/
	return log;
}
void writeEntry(FILE *log, char *type, double oldX, 
				double oldY, double newX, double newY)
{
	fprintf(log, "%4s (%7.3f,%7.3f)-(%7.3f,%7.3f)\n", 
			type, oldX, oldY, newX, newY);				/*writes an entry to the supplied file*/
}
void closeFile(FILE *log)								/*closes the file and checks for errors*/
{																								
	if (ferror(log))																			
		perror("ERROR WRITING TO FILE:");
	fclose(log);
}
