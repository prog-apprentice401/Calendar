/*
	This file contains all function protypes for utility
	functions
*/
#ifndef UTILS_H
	#define UTILS_H

	#define CURSOR_UP(y)	(printf ("\033[%dA", (y)))
	#define CURSOR_DOWN(y)	(printf ("\033[%dB", (y)))
	#define CURSOR_RIGHT(x)	(printf ("\033[%dC", (x)))
	#define CURSOR_LEFT(x)	(printf ("\033[%dD", (x)))

	#define GOTOXY(x,y) (printf ("\033[%d;%dH", (x), (y)))

	typedef enum {
		RED = 31,
		GREEN = 32,
		YELLOW = 33,
		BLUE = 34,
		MAGENTA = 35,
		CYAN = 36,
		DEFAULT = 0,
	} Colours;

	typedef struct {
		int x;
		int y;
	} Point;

	void clearBuffer (void);
	void setColour (Colours);
#endif	//UTILS_H
