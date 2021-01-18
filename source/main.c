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

typedef enum {
	RED = 31,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	DEFAULT = 0,
} Colours;

void printMonth (Date);
void clearBuffer (void);

void setColour (Colours);

int main (int argc, char *argv[])
{
	int option = -1;
	Date date;

	while (1) {
		printf ("Enter:\n"
		        "  1 to print a particular month\n");
		scanf ("%d", &option);
		printf ("You chose: %d\n", option);
		clearBuffer();

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
				fputs ("Invalid Option\n", stdout);
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
