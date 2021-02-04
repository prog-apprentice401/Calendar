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

void printMenu (void);
int getOption (void);
void handleMenu (int, Date);

int main (int argc, char *argv[])
{
	Date date;
	int option;

	while (1) {
		date.year = 1599;
		date.month = -1;
		
		printMenu ();
		option = getOption ();
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

void printMenu (void)
{
	setColour (CYAN);
	printf ("Enter:\n"
		"  0 to exit\n"
		"  1 to print a month's calendar\n"
		"  2 to print a year's calendar\n"
		"  3 to add a reminder (under development)\n");
	setColour (DEFAULT);
}

int getOption (void)
{
	int option;
	scanf ("%d", &option);
	clearBuffer ();

	if (option >= 0 && option <= 3) {
		return option;
	}
	return -1;
}

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
