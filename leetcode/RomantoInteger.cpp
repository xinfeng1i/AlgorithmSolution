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
using namespace std;

int romanToInt(string s)
{
	unordered_map<char, int> table;
	table['I'] = 1;
	table['V'] = 5;
	table['X'] = 10;
	table['L'] = 50;
	table['C'] = 100;
	table['D'] = 500;
	table['M'] = 1000;

	int n = s.size();
	int i = 0;
	int num = 0;
	while (i < n)
	{
		char ch = s[i];
		
		if (ch == 'I' && i + 1 < n && s[i+1] == 'V')
		{
				num += 4;
				i += 2;
		}
		else if (ch == 'I' && i + 1 < n && s[i+1] == 'X')
		{
				num += 9;
				i += 2;
		}
		else if (ch == 'X' && i + 1 < n && s[i+1] == 'L')
		{

				num += 40;
				i += 2;
		}
		else if (ch == 'X' && i + 1 < n && s[i+1] == 'C')
		{
				num += 90;
				i += 2;					
		}
		else if  (ch == 'C' && i + 1 < n && s[i+1] == 'D')
		{
				num += 400;
				i += 2;
		}
		else if (ch == 'C' && i + 1 < n && s[i+1] == 'M')
		{
				num += 900;
				i += 2;
		}
		else
		{
			num += table[ch];
			i++;
		}
	}
	return num;
}

int main()
{
	string s;
	cin >> s;
	cout << romanToInt(s) << endl;
	return 0;
}