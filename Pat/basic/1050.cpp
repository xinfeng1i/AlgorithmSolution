#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	vector<int> v(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	int m = N, n = 1;
	for (int i = N; i >= 1; --i) {
		if (N % i == 0) {
			int j = N / i;
			if (i < j) {
				break;
			}
			else if (i < m) {
				m = i;
				n = j;
			}
		}
	}

	sort(v.begin(), v.end(), greater<int>());

	vector<vector<int> > grid(m, vector<int>(n, 0));
	int x0 = 0;
	int y0 = 0;
	int xmax = m;
	int ymax = n;
	int idx = 0;
	int sz = v.size();
	while (idx < sz) {
		int x = x0;
		int y = y0;
		while (y < ymax) grid[x][y++] = v[idx++];  // right
		if (idx >= sz) break;

		y--; x++;
		while (x < xmax) grid[x++][y] = v[idx++]; // down
		if (idx >= sz) break;

		x--; y--;
		while (y >= y0) grid[x][y--] = v[idx++]; // left
		if (idx >= sz) break;

		y++; x--;
		while (x > x0) grid[x--][y] = v[idx++]; // up
		if (idx >= sz) break;

		x0 += 1;
		y0 += 1;
		xmax -= 1;
		ymax -= 1;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == 0) cout << grid[i][j];
			else cout << " " << grid[i][j];
		}
		cout << endl;
	}

	return 0;
}
