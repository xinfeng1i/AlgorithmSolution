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
#include <cstring>
#include <climits>
using namespace std;

typedef long long llong;

struct Point
{
	llong x;
	llong y;
};


int main()
{
	//freopen("data.in", "r", stdin);
	int T = 0;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		llong N, M;
		int A, B;
		cin >> N >> M >> A >> B;

		vector<vector<int>> visited(N + 1, vector<int>(M + 1, 0)); 
		vector<Point> AA(A);
		vector<Point> BB(B);
		llong ans = LLONG_MAX;
		for (int i = 0; i < A; ++i)
		{
			cin >> AA[i].x >> AA[i].y;
			visited[AA[i].x][AA[i].y] = 1;
		}
		for (int i = 0; i < B; ++i)
		{
			cin >> BB[i].x >> BB[i].y;
			visited[BB[i].x][BB[i].y] = 2;
		}

		for (llong x = 1; x <= N; ++x)
		{
			for (llong y = 1; y <= M; ++y)
			{
				if (visited[x][y] != 1)
				{
					llong cost1 = 0;
					for (int i = 0; i < A; ++i)
					{
						cost1 += (AA[i].x - x) * (AA[i].x - x) +
							     (AA[i].y - y) * (AA[i].y - y);
					}

					llong cost2 = (N + M) * 100;
					for (int j = 0; j < B; ++j)
					{
						llong tmp = abs(BB[j].x - x) + abs(BB[j].y - y);
						if (tmp < cost2) cost2 = tmp;
					}

					if (cost1 + cost2 < ans) ans = cost1 + cost2;
				}
			}
		}

		cout << "Case #" << nCase << ": " << ans << endl;
	}

	return 0;
}