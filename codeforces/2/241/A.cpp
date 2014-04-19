#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const long long MIN = -2 * 1000000000;
const long long MAX = 2 * 1000000000;

int main()
{
	int n = 0;
	scanf("%d", &n);

	string sgn;
	long long x;
	string answer;
	long long upper = MAX;
	long long upperEqual = MAX;
	long long lower = MIN;
	long long lowerEqual = MIN;
	for (int i = 0; i < n; ++i)
	{
		cin >> sgn >> x >> answer;
		if (sgn == ">")
		{
			if (answer == "Y")
			{
				lower = max(lower, x);
			}
			else
			{
				upperEqual = min(upperEqual, x);	
			}
		}
		else if (sgn == "<")
		{
			if (answer == "Y")
			{
				upper = min(upper, x);
			}
			else
			{
				lowerEqual = max(lowerEqual, x);
			}
		}
		else if (sgn == ">=")
		{
			if (answer == "Y")
			{
				lowerEqual = max(lowerEqual, x);
			}
			else
			{
				upper = min(upper, x);
			}
		}
		else if (sgn == "<=")
		{
			if (answer == "Y")
			{
				upperEqual = min(upperEqual, x);
			}
			else
			{
				lower = max(lower, x);
			}
		
		}

	}

	bool upperflag, lowerflag;
	long my_upper, my_lower;
	if (upperEqual >= upper)
	{
		upperflag = false;
		my_upper = upper;
	}
	else
	{
		upperflag = true;
		my_upper = upperEqual;
	}

	if (lowerEqual <= lower)
	{
		lowerflag = false;
		my_lower = lower;
	}
	else
	{
		lowerflag = true;
		my_lower = lowerEqual;
	}

	if (lowerflag && upperflag)
	{
		if (my_lower <= my_upper)
		{
			cout << my_lower << endl;
			return 0;
		}
		else
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}
	else if (lowerflag && !upperflag)
	{
		if (my_lower < my_upper)
		{
			cout << my_lower << endl;
			return 0;
		}
		else
		{
			cout << "Impossible" << endl;
			return 0;	
		}
	}
	else if (!lowerflag && upperflag)
	{
		if (my_lower < my_upper)
		{
			cout << my_upper << endl;
			return 0;
		}
		else
		{
			cout << "Impossible" << endl;
			return 0;	
		}
	}
	else if (!lowerflag && !upperflag)
	{
		if (my_upper - my_lower >= 2)
		{
			cout << my_lower + 1 << endl;
			return 0;
		}
		else
		{
			cout << "Impossible" << endl;
			return 0;	
		}
	}

	return 0;

}
