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

#if 0
// define match[i][j] = 1,  s[0...i-1] matches p[0...j-1]
//                    = 0,  not match
// Recursion:
// if p[j-1] = '*': match[i][j] = 1 iff exist 0 <= k <= i such that s1[0...k-1] matches p[0...j-2]
//                  match[i][j] = match[k][j-1],   0 < k <= i
// if p[j-1] = '.': match[i][j] = match[i-1][j-1]
// if p[j-1] = char: match[i][j] = match[i-1][j-1] && s1[i-1] == s2[j-1]
// Init:
// s2 == *, match
// s2 == ., match one char
bool isMatch(const char *s, const char *p)
{
	int m = strlen(s);
	int n = strlen(p);
	if (strcmp(p, "*") == 0) return true;
	if (strcmp(p, ".") == 0 && m == 1) return true;

	vector<vector<int> > matches(m + 1, vector<int>(n + 1, 0));
	// init
	matches[0][0] = 1;
	for (int j = 1; j <= n; ++j)
	{
		if (p[j-1] != '*') matches[0][j] = 0;
		else matches[0][j] = matches[0][j-1];
	}
	for (int i = 1; i <= m; ++i)
	{
		matches[i][0] = 0;
	}


	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (p[j-1] == '*')
			{
				for (int k = 0; k <= i; ++k)
				{
					if (matches[k][j-1]) 
					{
						matches[i][j] = 1;
						break;
					}
				}
			}
			else if (p[j-1] == '.')
			{
				matches[i][j] = matches[i-1][j-1];
			}
			else
			{
				if (s[i-1] != p[j-1]) matches[i][j] = 0;
				else matches[i][j] = matches[i-1][j-1];
			}
		}
	}

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			cout << " " << matches[i][j];
		}
		cout << endl;
	}

	return matches[m][n];
	
}
#endif //0

bool isMatch(const char* s, const char* p)
{
	int m = strlen(s);
	int n = strlen(p);
	// p is null str
	if (n == 0) return m == 0;

	if (*(p+1) != '*')	// next char is '*'
	{
		// 下一个字符不是'*'，匹配当且仅当当前字符匹配&&剩余子串匹配
		// current char equal or current pattern p is a '.'
		return ( (*p == *s) || (*p == '.' && *s != '\0') ) && isMatch(s+1, p+1);
	}
	else				// next char is not '*'
	{
		// 如果当前字符相等，则判断剩余的串(s) (p+2)是否已经匹配；
		// 如果已经匹配，则直接返回为真
		// 否则继续匹配一个字符后循环
		while ( (*p == *s) || (*p == '.' && *s != '\0') )
		{
			if (isMatch(s, p+2)) return true;
			else s++;
		}
		// 跳出循环后，当前字符指针s,p不再相等,而(p+1)=='*'，因此只需判断
		// 剩余子串是否匹配
		return isMatch(s, p+2);
	}
}

int main()
{
	const char* s = "aab";
	const char* p = "c*a*b";
	bool ans = isMatch(s, p);
	cout << ans << endl;
	return 0;
}