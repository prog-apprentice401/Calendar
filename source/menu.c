/*
	This is the Source file for all functions relating
	to handling the menu
*/

#include <stdio.h>
#include <stdlib.h>
#include "outputs.h"
#include "menu.h"
#include "date.h"
#include "utils.h"

//function: prints option menu
//accepts : void
//returns : void
void printMenu (void)
{
	setColour (CYAN);
	printf ("\nEnter:\n"
		"  0 to exit\n"
		"  1 to print a year's calendar\n"
		"  2 to print a month's calendar\n" );
	setColour (DEFAULT);
}

//function: calls appropriate functions based on option
//accepts : option chosen
//returns : void
void handleMenu (int option)
{
	Date date = {0};
	Point origin = {1, 1};

	switch (option) {
		case 0:
			setColour (YELLOW);
			printf ("Thanks for using this application\n");
			exit (0);
		case 1:
			date.year = getYear ();
			printYear (date.year);
			break;
		case 2:
			date.year = getYear ();
			date.month = getMonth ();

			system ("clear");
			printMonth (date, origin);
			break;
		default:
			setColour (RED);
			printf ("Invalid Option\n");
			setColour (DEFAULT);
			break;
	}
}

