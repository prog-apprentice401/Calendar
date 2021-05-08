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
//returns : 0:success;1:full message may not have been read
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

//function: prints events on given day
//accepts : Date to check for Events
//returns : -1:file error; 0:success; 1:no events found
int printEvents (Date date)
{
	FILE* eventsFile = fopen (EVENTS_FILE_PATH, "rb");
	Event eventRead;
	int eventSearchStatus = 1;  //no events for date

	if (eventsFile == NULL) {
		return -1;  //file error
	}
	while (fread (&eventRead, sizeof(Event), 1, eventsFile) == 1) {
		if (compareDates (eventRead.date, date) == 0) {
			eventSearchStatus = 0;
			printMessage (eventRead.message);
		}
	}
	return eventSearchStatus;
}

//function: prints all events added to the Calendar
//accepts : void
//returns : -1:file error; 0:success; 1:no events found
int printAllEvents (void)
{
	FILE* eventsFile = fopen (EVENTS_FILE_PATH, "rb");
	Event eventRead = {0};
	Date dateLastPrinted = {1}; //must differ

	int eventSearchStatus = 1;  //events not found
	
	if (eventsFile == NULL) {
		return -1;  //file error
	}
	while (fread (&eventRead, sizeof (Event), 1, eventsFile) == 1) {
		eventSearchStatus = 0;  //success
		if (compareDates (eventRead.date, dateLastPrinted) != 0) {
			printf ("\nDate: %hu/%hu/%lu\n"
				"---------\n",
				eventRead.date.day, eventRead.date.month, eventRead.date.year);
			dateLastPrinted = eventRead.date;
		}
		printMessage (eventRead.message);
	}

	return eventSearchStatus;
}

//function: adds Event to Events.log file
//accepts : Event to add
//returns : -1:file error; 0:success; 1:no events found
int addEvent (Event eventToAdd)
{
	FILE* eventsFile = fopen (EVENTS_FILE_PATH, "ri+b");
	FILE* tempEventsFile = fopen (TEMP_EVENTS_FILE_PATH, "wb");
	Event eventRead = {0};
	int eventAddStatus = 1; //faliure adding event

	if (eventsFile == NULL || tempEventsFile == NULL) {
		return -1;  //file error
	}
	while (fread (&eventRead, sizeof (Event), 1, eventsFile) == 1) {
		//adds event in ascending order
		if (compareDates (eventRead.date, eventToAdd.date) > 0) {
			fwrite (&eventToAdd, sizeof (Event), 1, tempEventsFile);
			eventAddStatus = 0;  //success
		}
		fwrite (&eventRead, sizeof (Event), 1, tempEventsFile);
	}
	if (eventAddStatus != 0) {  //couldn't find position
		fwrite (&eventToAdd, sizeof (Event), 1, tempEventsFile);
	}

	fclose (eventsFile);
	fclose (tempEventsFile);

	remove (EVENTS_FILE_PATH);
	rename (TEMP_EVENTS_FILE_PATH, EVENTS_FILE_PATH);

	return eventAddStatus;
}

//function: deletes ALL events on a particular day
//accepts : Date object to delete
//returns : -1:file error; 0:success; 1:no events found
int deleteEvents (Date date)
{
	FILE* eventsFile = fopen (EVENTS_FILE_PATH, "rb");
	FILE* tempEventsFile = fopen (TEMP_EVENTS_FILE_PATH, "w+");
	Event eventRead = {0};
	int deletionStatus = 1;

	if (eventsFile == NULL || tempEventsFile == NULL) {
		return -1;  //file error
	}
	while (fread (&eventRead, sizeof (Event), 1, eventsFile) == 1) {
		if (compareDates (date, eventRead.date) == 0) {
			fwrite (&eventRead, sizeof (Event), 1, tempEventsFile);
		} else {  //this record is not in new file
			deletionStatus = 0;
		}
	}
	fclose (eventsFile);
	fclose (tempEventsFile);

	remove (EVENTS_FILE_PATH);
	rename (TEMP_EVENTS_FILE_PATH, EVENTS_FILE_PATH);

	return deletionStatus;
}
