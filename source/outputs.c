/*
	This file contains all the function definitions that print output
	onto the console screen.
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "date.h"
#include "outputs.h"

//function: prints a months calendar
//format:   [monthName year];\n [weekdays' names];\n [dates]
//recieves: Date structure with month and year, point to start printing from
//returns:  number of lines used to print month

void printMonth (Date date, const Point startOn)
{
	Point cursor = startOn;

	int firstDay = getFirstDayOfMonth (date);
	int daysInMonth = getDaysInMonth (date.month, ISLEAP (date.year));
	
	if (firstDay == -1) {
		return;
	}

	setColour (BLUE);
	printf ("       %s %4d", getMonthName (date.month), date.year);
	GOTOXY (cursor.x += 1, cursor.y);
	setColour (RED);
	printf ("  M  T  W  T  F  S  S");

	GOTOXY (cursor.x += 1, cursor.y);

	setColour (DEFAULT);

	for (int i = 0; i < firstDay; i++) {
		printf ("   ");
	}
	for (int i = 1; i <= daysInMonth; i++) {
		printf ("%3d", i);
		if ((i + firstDay) % 7 == 0) {
			GOTOXY (cursor.x += 1, cursor.y);
		}
	}
	GOTOXY (cursor.x += 1, cursor.y);

	if (cursor.x - startOn.x <= 9) {
		GOTOXY (cursor.x += 1, cursor.y);
	}
}

//function: prints a year's calander
//format:   four months in a row, three rows
//recieves: Date structure with year
//returns:  void

void printYear (Date date)
{
	system ("clear");
	
	Point cursor = {1, 1};
	
	for (date.month = 1; date.month <= 12; date.month++) {
		printMonth (date, cursor);
		cursor.y += 23;

		GOTOXY (cursor.x, cursor.y);

		if (date.month % 4 == 0) {
			GOTOXY (cursor.x += 8, cursor.y = 1);
		}
	}
}
