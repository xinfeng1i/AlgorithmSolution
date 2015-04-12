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