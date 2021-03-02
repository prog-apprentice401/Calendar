/*
	This is the program for a calender application.
	It allows the user to:
		-Print a particular month's calander
		-Print a particular year's calander

	Project started by Koustubh Srivastava
*/
#include <stdio.h>
#include <stdlib.h>
#include "logs.h"
#include "date.h"
#include "utils.h"
#include "outputs.h"

void printMenu (void);
void getOption (int *);
void handleMenu (int);
void getYear (Date *);
void getMonth (Date *);
void getDay (Date *);

int main (int argc, char *argv[])
{
	int option;

	while (1) {
		printMenu ();
		getOption (&option);
		if (option < 0) {
			setColour (RED);
			printf ("Invalid Option\n");
			setColour (DEFAULT);

			continue;
		}

		handleMenu (option);
	}
	return 0;
}

//function: prints option menu
//accepts : void
//returns : void
void printMenu (void)
{
	setColour (CYAN);
	printf ("Enter:\n"
		"  0 to exit\n"
		"  1 to print a year's calendar\n"
		"  2 to print a month's calendar\n"
		"  3 to add a reminder (under development)\n");
	setColour (DEFAULT);
}

//function: gets a VALID option from the user
//accepts : number of options the user gets
//returns : integer b/w 0 and numOfOptions, -1 on invalid input
void getOption (int * optionPtr)
{
	if (optionPtr == NULL) {
		return;
	}

	while (1) {
		scanf ("%d", optionPtr);
		clearBuffer ();

		if (*optionPtr < 0 || *optionPtr > 3) {
			setColour (RED);
			printf ("Invalid Option\n");
			continue;
		}
		break;
	}
}

//function: calls appropriate functions based on option
//accepts : option chosen
//returns : void
void handleMenu (int option)
{
	Date date;
	Point origin = {0, 0};

	switch (option) {
		case 0:
			printf ("Thanks for using this application\n");
			exit (0);
		case 1:
			getYear (&date);
			printYear (date);
			break;
		case 2:
			getMonth (&date);
			system ("clear");
			printMonth (date, origin);
			break;
		case 3:
			getDay (&date);
			addNewEvent (date);
			break;
		default:
			setColour (RED);
			printf ("Invalid Option\n");
			setColour (DEFAULT);
			break;
	}
}

void getYear (Date* datePtr)
{
	if (datePtr == NULL) {
		return;
	}

	while (1) {
		setColour (YELLOW);
		
		printf ("Enter the year\n");
		scanf ("%lu", &datePtr->year);
		clearBuffer ();

		if (datePtr->year < 1600) {
			setColour (RED);
			printf ("No record befor 1600\n");
			continue;
		}
		break;
	}
	setColour (DEFAULT);
}

void getMonth (Date* datePtr)
{
	if (datePtr == NULL) {
		return;
	}

	while (1) {
		getYear (datePtr);

		setColour (YELLOW);
		printf ("Enter the Month\n"
			"[January is 1]\n");
		scanf ("%hu", &datePtr->month);
		clearBuffer ();

		if (datePtr->month > 12 || datePtr->month < 1) {
			setColour (RED);
			printf ("Invalid Month\n");
			continue;
		}
		break;
	}
	setColour (DEFAULT);
}

void getDay (Date* datePtr)
{
	if (datePtr == NULL) {
		return;
	}

	getMonth (datePtr);

	while (1) {

		setColour (YELLOW);
		printf ("Enter the Day of the Month:\n");
		scanf ("%hu", &datePtr->day);
		clearBuffer ();

		if (datePtr->day < 1 || datePtr->day > getDaysInMonth (datePtr->month, datePtr->year)) {
			setColour (RED);
			printf ("Invalid Day\n");
			continue;
		}
		break;
	}
}
