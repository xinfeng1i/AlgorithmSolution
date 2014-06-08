#include <iostream>
#include <string>
using namespace std;

/* MinCut[n] = min{1 + MinCut[i] + MinCut[n-i]}, for i = 1:n-1
 * string s;
 * if (isPalindrome(s)) MinCut = 0;
 */

/*
 * MinCut(s, i, j) = min{MinCut(s, i, k) + MinCut(s, k+1, j) + 1};
 * for k >= i && k + 1 <= j, i <=j;
 *
 * MinCut(s, i, j) = 0; if (s.substr(i...j) is Palindrome);
 */

int MinPalindromePartition(string s)
{
	int n = s.size();
	
	int cut[n][n];

	// init
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cut[i][j] = max(j - i, 0);
		}
	}
	for (int i = 0; i < n; ++i) cut[i][i] = 0;


	// bottom
	for (int l = 2; l <= n; ++l)
	{
		for (int i = 0; i <= n-l; ++i)
		{
			int j = i + l - 1;
			for (int k = i; k+1 <= j; ++k)
			{
				if (cut[i][k] + cut[k+1][j] + 1 < cut[i][j])
				{
					cut[i][j] = cut[i][k] + cut[k+1][j] + 1;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << " " << cut[i][j];
		}
		cout << endl;
	}
	cout << endl;

	return cut[0][n-1];
}

int main()
{
	string s = "ababbbabbababa";
	int ans = MinPalindromePartition(s);
	cout << ans << endl;
	return 0;
}
