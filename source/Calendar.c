/*
	This is the program for a calender application.
	It allows the user to:
		-Print a particular month's calander
		-Print a particular year's calander

	Project started by Koustubh Srivastava
*/
#include <stdio.h>
#include <stdlib.h>

#define ISLEAP(x) ((x) % 400 == 0 || ((x) % 4 == 0 && (x) % 100 != 0))
#define clearScreen() system ("clear");
typedef struct {
	int year;
	int month;
} Date;

typedef enum {
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	DEFAULT,
} Colours;

void printMonth (Date);
int getFirstDayOfMonth (Date);
int getDaysInMonth (int, _Bool);
char* getMonthName (int);
void clearBuffer (void);

void setColour (Colours);

int main (int argc, char *argv[])
{
	int option = 1;
	Date date;

	while (1) {
		clearScreen ();
		printf ("Enter:\n"
		        "  1 to print a particular month\n");
		scanf ("%d", &option);

		switch (option) {
			case 1:
				clearScreen ();
				printf ("Enter the month \n"
				        "ex: Jan 1600 is written as 1/1600\n");
				scanf ("%d/%d", &date.month, &date.year);
				if (date.year < 1600) {
					setColour (RED);
					printf ("No record before Jan 1600\n");
					setColour (DEFAULT);
					break;
				}
				if (date.month < 1 || date.month > 12) {
					setColour (RED);
					printf ("Invalid Month\n");
					setColour (DEFAULT);
					break;
				}
				printMonth (date);
				break;
			defualt:
				fputs ("Invalid Option", stderr);
				break;
		}
		getchar();
		clearBuffer ();
	}
}

void printMonth (Date date)
{
	printf ("\n\n");
	int firstDay = getFirstDayOfMonth (date);
	int daysInMonth = getDaysInMonth (date.month, ISLEAP (date.year));
	
	if (firstDay == -1) {
		return;
	}
	setColour (BLUE);
	printf ("       %s %4d\n", getMonthName (date.month), date.year);
	setColour (RED);
	printf ("  M  T  W  T  F  S  S\n");
	setColour (DEFAULT);

	for (int i = 0; i < firstDay; i++) {
		printf ("   ");
	}
	for (int i = 1; i <= daysInMonth; i++) {
		printf ("%3d", i);
		if ((i + firstDay) % 7 == 0) {
			printf ("\n");
		}
	}
	printf ("\n\n");
	return;
}

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
		printf ("%d\n", firstDay);
		if (ISLEAP (i)) {
			firstDay += 2;
		} else {
			firstDay++;
		}
		firstDay %= 7;
		printf ("%d\n", firstDay);
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

void setColour (Colours colour)
{
	switch (colour) {
		case RED: printf ("\033[1;31m"); break;
		case GREEN: printf ("\033[1;32m"); break;
		case YELLOW: printf ("\033[1;33m"); break;
		case BLUE: printf ("\033[1;34m"); break;
		case MAGENTA: printf ("\033[1;35m"); break;
		case CYAN: printf ("\033[1;36m"); break;
		case DEFAULT: printf ("\033[0;0m"); break;
		default: break;
	}
	return;
}

void clearBuffer (void)
{
	char dump;
	while ((dump = getchar ()) != '\n' && dump != EOF)
		;
}
