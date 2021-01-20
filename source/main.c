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

int main (int argc, char *argv[])
{
	Date date;
	Point origin = {1, 1};

	while (1) {
		int option = -1;
		setColour (CYAN);
		printf ("Enter:\n"
			"  0 to exit\n"
			"  1 to print a month's calendar\n"
			"  2 to print a year's calendar\n");
		setColour (DEFAULT);
		scanf ("%d", &option);
		clearBuffer ();

		switch (option) {
			case 0:
				setColour (YELLOW);
				printf ("Thanks for using this application\n");
				exit (0);
			case 1:
				date.month = -1;
				date.year = 1599;
				setColour (YELLOW);
				printf ("Enter the month \n"
					"[Jan 1600 is written as 1/1600]\n");
				setColour (DEFAULT);
				scanf ("%d/%d", &date.month, &date.year);
				clearBuffer ();

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
				system ("clear");
				printMonth (date, origin);
				break;
			case 2:
			/*
				setColour (RED);
				printf ("Cannot use feature: under development\n");
				setColour (DEFAULT);
				break;
			*/
				date.month = 1;
				date.year = 1599;

				setColour (YELLOW);
				printf ("Enter the year\n");
				setColour (DEFAULT);

				scanf ("%d", &date.year);
				clearBuffer ();
				
				if (date.year < 1600) {
					setColour (RED);
					printf ("No Record Before 1600\n");
					setColour (DEFAULT);

					break;
				}

				printYear (date);
				
				break;
			default:
				setColour (RED);
				printf ("Invalid Option\n");
				setColour (DEFAULT);
				break;
		}
	}
	return 0;
}
