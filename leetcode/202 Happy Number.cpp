#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int sumDigitSquare(int n)
{
	int sum = 0;
	while (n != 0)
	{
		int r = n % 10;
		sum += r * r;
		n /= 10;
	}
	cout << "sum = " << sum << endl;
	return sum;
}

bool isHappy(int n)
{
	if (n <= 0) return false;
	
	set<int> table;
	table.insert(n);
	
	while (n != 1)
	{
		// sum the digit^2
		int sum = sumDigitSquare(n);
		
		if (sum == 1)
		{
			return true;
		}
		else
		{
			if (table.find(sum) == table.end())
			{
				table.insert(sum);
				n = sum;
			}
			else
			{
				return false;
			}
		}
				
	}
	
	return true;
}

int main()
{
	cout << isHappy(19) << endl;
	return 0;
}