/* time example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <iostream>

#if 0
int main()
{
	time_t timer;
	struct tm y2k = { 0 };
	double seconds;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 119; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	seconds = difftime(timer, mktime(&y2k));

	printf("%.f seconds since January 1, 2000 in the current timezone", seconds);

	system("pause");

	return 0;
}

#endif

#if 1
int main()
{
	time_t rawtime;
	struct tm * timeinfo;
	int year, month, day;
	const char * weekday[] = { "Sunday", "Monday",
		"Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday" };

	/* prompt user for date */
	//printf("Enter year: "); fflush(stdout); scanf("%d", &year);
	//printf("Enter month: "); fflush(stdout); scanf("%d", &month);
	//printf("Enter day: "); fflush(stdout); scanf("%d", &day);

	year = 2019;
	month = 4;
	day = 16;

	/* get current timeinfo and modify it to the user's choice */
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	/* call mktime: timeinfo->tm_wday will be set */
	mktime(timeinfo);

	printf("That day is a %s.\n", weekday[timeinfo->tm_wday]);

	return 0;
}

#endif
