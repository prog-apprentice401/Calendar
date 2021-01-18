/*
	This is a source file contating the definitions of all utility fucntions
	used in the project
*/
#include <stdio.h>
#include "utils.h"

void setColour (Colours colour)
{
	printf ("\033[1;%dm", colour);	
}

void clearBuffer (void)
{
	char dump;
	while ((dump = getchar ()) != '\n' && dump != EOF)
		;
}
