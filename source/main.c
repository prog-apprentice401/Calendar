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
#include "inputs.h"

void printMenu (void);
int getOption (void);
void handleMenu (int);
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

//function: gets a VALID option from the user
//accepts : number of options the user gets
//returns : integer b/w 0 and numOfOptions, -1 on invalid input
int getOption (void)
{
	int option;
	scanf ("%d", &option);
	clearBuffer ();

	return option;
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

//function: gets year from user
//accepts : void
//returns : year entered by user
unsigned long int getYear (void)
{
	unsigned long int year;

	while (1) {
		setColour (YELLOW);
		
		printf ("Enter the year\n");
		scanf ("%lu", &year);
		clearBuffer ();

		if (year < 1600) {
			setColour (RED);
			printf ("No record befor 1600\n");
			continue;
		}
		break;
	}
	setColour (DEFAULT);
	return year;
}

//function: gets month from user
//accepts : void
//returns : month entered by user
unsigned short int getMonth (void)
{
	unsigned short month;

	while (1) {
		setColour (YELLOW);
		printf ("Enter the Month\n"
			"[January is 1]\n");
		scanf ("%hu", &month);
		clearBuffer ();

		if (month > 12 || month < 1) {
			setColour (RED);
			printf ("Invalid Month\n");
			continue;
		}
		break;
	}
	setColour (DEFAULT);
	return month;
}

//function: gets year from user
//accepts : void
//returns : year value entered by user
unsigned short int getDay (unsigned short int month, unsigned long int year)
{
	unsigned short day;

	while (1) {

		setColour (YELLOW);
		printf ("Enter the Day of the Month:\n");
		scanf ("%hu", &day);
		clearBuffer ();

		if (day < 1 || day > getDaysInMonth (month, year)) {
			setColour (RED);
			printf ("Invalid Day\n");
			continue;
		}
		break;
	}
	setColour (DEFAULT);
	return day;
}
