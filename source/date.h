/*
	This header contains the prototypes of all the functions
	present in the source file datefunctions.c
*/

#ifndef DATE_H
	#define DATE_H
	#define ISLEAP(x) ((x) % 400 == 0 || ((x) % 4 == 0 && (x) % 100 != 0))

	typedef struct {
		unsigned long int year;
		unsigned short int month;
		unsigned short int day;
	} Date;
	
	int getFirstDayOfMonth (Date);
	int getDaysInMonth (unsigned short int, unsigned long int);
	char* getMonthName (int);
	long int compareDates (Date, Date);

#endif	//DATE_FUNCTIONS_H
