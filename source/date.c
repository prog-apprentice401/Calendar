/*
	This source file contains all of the functions that relate
	calculation of dates.
*/
#include <stdio.h>
#include "utils.h"
#include "date.h"

//function: calculate first day , Mon = 0, Sun = 7
//accepts : month (member of Date) to calculate for
//returns : first day of month, Mon = 0 Sun = 7
int getFirstDayOfMonth (Date date)
{
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
		firstDay += getDaysInMonth (i, date.year);
		firstDay %= 7;
	}
	return firstDay;
}

//function: gets number of days in a month
//accepts : month, _Bool value of leap status
//returns : days in month
int getDaysInMonth (unsigned short int month, unsigned long int year)
{
	switch (month) {
		case 1 : return 31;
		case 2 : return (ISLEAP (year)) ? 29 : 28;
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

//function: gets name of a month
//accepts : month number
//returns : month name as string
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

//function: checks if date1 comes before date2
//accepts : first date and seconds date
//returns : 1 if date1 is less or equal to date2, else 0
int dateIsLessThan (Date date1, Date date2)
{
	if (date1.year <= date2.year) {
		return 1;
	} else if (date1.month <= date2.month) {
		return 1;
	} else if (date1.day <= date2.day) {
		return 1;
	} else {
		return 0;
	}
}
