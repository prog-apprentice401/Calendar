/*
	This is a source file contating the definitions of all utility fucntions
	used in the project
*/
#include <stdio.h>
#include "utils.h"

//function: sets output colour
//accepts : colour value to print
//returns : void
void setColour (Colours colour)
{
	printf ("\033[1;%dm", colour);	
}

//function: clears input buffer
//accepts : void
//returns : void
void clearBuffer (void)
{
	char dump;
	while ((dump = getchar ()) != '\n' && dump != EOF)
		;
}
