#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#if 1
typedef long long llong;

bool isRunNian(llong year)
{
	if ( (year % 4 == 0 && year % 100 != 0) ||
		 (year % 400 == 0))
		 return true;
	return false;
}

// "January", "February", "March", "April", 
// "May", "June", "July", "August", "September", "October", "November" , "December"}
int Month2Int(char month[100])
{
	if (strcmp(month, "January") == 0) return 1;
	else if (strcmp(month, "February") == 0) return 2;
	else if (strcmp(month, "March") == 0) return 3;
	else if (strcmp(month, "April") == 0) return 4;
	else if (strcmp(month, "May") == 0) return 5;
	else if (strcmp(month, "June") == 0) return 6;
	else if (strcmp(month, "July") == 0) return 7;
	else if (strcmp(month, "August") == 0) return 8;
	else if (strcmp(month, "September") == 0) return 9;
	else if (strcmp(month, "October") == 0) return 10;
	else if (strcmp(month, "November") == 0) return 11;
	else if (strcmp(month, "December") == 0) return 12;
	return -1;
}

int cmpTime(char month1[100], int day1, llong year1,
	         char month2[100], int day2, llong year2)
{
	int m1 = Month2Int(month1);
	int m2 = Month2Int(month2);

	if (year1 < year2) return -1;
	else if (year1 == year2)
	{
		if (m1 < m2) return -1;
		else if (m1 == m2) 
		{
			if (day1 < day2) return -1;
			else if (day1 == day2) return 0;
			else return 1;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}

int main()
{
	freopen("data.in", "r", stdin);
	int T = 0;
	scanf("%d\n", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		char month1[100]; int day1; llong year1;
		char month2[100]; int day2; llong year2;
		scanf("%s %d, %lld\n", month1, &day1, &year1);
		scanf("%s %d, %lld\n", month2, &day2, &year2);

		llong sum = 0;
		
		while (cmpTime(month1, day1, year1 + 1, month2, day2, year2) == -1)
		{
			if (Month2Int(month1) == 1 || Month2Int(month1) == 2)
			{
				if (isRunNian(year1)) sum++;
			}
			else
			{
				if (isRunNian(year1 + 1)) sum++;
			}

			year1++;
		}

		if (year1 < year2)
		{
			if (isRunNian(year1) && (Month2Int(month1) == 1 || Month2Int(month1) == 2)) sum++;
			if (isRunNian(year2) && cmpTime(month2, day2, year2, "February", 29, year2) >= 0) sum ++;
		}
		else if (year1 == year2)
		{
			if (isRunNian(year1) && cmpTime(month1, day1, year1, "February", 29, year1) <= 0 &&
				cmpTime(month2, day2, year1, "February", 29, year1) >= 0)
			{
				sum++;
			}
		}

		printf("Case #%d: %lld\n", nCase, sum);
		
	}
	return 0;
}
#endif //0
