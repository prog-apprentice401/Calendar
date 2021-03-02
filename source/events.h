/*
	This header file contains all of the function prototypes for the logs.c
	source file.
*/
#include "date.h"

#define EVENTS_PATH "Events.log"

#ifndef EVENTS_H
	#define EVENTS_H
	typedef struct {
		char message[100];
		Date date;
	} Event;

	void addNewEvent(Date);
#endif //EVENTS_H
