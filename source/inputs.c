/*
	Source for functions to take inputs from user
*/
#include <stdio.h>
#include "utils.h"
#include "date.h"

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
