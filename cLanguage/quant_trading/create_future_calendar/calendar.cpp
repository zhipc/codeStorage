#include "calendar.h"


FILE* create_fp()
{
	FILE* fp;
	char filename[256] = { 0 };
	sprintf(filename, "./TradingCalendar_%d.csv", toYear);
	remove(filename);
	fp = fopen(filename, "a");
	return fp;
}

void close_fp(FILE* fp)
{
	if (fp) {
		fclose(fp);
	}
}

Calendar::Calendar()
{
	if (isLeapYear)
		startWeekday = (34 + toYear + toYear / 4 - toYear / 100 + toYear / 400) % 7;
	else
		startWeekday = (35 + toYear + toYear / 4 - toYear / 100 + toYear / 400) % 7;
	setHolidayNomb();
}

void Calendar::getFileName(char* fileName)
{
	int year;
	int month;
	int day;
	int hour;
	currentTime(&year, &month, &day, &hour);
	bool isday = hour < 20 ? true : false;
	getTradingDate_(fileName, year, month, day, isday);
}

void Calendar::getFileName_(char* fileName, int date, int hour)
{
	int year = date / 10000;
	int month = date % 10000 / 100;
	int day = date % 100;
	bool isday = hour < 20 ? true : false;
	getTradingDate_(fileName, year, month, day, isday);
}

void Calendar::createCalender()
{
	FILE* calender_fp = create_fp();
	char quote[4][100];
	int dayQuality = isLeapYear ? 366 : 365;
	bool isDay;
	int date;
	int month;
	int day;
	for (int dayNo = 1; dayNo <= dayQuality; dayNo++)
	{
		date = deNomb(dayNo);
		month = date % 10000 / 100;
		day = date % 100;
		sprintf(quote[0], "%d", date);
		isDay = true;
		sprintf(quote[1], "%d", isDay);
		getTradingDate_(quote[3], toYear, month, day, isDay);
		if ((strcmp(quote[3], "weekend") == 0) || (strcmp(quote[3], "holiday") == 0))
			sprintf(quote[2], "%d", 0);
		else
			sprintf(quote[2], "%d", 1);
		for (int i = 0; i < 3; i++)
			fprintf(calender_fp, "%s,", quote[i]);
		fprintf(calender_fp, "%s\n", quote[3]);
		isDay = false;
		sprintf(quote[1], "%d", isDay);
		getTradingDate_(quote[3], toYear, month, day, isDay);
		if ((strcmp(quote[3], "weekend") == 0) || (strcmp(quote[3], "holiday") == 0))
			sprintf(quote[2], "%d", 0);
		else
			sprintf(quote[2], "%d", 1);
		for (int i = 0; i < 3; i++)
			fprintf(calender_fp, "%s,", quote[i]);
		fprintf(calender_fp, "%s\n", quote[3]);
	}
	close_fp(calender_fp);
}

void Calendar::getTradingDate_(char* date, int year, int month, int day, bool isDay)
{
	if (check(year, month, day) == -1) {
		strcpy(date, "fail");
		return;
	}
	int nomb = getNomb(month, day);
	if (isDay)
	{
		if (isHoliday(nomb))
		{
			strcpy(date, "holiday");
			return;
		}
		if (isWeekend(nomb))
		{
			strcpy(date, "weekend");
			return;
		}
		sprintf(date, "%d", deNomb(nomb));
		return;
	}
	else {
		if (isHoliday(nomb))
		{
			strcpy(date, "holiday");
			return;
		}
		if (isWeekend(nomb))
		{
			strcpy(date, "weekend");
			return;
		}
		int temp = nomb + 1;
		if (isHoliday(temp))
		{
			strcpy(date, "holiday");
			return;
		}
		while (isWeekend(temp))
			temp++;
		if (temp > (isLeapYear ? 366 : 365))
			strcpy(date, "holiday");
		else
			sprintf(date, "%d", deNomb(temp));
		return;
	}
}

int Calendar::deNomb(int nomb)
{
	int month = 0;
	int temp = nomb;
	for (int n = 1; n < 13; n++)
	{
		if (temp <= monthdays(n))
		{
			month = n;
			break;
		}
		else
			temp -= monthdays(n);
	}
	return toYear * 10000 + month * 100 + temp;
}

int Calendar::check(int year, int month, int day)
{
	if (year != toYear)
	{
		printf("year:%d is unavailable!\n", year);
		return -1;
	}
	if ((month > 12) || (month < 1))
	{
		printf("month:%02d is unavailable!\n", month);
		return -1;
	}

	int days = monthdays(month);

	if ((day > days) || (day < 1))
	{
		printf("day:%02d is unavailable!\n", day);
		return -1;
	}
	return 0;
}

int Calendar::monthdays(int n)
{
	switch (n)
	{
	case 0:
		return 0;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
	{
		if (isLeapYear)  //判断是否闰年
			return 29;//闰年 
		else
			return 28;//平年 
	}
	default: return -1;
	}
}

int Calendar::getNomb(int month, int day)
{
	int numb = 0;
	for (int i = 0; i < month; i++)
		numb += monthdays(i);
	numb += day;
	return numb;
}

bool Calendar::isWeekend(int nomb)
{
	int flag = (nomb + startWeekday - 1) % 7;
	if ((flag == 6) || (flag == 0))
		return true;
	else
		return false;
}

bool Calendar::isHoliday(int nomb)
{
	for (int index = 0; index < (sizeof(holidayNomb) / sizeof(int)); index++)
		if (nomb == holidayNomb[index])
			return true;
	return false;
}

void Calendar::setHolidayNomb()
{
	int month, day;
	for (int index = 0; index < (sizeof(holidayList) / sizeof(int)); index++)
	{
		month = holidayList[index] / 100;
		day = holidayList[index] % 100;
		holidayNomb[index] = getNomb(month, day);
	}
}

void Calendar::currentTime(int* year, int* month, int* day, int* hour)
{
	time_t tt = time(NULL);
	struct tm* t = localtime(&tt);
	*year = t->tm_year + 1900;
	*month = t->tm_mon + 1;
	*day = t->tm_mday;
	*hour = t->tm_hour;
	//printf("%d-%02d-%02d %02d\n", *year, *month, *day, *hour);

}


