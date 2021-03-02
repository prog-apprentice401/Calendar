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
	int charactersRead;
	int maxMessageLength = sizeof (input.message);

	FILE* eventFile = NULL;

	if ((eventFile = fopen (EVENTS_PATH, "a+")) == NULL) {
		setColour (RED);
		printf ("Events.log: file not found, could not be created\n"
			"Aborting operation\n");
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

	while (fread (&tempEvent, sizeof (Event), 1, eventFile) != 0) {
		if (dateIsLessThan (input.date, tempEvent.date)) {
			break;
		}
	}

	fwrite (&input, sizeof (input), 1, eventFile);
	fclose (eventFile);

	setColour (BLUE);
	printf ("Successfully added log\n\n");
	setColour (DEFAULT);
}
