#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

map<char, int> table;           // current char count hashtable
map<char, int> const_table;     // all we need char hashtable


string minWindow(string s, string t)
{
    // init hash table
    for (size_t i = 0; i < t.size(); ++i)
    {
        table[t[i]] = 0;
		const_table[t[i]] += 1;
    }
    
    // ans init
    int ans_len = INT_MAX;
    int ans_begin = 0;
    
    
    int n = s.size();
    int m = t.size();
    int i = 0;
    int j = 0;
    int count = 0;
    while (j < n)
    {
        if (table.find(s[j]) != table.end())
        {
            if (table[s[j]] < const_table[s[j]]) count++;
            table[s[j]]++;

            while (count == m)
            {
            	if (table.find(s[i]) != table.end())
				{
					int len = j - i + 1;
                    if (len < ans_len)
                    {
                        ans_len = len;
                        ans_begin = i;
                    }
                    
                    if (table[s[i]] <= const_table[s[i]]) count--;
                    table[s[i]]--;
				}
				i++;
            }
        }
        j++;
    }
    
    if (ans_len == INT_MAX) return "";
    else return s.substr(ans_begin, ans_len);
}

int main()
{
    string s = "AAABC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}
