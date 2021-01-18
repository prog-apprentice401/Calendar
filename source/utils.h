/*
	This file contains all function protypes for utility
	functions
*/
#ifndef UTILS_H
	#define UTILS_H

	typedef enum {
		RED = 31,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		DEFAULT = 0,
	} Colours;

	void clearBuffer (void);
	
	void setColour (Colours);
#endif	//UTILS_H
