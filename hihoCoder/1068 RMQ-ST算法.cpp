#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
using namespace std;

const int MAXN = 1000010;
vector<int> weight(MAXN, 0);
vector<vector<int>> preCalc(MAXN, vector<int>(32, 0));

void Init(int n)
{
	for (int i = 0; i < n; ++i) {
		preCalc[i][0] = weight[i]; // 2^j = len
	}

	for (int j = 1; (1<<j) <= n; j++) { // 2^j = len
		for (int i = 0; i < n; ++i) {
			if (i+(1<<j-1) < n) {
				preCalc[i][j] = min(preCalc[i][j-1], preCalc[i+(1<<j-1)][j-1]);
			} else {
				preCalc[i][j] = preCalc[i][j-1];
			}
		}
	}
}

int query(int L, int R) {
	int curLen = R - L + 1;
	for (int j = 30; j >= 0; j--) {
		if ((curLen >> j) & 1) {
			return min(preCalc[L][j], preCalc[R+1-(1<<j)][j]);
		}
	}	
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &weight[i]);
	}

	Init(n);

	int q;
	scanf("%d", &q);
	int l, r;
	int ans = -1;
	for (int i = 0; i < q; ++i) {
		scanf("%d %d", &l, &r);
		l -= 1;
		r -= 1;
		ans = query(l, r);
		printf("%d\n", ans);
	}

	return 0;
}