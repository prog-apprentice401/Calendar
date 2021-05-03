/*
	This is the program for a calender application.
	It allows the user to:
		-Print a particular month's calander
		-Print a particular year's calander

	Project started by Koustubh Srivastava
*/

#include <stdio.h>
#include <stdlib.h>
#include "outputs.h"
#include "inputs.h"
#include "date.h"
#include "utils.h"
#include "events.h"

unsigned long int getYear (void);
unsigned short int getMonth (void);
unsigned short int getDay (unsigned short int, unsigned long int);

void printMenu (void);
void handleMenu (int);

int main (int argc, char *argv[])
{
	int option;

	while (1) {
		printMenu ();
		option = getOption ();
		handleMenu (option);
	}
	return 0;
}


//function: prints option menu
//accepts : void
//returns : void
void printMenu (void)
{
	setColour (CYAN);
	printf ("\nEnter:\n"
		"  0 to exit\n"
		"  1 to print a year's calendar\n"
		"  2 to print a month's calendar\n"
		"  3 to add an event\n"
		"  4 to view events of a day\n"
		"  5 to delete ALL events of a day [under development]\n");
	setColour (DEFAULT);
}

//function: calls appropriate functions based on option
//accepts : option chosen
//returns : void
void handleMenu (int option)
{
	Date date = {0};
	Point origin = {1, 1};
	Event event = {0};
	int returnStatus;  //return status of any function called

	switch (option) {
		case 0:
			setColour (YELLOW);
			printf ("Thanks for using this application\n");
			exit (0);
			break;
		case 1:
			date.year = getYear ();
			printYear (date.year);
			break;
		case 2:
			date.year = getYear ();
			date.month = getMonth ();

			system ("clear");
			printMonth (date, origin);
			break;
		case 3:
			event.date.year = getYear ();
			event.date.month = getMonth ();
			event.date.day = getDay (event.date.month, event.date.year);
			
			returnStatus = getEventMessage (event.message);
			if (returnStatus != 0) {
				setColour (RED);
				printf ("All Characters may not have been read\n");
				setColour (DEFAULT);
			}
			addEvent (event);
			break;
		case 4:
			date.year = getYear ();
			date.month = getMonth ();
			date.day = getDay (date.month, date.year);
			
			returnStatus = printEvents (date);
			setColour (RED);
			if (returnStatus == 1) {
				printf ("printEvents: no records on %hu/%hu/%lu\n",
					date.day, date.month, date.year);
			} else if (returnStatus == -1) {
				printf ("printEvents: error opening Files `%s`;`%s`\n",
					EVENTS_FILE_PATH, TEMP_EVENTS_FILE_PATH);
			}
			setColour (DEFAULT);
			break;
		case 5:
			date.year = getYear ();
			date.month = getMonth ();
			date.day = getDay (date.month, date.year);

			returnStatus = deleteEvents (date);
			setColour (RED);
			if (returnStatus == 1) {
				printf ("deleteEvents: no records for %hu/%hu/%lu\n",
					date.day, date.month, date.year);
			} else if (returnStatus == -1) {
				printf ("deleteEvents: error opening files `%s`; `%s`\n",
					EVENTS_FILE_PATH, TEMP_EVENTS_FILE_PATH);
			}
			/*
			setColour (YELLOW);
			printf ("feature under development, returning\n");
			*/
			break;
		default:
			setColour (RED);
			printf ("Invalid Option\n");
			setColour (DEFAULT);
			break;
	}
}

