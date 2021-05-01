/*
	Header file for events.c source file
*/
#include "date.h"

#ifndef __EVENTS_H__
	#define __EVENTS_H__

	#define MAX_MESSAGE_LENGTH 101
	#define EVENTS_FILE_PATH "Events.log"
	
	typedef struct Event {
		char message[MAX_MESSAGE_LENGTH + 1];
		Date date;
	} Event;

	int getEventMessage (char[]);
	int addEvent (Event);
	int printEvents (Date);
	
#endif //__EVENTS_H__
