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

unordered_map<string, int> records;

bool wordBreak(string s, unordered_set<string> &dict) 
{
	// base case
	if (s == "") return true;

	// have been judged before
	if (records.find(s) != records.end())
	{
		return records[s];	
	}

	// recursive
	int n = s.size();
	for (int len = 1; len <= n; ++len)
	{
		string firstWord = s.substr(0, len);
		if (dict.find(firstWord) == dict.end()) records[firstWord] = 0;
		else records[firstWord] = 1;

		bool flag = wordBreak(s.substr(len), dict);
		if (flag) records[s.substr(len)] = 1;
		else records[s.substr(len)] = 0;

		if (records[firstWord] && records[s.substr(len)]) return true;

	}
	return false;
}

// Method 2: bottom to up
// Reference: http://fisherlei.blogspot.jp/2013/11/leetcode-word-break-solution.html
// define:
// possible[i+1] = s[0...i] can be break up, then
// possible[i+1] = true  if s[0...i] in the dict
// possible[i+1] = true  if exist some k such that possible[k] = true && s[k+1,i] in dict
// possible[i+1] = false otherwise

bool wordBreak2(string s, unordered_set<string> &dict)
{
	int n = s.size();
	deque<bool> possible(n + 1, false);
	possible[0] = true;
	for (int i = 1; i <= n; ++i)
	{
		for (int k = 0; k < i; ++k)
		{
			possible[i] = possible[k] && dict.find(s.substr(k, i - k)) != dict.end();
			if (possible[i]) break;
		}
	}
	return possible[n];
}

int main()
{
	string s("leetcode");
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	dict.insert("");
	bool ans = wordBreak2(s, dict);
	cout << ans << endl;
	return 0;
}