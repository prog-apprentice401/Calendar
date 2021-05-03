/*
	Source file for all functions related to adding and removing Events
*/
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "events.h"
#include "utils.h"

//function: gets event message from user
//accepts : character array to store message
//returns : 0 if all ok, 1 if message was too long
int getEventMessage (char message[])
{
	int maxMessageLength = MAX_MESSAGE_LENGTH;
	int charsRead;
	
	printf ("Enter the message [max: 100 cahracters]:\n");
	charsRead = getline (&message, (unsigned long *) &maxMessageLength, stdin);

	if (charsRead >= maxMessageLength) {
		return 1; //all cahracters may not have been read
	}
	return 0;
}

//function: adds Event to Events.bin file
//accepts : Event to add
//returns : status of write
int addEvent (Event event)
{
	FILE * eventsFile = fopen (EVENTS_FILE_PATH, "a+b");

	if (eventsFile == NULL) {
		setColour (RED);
		printf ("error: addEvent(): could not open Events.log file");
		return -1;
	}
	fwrite (&event, sizeof (Event), 1, eventsFile);
	fclose (eventsFile);
	return 0;
}

//function: prints all events on given day
//accepts : Date to check for Events
//returns : 0 if events found, -1 otherwise
int printEvents (Date date)
{
	FILE* eventsFile = fopen (EVENTS_FILE_PATH, "rb");
	Event eventRead;
	int eventSearchStatus = -1;

	if (eventsFile == NULL) {
		setColour (RED);
		printf ("printevents: file Events.log not found, returning\n");
		setColour (DEFAULT);

		return eventSearchStatus;
	}
	while (fread (&eventRead, sizeof(Event), 1,
		eventsFile) == 1) {
		if (compareDates (eventRead.date, date) == 0) {
			eventSearchStatus = 0; //successful

			setColour (CYAN);
			printf ("Message: ");
			setColour (DEFAULT);
			printf ("%s", eventRead.message);
			printf ("\n");
		}
	}
	return eventSearchStatus;
}
