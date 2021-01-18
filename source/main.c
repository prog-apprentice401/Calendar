/*
	This is the program for a calender application.
	It allows the user to:
		-Print a particular month's calander
		-Print a particular year's calander

	Project started by Koustubh Srivastava
*/
#include <stdio.h>
#include "date.h"
#include "utils.h"


int main (int argc, char *argv[])
{
	int option = -1;
	Date date;

	while (1) {
		setColour (BLUE);
		printf ("Enter:\n"
		        "  1 to print a month's calendar\n");
		setColour (DEFAULT);
		scanf ("%d", &option);
		setColour (GREEN);
		printf ("You chose: %d\n\n", option);

		switch (option) {
			case 1:
				setColour (YELLOW);
				printf ("Enter the month \n"
				        "ex: Jan 1600 is written as 1/1600\n");
				setColour (DEFAULT);
				scanf ("%d/%d", &date.month, &date.year);
				clearBuffer();
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
			default:
				setColour (RED);
				fputs ("Invalid Option\n", stderr);
				setColour (DEFAULT);
				break;
		}
		clearBuffer (); //to handle any other letters the user may enter
	}
}

void setColour (Colours colour)
{
	printf ("\033[1;%dm", colour);	
}

void clearBuffer (void)
{
	char dump;
	while ((dump = getchar ()) != '\n' && dump != EOF)
		;
}
