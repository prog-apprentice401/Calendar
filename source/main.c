/*
	This is the program for a calender application.
	It allows the user to:
		-Print a particular month's calander
		-Print a particular year's calander

	Project started by Koustubh Srivastava
*/
#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#include "utils.h"
#include "outputs.h"

int printMenu (void);
int getOption (int);
void handleMenu (int, Date);

int main (int argc, char *argv[])
{
	Date date;
	int option;
	int numOfOptions;

	while (1) {
		date.year = 1599;
		date.month = -1;
		
		numOfOptions = printMenu ();
		option = getOption (numOfOptions);
		if (option < 0) {
			setColour (RED);
			printf ("Invalid Option\n");
			setColour (DEFAULT);

			continue;
		}
		setColour (YELLOW);
		printf ("Enter the month and year\n\n"
			"[Jan 1600 as 1/1600]\n");
		scanf ("%d/%d", &date.month, &date.year);
		clearBuffer ();
		setColour (DEFAULT);

		setColour (RED);
		if (date.year < 1600) {
			printf ("No record before 1600\n");
			continue;
		} else if (date.month > 12 || date.month < 1) {
			printf ("Invalid Date\n");
			continue;
		}
		setColour (DEFAULT);
		handleMenu (option, date);
	}
	return 0;
}

//function: printfs option menu
//accepts : void
//returns : number of options
int printMenu (void)
{
	int numOfOptions = 4;

	setColour (CYAN);
	printf ("Enter:\n"
		"  0 to exit\n"
		"  1 to print a month's calendar\n"
		"  2 to print a year's calendar\n"
		"  3 to add a reminder (under development)\n");
	setColour (DEFAULT);

	return numOfOptions;
}

//function: gets a VALID option from the user
//accepts : number of options the user gets
//returns : integer b/w 0 and numOfOptions, -1 on invalid input
int getOption (int numOfOptions)
{
	int option;
	scanf ("%d", &option);
	clearBuffer ();
	
	if (option >= 0 && option < numOfOptions) {
		return option;
	}
	return -1;
}

//function: calls appropriate functions based on option
//accepts : option chosen, date to calculate upon
//returns : void
void handleMenu (int option, Date date)
{
	Point origin = {0, 0};
	switch (option) {
		case 0:
			setColour (GREEN);
			printf ("Thanks for Using this Application\n");
			setColour (DEFAULT);
			exit (0);
		case 1:
			system ("clear");
			printMonth (date, origin);
			break;
		case 2:
			printYear (date);
			break;
		case 3:
			setColour (RED);
			printf ("Feature under development\n");
			setColour (DEFAULT);
			break;
		default:
			setColour (RED);
			printf ("Invalid Option\n");
			setColour (DEFAULT);
			break;
	}
}
