#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;

	bool operator< (const Date& other) const
	{
		if (year != other.year) return year < other.year;
		else if (month != other.month) return month < other.month;
		else return day < other.day;
	}
};

int main()
{
	//freopen("in.txt", "r", stdin);
	Date illeagal_min_date;
	illeagal_min_date.year = 1814;
	illeagal_min_date.month = 9;
	illeagal_min_date.day = 6;

	Date today;
	today.year = 2014;
	today.month = 9;
	today.day = 6;

	char yong_name[10];
	Date yong_date;
	yong_date.year = 1;
	yong_date.month = 1;
	yong_date.day = 1;

	char old_name[10];
	Date old_date;
	old_date.year = 3000;
	old_date.month = 12;
	old_date.day = 31;

	int cnt = 0;
	int n;
	scanf("%d", &n);
	char name[10];
	Date date;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d/%d/%d", name, &date.year, &date.month, &date.day);
		if (date < illeagal_min_date || today < date) continue;

		cnt++;
		if (date < old_date)
		{
			strcpy(old_name, name);
			old_date = date;
		}

		if (yong_date < date)
		{
			strcpy(yong_name, name);
			yong_date = date;
		}
	}

	if (cnt == 0) printf("%d\n", cnt);
	else printf("%d %s %s\n", cnt, old_name, yong_name);
	return 0;
}

// 注意：可能出现没有合法日期的情况，这是不输出名字 