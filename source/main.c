/*
	This is the program for a calender application.
	It allows the user to:
		-Print a particular month's calander
		-Print a particular year's calander

	Project started by Koustubh Srivastava
*/
#include <stdio.h>
#include "date.h"
#include "utils.h"
#include "outputs.h"
#include "inputs.h"
#include "menu.h"

unsigned long int getYear (void);
unsigned short int getMonth (void);
unsigned short int getDay (unsigned short int, unsigned long int);

int main (int argc, char *argv[])
{
	int option;

	while (1) {
		printMenu ();
		option = getOption ();
		handleMenu (option);
	}
	return 0;
}
