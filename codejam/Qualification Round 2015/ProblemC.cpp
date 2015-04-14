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
int Char2Int(char ch)
{
	if (ch == 'i') return 2;
	else if (ch == 'j') return 3;
	else if (ch == 'k') return 4;
}

vector<vector<int>> table(5, vector<int>(5, 0));
typedef long long llong;

int main()
{
	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);
	table[1][1] = 1; table[1][2] = 2; table[1][3] = 3; table[1][4] = 4;
	table[2][1] = 2; table[2][2] = -1; table[2][3] = 4; table[2][4] = -3;
	table[3][1] = 3; table[3][2] = -4; table[3][3] = -1; table[3][4] = 2;
	table[4][1] = 4; table[4][2] = 3; table[4][3] = -2; table[4][4] = -1;

	int T = 0;
	cin >> T;

	for (int nCase = 1; nCase <= T; ++nCase)
	{
		llong L, X; 
		string str;
		cin >> L >> X;
		cin >> str;
		llong totalLength = L * X;

		int flag = 1;

		llong i = 0;
		int curi = 1;
		bool foundi = false;
		for (i = 0; i < totalLength; ++i)
		{
			int ch = Char2Int(str[i % L]);
			if (ch < 0) { flag = -flag; ch = -ch;}
			curi = table[curi][ch];
			if (curi < 0) {flag = -flag; curi = -curi;}
			if (curi == 2 && flag == 1)
			{
				foundi = true;
				curi = 1;
				i++;
				break;
			}
		}

		bool foundj = false;
		llong j = i;
		for (j = i; j < totalLength; ++j)
		{
			int ch = Char2Int(str[j % L]);
			if (ch < 0) { flag = -flag; ch = -ch;}
			curi = table[curi][ch];
			if (curi < 0) {flag = -flag; curi = -curi;}
			if (curi == 3 && flag == 1)
			{
				foundj = true;
				curi = 1;
				j++;
				break;
			}
		}

		bool foundk = false;
		llong k = j;
		for (k = j; k < totalLength; ++k)
		{
			int ch = Char2Int(str[k % L]);
			if (ch < 0) { flag = -flag; ch = -ch;}
			curi = table[curi][ch];
			if (curi < 0) {flag = -flag; curi = -curi;}
			if (curi == 4)
			{
				foundk = true;
				curi = 1;
				k++;
				break;
			}
		}

		bool found1 = false;
		llong ii = k;
		for (ii = k; ii < totalLength; ++ii)
		{
			int ch = Char2Int(str[ii % L]);
			if (ch < 0) { flag = -flag; ch = -ch;}
			curi = table[curi][ch];
			if (curi < 0) {flag = -flag; curi = -curi;}
		}
		if (curi == 1 && flag == 1) found1 = true;

		cout << "Case #" << nCase << ": ";
		if (foundi && foundj && foundk && found1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
	return 0;
}
#endif //0

#if 1
typedef long long llong;

int table[5][5] = { {0, 0, 0, 0, 0},
	                {0, 1, 2, 3, 4},
					{0, 2, -1, 4, -3},
					{0, 3, -4, -1, 2},
					{0, 4, 3, -2, -1} };

int Char2Int(char ch)
{
	if (ch == '1') return 1;
	else if (ch == 'i') return 2;
	else if (ch == 'j') return 3;
	else if (ch == 'k') return 4;
}

int MultiplyAB(int a, int b)
{
	int sign = 1;
	if (a * b < 0) sign = -1;
	return sign * table[abs(a)][abs(b)];
}

int MyPower(int a, llong n)
{
	if (n == 1) return a;
	else if (n % 2 == 0) return MyPower(MultiplyAB(a, a), n / 2);
	else if (n % 2 != 0) return MultiplyAB(a, MyPower(MultiplyAB(a, a), (n - 1)/2));
}

bool MultiplyAll(llong L, llong X, string s)
{
	int ans = 1;
	for (llong i = 0; i < L; ++i)
	{
		ans = MultiplyAB(ans, Char2Int(s[i]));
	}
	ans = MyPower(ans, X);
	return ans == -1;
}

bool ConstructFirstTwoSubString(llong L, llong X, string s)
{
	int value_i = 1;
	int value_j = 1;
	llong repeated_times = min(8LL, X);
	for (llong i = 0; i < repeated_times * L; ++i)
	{
		if (value_i != 2)
		{
			value_i = MultiplyAB(value_i, Char2Int(s[i % L]));
		}
		else if (value_j != 3)
		{
			value_j = MultiplyAB(value_j, Char2Int(s[i % L]));
		}
	}
	return value_i == 2 && value_j == 3;
}

int main()
{
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		llong L, X;
		string s;
		cin >> L >> X;
		cin >> s;

		bool ok1 = MultiplyAll(L, X, s);
		bool ok2 = ConstructFirstTwoSubString(L, X, s);

		cout << "Case #" << nCase << ": ";
		if (ok1 && ok2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
#endif //0