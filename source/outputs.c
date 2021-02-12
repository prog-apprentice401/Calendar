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
	Point cursor = startOn;

	int firstDay = getFirstDayOfMonth (date);
	int daysInMonth = getDaysInMonth (date.month, ISLEAP (date.year));
	
	if (firstDay == -1) {
		return;
	}

	setColour (BLUE);
	printf ("       %s %4lu", getMonthName (date.month), date.year);
	
	CURSOR_DOWN (1);
	cursor.x += 1;
	CURSOR_LEFT (15);

	setColour (RED);
	printf ("  M  T  W  T  F  S  S");

	CURSOR_DOWN (1);
	cursor.x += 1;
	CURSOR_LEFT (21);

	setColour (DEFAULT);

	for (int i = 0; i < firstDay; i++) {
		printf ("   ");
	}
	for (unsigned char i = 1; i <= daysInMonth; i++) {
		printf ("%3d", i);
		if ((i + firstDay) % 7 == 0) {
			cursor.x += 1;
			CURSOR_DOWN (1);
			CURSOR_LEFT (21);
		}
	}
	cursor.x += 1;
	GOTORC (cursor.x, cursor.y);

	if (cursor.x - startOn.x <= 9) {
		cursor.x += 1;
		GOTORC (cursor.x, cursor.y);
	}
}

//function: prints a year's calander from top left of calendar
//accepts : year
//returns : void
void printYear (Date date)
{
	system ("clear");
	
	Point cursor = {1, 1};
	
	for (date.month = 1; date.month <= 12; date.month++) {
		printMonth (date, cursor);
		cursor.y += 23;

		GOTORC (cursor.x, cursor.y);

		if (date.month % 4 == 0) {
			cursor.x += 8;
			GOTORC (cursor.x, cursor.y = 1);
		}
	}
}
