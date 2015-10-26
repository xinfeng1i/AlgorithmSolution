#include <stdio.h>
#include <stdlib.h>

int MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int IsLeapYear(int year);
int DayRank(int year, int month, int date);

int main()
{
	int year, month, date;
	int days = 0;
	while (scanf("%d/%d/%d", &year, &month, &date) != EOF) {
		days = DayRank(year, month, date);
		printf("%d\n", days);
	}
	return 0;
}

int IsLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int DayRank(int year, int month, int date)
{
	int days = 0, i;
	int flag = IsLeapYear(year);
	if (flag) MONTH[1] = 29;
	else MONTH[1] = 28;
	for (i = 0; i < month - 1; ++i) days += MONTH[i];
	days += date;
	return days;
}
