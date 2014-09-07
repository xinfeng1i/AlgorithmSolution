#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool IsPalindrome(const string& s)
{
	if (s == "")
	{
		return true;
	}

	int n = s.size();
	if (s[0] != s[n-1])
	{
		return false;
	}
	else
	{
		return IsPalindrome(s.substr(1, n-2));
	}
}

bool IsTolerable(const string& s, int p)
{
	char maxChar = p - 1 + 'a';
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] > maxChar)
		{
			return false;
		}
	}

	int n = s.size();
	for (int k = 2; k <= n; ++k)
	{
		for (int i = 0; i <= n-k; ++i)
		{
			if (IsPalindrome(s.substr(i, k)))
			{
				return false;
			}
		}
	}

	return true;
}

string StrAddOne(const string& s, int p)
{
	char maxChar = p - 1 + 'a';
	string ans(s);
	int n = ans.size();

	ans[n-1] += 1;
	if (ans[n-1] <= maxChar)
	{
		return ans;
	}

	for (int i = n-1; i >= 0; --i)
	{
		if (ans[i] > maxChar)
		{
			ans[i] = 'a';
			if (i-1 >= 0)
			{
				ans[i-1] += 1;
			}
		}
	}
	return ans;
}

int main()
{
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;

	char maxChar = p - 1 + 'a';
	string maxStr(n, maxChar); 
	
	string ans;
	do
	{
		ans = StrAddOne(s, p);
		if (ans >= maxStr)
		{
			cout << "NO" << endl;
			return 0;
		}

		if (IsTolerable(ans, p))
		{
			cout << ans << endl;
			return 0;
		}

		s = ans;

	}while(true);

	return 0;
}
