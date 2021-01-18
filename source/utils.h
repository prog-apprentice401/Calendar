/*
	This file contains all function protypes for utility
	functions
*/
#ifndef UTILS_H
	#define UTILS_H

	#define gotoxy(x,y) (printf ("\033[%d;%dH", x, y))

	typedef enum {
		RED = 31,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		DEFAULT = 0,
	} Colours;

	typedef struct {
		int x;
		int y;
	} Point;

	void clearBuffer (void);
	void setColour (Colours);
#endif	//UTILS_H
