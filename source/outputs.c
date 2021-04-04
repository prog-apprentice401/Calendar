/*
	This file contains all the function definitions that print output
	onto the console screen.
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "date.h"
#include "outputs.h"

//function: prints a months' calendar
//accepts : month and year, point to start printing from
//returns : void
void printMonth (Date date, const Point startOn)
{
	int firstDay = getFirstDayOfMonth (date);
	int daysInMonth = getDaysInMonth (date.month, date.year);
	
	if (firstDay == -1) {
		return;
	}

	GOTORC (startOn.r, startOn.c);
	setColour (BLUE);
	printf ("       %s %4lu", getMonthName (date.month), date.year);
	
	CURSOR_DOWN (1);
	CURSOR_LEFT (15);

	setColour (RED);
	printf ("  M  T  W  T  F  S  S");

	CURSOR_DOWN (1);
	CURSOR_LEFT (21);

	setColour (DEFAULT);

	for (int i = 0; i < firstDay; i++) {
		printf ("   ");
	}
	for (int i = 1; i <= daysInMonth; i++) {
		printf ("%3d", i);
		if ((i + firstDay) % 7 == 0) {
			CURSOR_DOWN (1);
			CURSOR_LEFT (21);
		}
	}
}

//function: prints a year's calander from top left of calendar
//accepts : year
//returns : void
void printYear (unsigned long int year)
{
	system ("clear");
	Date date = {year, 1};
	Point cursor = {1, 1};
	
	for (; date.month <= 12; date.month++) {
		printMonth (date, cursor);

		if (date.month % 4 == 0) {
			cursor.r += 8;
			cursor.c = 1;
		} else {
			cursor.c += 22;
		}
	}
}
