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

// 双指针前后步进：
// 初始right指针一直走直到碰到重复字符将经历的字符置为1，更新最长长度，
// 这时可以确定最长不重复子串只能出现在该重复字符第一次出现之后的位置开始
// 从而left指针不断步进，直到碰到重复字符, 同时将经历的字符全部归位为-1
int lengthOfLongestSubstring(string s)
{
	int n = s.size();

	int ans = 0;
	//unordered_map<char, int> chars;
	vector<int> visited(256, -1);
	
	int i = 0;
	int j = 0;
	while (j < n)
	{

		// 右指针移动
		// find the first repeated char
		while (j < n && visited[s[j]] == -1)
		{
			visited[s[j]] = 1;
			j++;
		}

		if (j >= n)
		{
			ans = max(ans, j - i);
			break;
		}
		else
		{
			// 左指针移动
			// find repeated chars
			ans = max(ans, j - i);
			
			while (s[i] != s[j])
			{
				visited[s[i]] = -1;
				i++;
			}
			i++;
			j++;
		}

	}
	return ans;
}

int main()
{
	string s;
	cin >> s;
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
}