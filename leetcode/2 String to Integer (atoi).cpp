#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		int myAtoi(string s) 
		{
			int n = s.size();
			int i = 0;
			// skip leading spaces
			while (i < n && s[i] == ' ') i++;
			// space str, unvalid return
			if (i >= n) return 0;

			bool positive = true;
			if (s[i] == '+')
			{
				positive = true;
				i++;
			}
			else if (s[i] == '-')
			{
				positive = false;
				i++;
			}
			else if (!(s[i] >= '0' && s[i] <= '9'))
			{
				// is not + - or 0-9, illegal
				return 0;
			}
			
			long long sum = 0;
			while (i < n && s[i] >= '0' && s[i] <= '9')
			{
				sum = 10 * sum + (s[i] - '0');
				
				// over flow
				if (positive == true && sum > INT_MAX)
				{
					return INT_MAX;
				}
				else if (positive == false && -sum < INT_MIN)
				{
					return INT_MIN;
				}
				
				i++;
			}
			

			if (!positive) sum = -sum;
			return sum;

		}
};

int main()
{
	Solution s;
	cout << s.myAtoi("  -345LL") << endl;
	return 0;
}
