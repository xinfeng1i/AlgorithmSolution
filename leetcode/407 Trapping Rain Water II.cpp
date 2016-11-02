#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Cell {
	int r;
	int c;
	int h;
	Cell(int _r=0, int _c=0, int _h=0):r(_r), c(_c), h(_h) {}
	
	bool operator< (const Cell& other) const {
		return h > other.h;
	}
};

int trapRainWater(vector<vector<int>>& height) {
	if (height.empty()) return 0;
	if (height[0].empty()) return 0;
	priority_queue<Cell> Q;
	int ans = 0;
	
	int m = height.size();
	int n = height[0].size();
	
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	// 将四周的元素优先放入优先级队列
	for (int i = 0; i < m; ++i) {
		visited[i][0] = true;
		visited[i][n-1] = true;
		Q.push(Cell(i, 0, height[i][0]));
		Q.push(Cell(i, n-1, height[i][n-1]));
	}
	for (int j = 1; j < n-1; ++j) {
		visited[0][j] = true;
		visited[m-1][j] = true;
		Q.push(Cell(0, j, height[0][j]));
		Q.push(Cell(m-1, j, height[m-1][j]));
	}
	
	// 从第低到高访问每个元素的邻居，如果邻居比当前最低还要低
	// 说明其可以 hold 更多的 water，否则保持高度不变
	int di[4] = {1, -1, 0, 0};
	int dj[4] = {0, 0, 1, -1};
	while (!Q.empty()) {
		Cell cur = Q.top(); Q.pop();
		int i = cur.r;
		int j = cur.c;
		int h = cur.h;
		//printf("i=%d, j=%d, h=%d\n", i, j, h);
		for (int dir = 0; dir < 4; ++dir) {
			int ni = i + di[dir];
			int nj = j + dj[dir];
			if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
				visited[ni][nj]=true;
				int extra = max(0, height[i][j]-height[ni][nj]);
				ans += extra;
				height[ni][nj] += extra;
				Q.push(Cell(ni, nj, height[ni][nj]));
			}
		}
	}
	return ans;
}

int main()
{
	int a1[] = {1, 4, 3, 1, 3, 2};
	int a2[] = {3, 2, 1, 3, 2, 4};
	int a3[] = {2, 3, 3, 2, 3, 1};
	vector<int> v1(a1, a1+6);
	vector<int> v2(a2, a2+6);
	vector<int> v3(a3, a3+6);
	
	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	
	cout << trapRainWater(v) << endl;
	
	return 0;
	
}
