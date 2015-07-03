#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

bool isIsomorphic(string s, string t)
{
	if (s.size() != t.size()) return false;
	
	map<char, char> table;
	set<char> existValues;	// record the mapped values exist if a->c, then b not -> c
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (table.find(s[i]) == table.end())
		{
			if (existValues.find(t[i]) != existValues.end())
			{
				return false;
			}
			else
			{
				table[s[i]] = t[i];
				existValues.insert(t[i]);
				s[i] = t[i];
			}
		}
		else
		{
			s[i] = table[s[i]];
		}
	}
	return s == t;
}

int main()
{
	string s = "paper";
	string t = "title";
	
	cout << isIsomorphic(s,t) << endl;
	return 0;
}
