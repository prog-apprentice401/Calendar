/*
	This file contains all function protypes for utility
	functions
*/
#ifndef UTILS_H
	#define UTILS_H

	#define CURSOR_UP(r)	(printf ("\033[%dA", (r)))
	#define CURSOR_DOWN(r)	(printf ("\033[%dB", (r)))
	#define CURSOR_RIGHT(c)	(printf ("\033[%dC", (c)))
	#define CURSOR_LEFT(c)	(printf ("\033[%dD", (c)))
	
	//macro to set cursor position: 
	#define GOTORC(r,c) (printf ("\033[%d;%dH", (r), (c)))

	//enumeration containing ASCII CSI codes
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
