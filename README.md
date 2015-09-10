README:
Turtle Graphics Program
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

effects.c by David Cooper

KNOWN BUGS:
Cannot handle going out of the bounds of the windows, makes garbage characters pop up.
shapes/drawings are skewed vertically due to there being a larger space between vertical pixels compared to horizontal ones.

OTHER THINGS:
Will read files with blank or gibberish lines (and ignore these lines), as long as those lines aren't above the defined maximum length in read_instr.h
Recommend maximising terminal and/or setting to a small font for best output.

TO RUN:
just run make then ./turtle <instruction file>