/*
	This header contains the prototypes of all the functions
	present in the source file datefunctions.c
*/

#ifndef DATE_H
	#define DATE_H


	#define ISLEAP(x) ((x) % 400 == 0 || ((x) % 4 == 0 && (x) % 100 != 0))

	typedef struct {
		int year;
		int month;
	} Date;
	
	int getFirstDayOfMonth (Date);
	int getDaysInMonth (int, _Bool);
	char* getMonthName (int);
	void printMonth (Date);

#endif	//DATE_FUNCTIONS_H