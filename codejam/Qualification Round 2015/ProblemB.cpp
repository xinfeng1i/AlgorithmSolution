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

int solve(vector<int>& plates, int D)
{
	// suppose after moving within x minites eat up
	int totAns = 2000;
	for (int x = 1; x <= 1000; ++x)
	{
		int total_move = 0;
		for (int i = 0; i < D; ++i)
		{
			// if current plate have more than x cakes, then we need
			// move some time
			if (plates[i] > x)
			{
				total_move += ceil((plates[i] + 0.0) / (x + 0.0)) - 1;
			}
		}
		int curAns = total_move + x;

		totAns = min(totAns, curAns);
	}
	return totAns;
}

int main()
{
	//freopen("B-small-practice.in", "r", stdin);
	//freopen("B-small-practice.out", "w", stdout);
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		int D = 0;
		cin >> D;
		vector<int> plates(D, 0);
		for (int i = 0; i < D; ++i)
		{
			cin >> plates[i];
		}
		int ans = solve(plates, D);
		cout << "Case #" << nCase << ": " << ans << endl;
	}
	return 0;
}