#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 50000 + 10;
int A[N];
int st[5 * N];
// 注意：线段树的节点数是2 * n - 1, 但是节点编号不是[0, 2n-1]，需要的空间是
//       是 2 * pow(2, ceil(log2(n))) - 1

int getmid(int s, int e)
{
	return s + (e - s) / 2;
}

int buildtree(int* A, int left, int right, int* st, int idx)
{
	assert(left <= right);
	if (left == right) return st[idx] = A[left];

	int mid = getmid(left, right);
	return  (st[idx] = (buildtree(A, left, mid, st, 2 * idx + 1) +
		               buildtree(A, mid + 1, right, st, 2 * idx + 2)));
}

void updateutil(int* A, int i, int diff, int* st, int idx, int s, int e)
{
	if (i < s || i > e) return;
	st[idx] += diff;
	if (s != e)
	{
		int mid = getmid(s, e);
		updateutil(A, i, diff, st, 2 * idx + 1, s, mid);
		updateutil(A, i, diff, st, 2 * idx + 2, mid + 1, e);
	}
}
void update(int* A, int n, int i, int diff, int* st)
{
	A[i] += diff;
	updateutil(A, i, diff, st, 0, 0, n - 1);
}

int getsumutil(int* A, int n, int qs, int qe, int* st, int idx, int s, int e)
{
	if (qs <= s && qe >= e) return st[idx];
	if (qe < s  || qs >  e) return 0;
	int mid = getmid(s, e);
	int leftsum = getsumutil(A, n, qs, qe, st, 2 * idx + 1, s, mid);
	int rightsum = getsumutil(A, n, qs, qe, st, 2 * idx + 2, mid + 1, e);
	return (leftsum + rightsum);
}
int getsum(int* A, int n, int qs, int qe, int* st)
{
	//assert(qs <= qe);
	return getsumutil(A, n, qs, qe, st, 0, 0, n - 1);
}

void solve()
{
	memset(A, 0, sizeof(A));
	memset(st, 0, sizeof(st));
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
	getchar();
	buildtree(A, 0, n - 1, st, 0);
	char cmd[100];
	int i = 0; int diff = 0;
	int qs = 0; int qe = 0;
	while (1)
	{
		memset(cmd, '\0', 100);
		scanf("%s", cmd);
		if (cmd[0] == 'E')
		{
			break;
		}
		else if (cmd[0] == 'A')
		{
			scanf("%d %d", &i, &diff);
			getchar();
			update(A, n, i-1, diff, st);
		}
		else if (cmd[0] == 'S')
		{
			scanf("%d %d", &i, &diff);
			getchar();
			update(A, n, i-1, -diff, st);
		}
		else if (cmd[0] == 'Q')
		{
			scanf("%d %d", &qs, &qe);
			getchar();
			if (qs > qe) swap(qs, qe);
			int tot = getsum(A, n, qs-1, qe-1, st);
			printf("%d\n", tot);
		}
	}
}


int main()
{
	//freopen("in.txt", "r", stdin);
	int T = 0;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		printf("Case %d:\n", nCase);
		solve();
	}
	
	return 0;
}