/*
	This source file contains all of the functions that relate
	calculation of dates.
*/
#include <stdio.h>
#include "utils.h"
#include "date.h"

int getFirstDayOfMonth (Date date)
{
	if (date.year < 1600) {
		fputs ("\nNo record before 1600\n", stderr);
		return -1;
	}
	
	int firstDay = 5;	//first Jan 1600 was Saturday

	for (int i = 1600; i < date.year - date.year % 100; i+= 100) {	//first calculate day on first Jan of year
		if (ISLEAP (i)) {
			firstDay += 6;
		} else {
			firstDay += 5;
		}
		firstDay %= 7;
	}

	for (int i = date.year - date.year % 100; i < date.year; i++) {
		if (ISLEAP (i)) {
			firstDay += 2;
		} else {
			firstDay++;
		}
		firstDay %= 7;
	}

	for (int i = 1; i < date.month; i++) {	//caluclate first day of given month
		firstDay += getDaysInMonth (i, ISLEAP (date.year));
		firstDay %= 7;
	}

	return firstDay;
}


int getDaysInMonth (int month, _Bool isLeapYear)
{
	switch (month) {
		case 1 : return 31;
		case 2 : return (isLeapYear) ? 29 : 28;
		case 3 : return 31;
		case 4 : return 30;
		case 5 : return 31;
		case 6 : return 30;
		case 7 : return 31;
		case 8 : return 31;
		case 9 : return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
	}
	return 0;
}


char* getMonthName (int month)
{
	switch (month) {
		case 1 : return "Jan";
		case 2 : return "Feb";
		case 3 : return "Mar";
		case 4 : return "Apr";
		case 5 : return "May";
		case 6 : return "Jun";
		case 7 : return "Jul";
		case 8 : return "Aug";
		case 9 : return "Sep";
		case 10: return "Oct";
		case 11: return "Nov";
		case 12: return "Dec";
	}
	return NULL;
}

