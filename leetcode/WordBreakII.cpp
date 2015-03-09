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

unordered_map<string, vector<string> > records;
vector<string> wordBreak(string s, unordered_set<string> &dict) 
{
	if (records.find(s) != records.end()) return records[s];
	vector<string> ans;

	for (size_t i = 1; i <= s.size(); ++i)
	{
		// find each prefix
		string prefix = s.substr(0, i);
		// if prefix in dict
		if (dict.find(prefix) != dict.end())
		{
			// if the prefix is the last word
			if (s.substr(i) == "")
			{
				ans.push_back(prefix);
			}
			else
			{
				prefix = prefix + " ";
				// find all suffix strs
				vector<string> suffixStrs = wordBreak(s.substr(i), dict);
				for (size_t j = 0; j < suffixStrs.size(); ++j)
				{
					ans.push_back(prefix + suffixStrs[j]);
				}

			}
		}
	}
	
	records[s] = ans;
	return ans;
}

int main()
{
	string s = "catsanddog";
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	vector<string> ans = wordBreak(s, dict);
	for (size_t i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
	return 0;
}