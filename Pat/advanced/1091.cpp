#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#if 1
struct CubeIndex {
	int K;
	int I;
	int J;
	CubeIndex(int k, int i, int j) : K(k), I(i), J(j) {}
};

int M, N, L, T;

void IterativeDFS(int kk, int ii, int jj, int& count,
	vector<vector<vector<int>>>& cube, 
	vector<vector<vector<bool>>>& visited)
{
	stack<CubeIndex> s;
	CubeIndex curIndex(kk, ii, jj);
	visited[kk][ii][jj] = true;
	count += 1;
	s.push(curIndex);
	while (!s.empty()) {
		CubeIndex temp = s.top();	
		s.pop();

		int k = temp.K;
		int i = temp.I;
		int j = temp.J;
		if (k+1 < L && cube[k+1][i][j] == 1 && !visited[k+1][i][j]) {
			visited[k+1][i][j] = true;
			count += 1;
			s.push(CubeIndex(k+1, i, j));
		}
		if (k-1 >= 0 && cube[k-1][i][j] == 1 && !visited[k-1][i][j]) {
			visited[k-1][i][j] = true;
			count += 1;
			s.push(CubeIndex(k-1, i, j));
		}
		if (i+1 < M && cube[k][i+1][j] == 1 && !visited[k][i+1][j]) {
			visited[k][i+1][j] = true;
			count += 1;
			s.push(CubeIndex(k, i+1, j));
		}
		if (i-1 >= 0 && cube[k][i-1][j] == 1 && !visited[k][i-1][j]) {
			visited[k][i-1][j] = true;
			count += 1;
			s.push(CubeIndex(k, i-1, j));
		}
		if (j+1 < N && cube[k][i][j+1] == 1 && !visited[k][i][j+1]) {
			visited[k][i][j+1] = true;
			count += 1;
			s.push(CubeIndex(k, i, j+1));
		}
		if (j-1 >= 0 && cube[k][i][j-1] == 1 && !visited[k][i][j-1]) {
			visited[k][i][j-1] = true;
			count += 1;
			s.push(CubeIndex(k, i, j-1));
		}
	}
}

void DFS(int k, int i, int j, int& count,
	vector<vector<vector<int>>>& cube, 
	vector<vector<vector<bool>>>& visited) 
{
	visited[k][i][j] = true;
	count += 1;
	if (k+1 < L && cube[k+1][i][j] == 1 && !visited[k+1][i][j]) 
		DFS(k+1, i, j, count, cube, visited);
	if (k-1 >= 0 && cube[k-1][i][j] == 1 && !visited[k-1][i][j]) 
		DFS(k-1, i, j, count, cube, visited);
	if (i+1 < M && cube[k][i+1][j] == 1 && !visited[k][i+1][j])
		DFS(k, i+1, j, count, cube, visited);
	if (i-1 >= 0 && cube[k][i-1][j] == 1 && !visited[k][i-1][j])
		DFS(k, i-1, j, count, cube, visited);
	if (j+1 < N && cube[k][i][j+1] == 1 && !visited[k][i][j+1])
		DFS(k, i, j+1, count, cube, visited);
	if (j-1 >= 0 && cube[k][i][j-1] == 1 && !visited[k][i][j-1])
		DFS(k, i, j-1, count, cube, visited);

}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> M >> N >> L >> T;

	vector<vector<vector<int>>> cube(L, vector<vector<int>>(M, vector<int>(N, 0)));
	for (int k = 0; k < L; ++k) {
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> cube[k][i][j];
			}
		}
	}

	int ans = 0;
	vector<vector<vector<bool>>> visited(L, vector<vector<bool>>(M, vector<bool>(N, false)));

	for (int k = 0; k < L; ++k) {
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (cube[k][i][j] == 1 && !visited[k][i][j]) {
					int count = 0;
					IterativeDFS(k, i, j, count, cube, visited);
					if (count >= T) ans += count;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}

#endif // 0