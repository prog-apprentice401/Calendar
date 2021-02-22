/*
	This source file contains all of the functions required to add logs
	in the application.
*/
#include <stdio.h>
#include "utils.h"
#include "date.h"
#include "logs.h"

void addNewEvent (Date date)
{
	Event tempEvent = {0};
	Event input = {0};
	int maxMessageLength = sizeof (input.message);
	int charactersRead;

	FILE* eventFile = NULL;

	if ((eventFile = fopen (EVENTS_PATH, "r+")) == NULL) {
		setColour (RED);
		printf ("Events.log file not found!\n");
		setColour (DEFAULT);

		return;
	}

	printf ("\n\nEnter the reminder (max 100 characters)\n");
	charactersRead = getline ((char**) &input.message, (size_t*) &maxMessageLength, stdin);
	
	if (charactersRead >= sizeof (input.message)) {
		setColour (CYAN);
		printf ("Note: All characters may not have been read\n");
		setColour (DEFAULT);
	}

	while (fread (&tempEvent, sizeof (Event), 1, eventFile) != 0 
		&& !dateIsLessThan (tempEvent.date, date))
		;

	fwrite (&input, sizeof (input), 1, eventFile);

	setColour (BLUE);
	printf ("Successfully added log\n\n");
	setColour (DEFAULT);

	fclose (eventFile);
}
