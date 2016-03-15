#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
using namespace std;

struct Elem {
	int len;
	int time;

	Elem(int l=-1, int t=-1):len(l), time(t) {}
};

const int MAXN = 510;
Elem G[MAXN][MAXN];
int n = 0;
int m = 0;
int src = -1;
int dest = -1;

int ChooseMinDist(const vector<int>& dist, vector<bool>& visited) {
	int minDist = INT_MAX;
	int minIdx = -1;
	for (int i = 0; i < n; ++i) {
		if (!visited[i] && dist[i] <minDist) {
			minDist = dist[i];
			minIdx = i;
		}
	}
	return minIdx;
}

vector<int> Dijkstra(int s, vector<vector<int>>& prev) {
	vector<int> dist(n, INT_MAX);
	vector<bool> visited(n, false);
	dist[s] = 0;

	for (int i = 0; i < n; ++i) {
		int u = ChooseMinDist(dist, visited);
		visited[u] = true;
		for (int v = 0; v < n; ++v) {
			if (G[u][v].len != -1 && 
				dist[u] != INT_MAX && dist[u] + G[u][v].len < dist[v]) {
					dist[v] = dist[u] + G[u][v].len;
					prev[v].clear();
					prev[v].push_back(u);
				
			} else if (G[u][v].len != -1 && 
				dist[u] != INT_MAX && dist[u] + G[u][v].len == dist[v]) {
				prev[v].push_back(u);
			}
		}
	}

	return dist;
}

int ChooseMinTime(const vector<int>& timeDist, vector<bool>& visited) {
	int minTime = INT_MAX;
	int minIdx = -1;
	for (int i = 0; i < n; ++i) {
		if (!visited[i] && timeDist[i] < minTime) {
			minTime = timeDist[i];
			minIdx = i;
		}
	}
	return minIdx;
}

vector<int> DijkstraTime(int s, vector<vector<int>>& prev) {
	vector<int> distTime(n, INT_MAX);
	vector<bool> visited(n, false);
	distTime[s] = 0;

	for (int i = 0; i < n; ++i) {
		int u = ChooseMinTime(distTime, visited);
		visited[u] = true;
		for (int v = 0; v < n; ++v) {
			if (G[u][v].time != -1 && 
				distTime[u] != INT_MAX && distTime[u] + G[u][v].time < distTime[v]) {
					distTime[v] = distTime[u] + G[u][v].time;
					prev[v].clear();
					prev[v].push_back(u);
				
			} else if (G[u][v].time != -1 && 
				distTime[u] != INT_MAX && distTime[u] + G[u][v].time == distTime[v]) {
				prev[v].push_back(u);
			}
		}
	}

	return distTime;
}

vector<vector<int>> BuildPath(int s, int t, const vector<vector<int>> &prev) {
	vector<vector<int>> ans;
	if (t == s) {
		vector<int> path;
		path.push_back(t);
		ans.push_back(path);
		return ans;
	}

	for (size_t i = 0; i < prev[t].size(); ++i) {
		int u = prev[t][i];
		vector<vector<int>> allPath = BuildPath(s, u, prev);
		for (size_t ii = 0; ii < allPath.size(); ++ii) {
			allPath[ii].push_back(t);
			ans.push_back(allPath[ii]);
		}

	}
	return ans;
}

void PrintVec(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (i == 0) printf("%d", v[i]);
		else printf(" -> %d", v[i]);
	}
	cout << endl;
}

int CountPathTime(const vector<int>& path) {
	int n = (int)path.size();
	if (n <= 1) return 0;

	int cnt = 0;
	for (int i = 1; i < n; ++i) {
		int v = path[i];
		int u = path[i-1];
		cnt += G[u][v].time;
	}
	return cnt;
}

int CountPathLength(const vector<int>& path) {
	int cnt = (int)path.size();
	return cnt;
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);

	int u, v, flag, len, t;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d %d %d", &u, &v, &flag, &len, &t);
		if (flag == 1) {
			G[u][v].len = len;
			G[u][v].time = t;
		} else {
			G[u][v].len = G[v][u].len = len;
			G[u][v].time = G[v][u].time = t;
		}
	}

	scanf("%d %d", &src, &dest);

	vector<vector<int>> prev(n);
	vector<int> dist = Dijkstra(src, prev);
	//cout << dist[dest] << endl;
	
	vector<vector<int>> allPath = BuildPath(src, dest, prev);

	vector<int> shortestMinTimePath;
	int minTime = INT_MAX;
	for (size_t i = 0; i < allPath.size(); ++i) {
		//PrintVec(allPath[i]);
		int t = CountPathTime(allPath[i]);
		if (t < minTime) {
			minTime = t;
			shortestMinTimePath = allPath[i];
		}	
	}

	//PrintVec(shortestMinTimePath);

	vector<vector<int>> prevTime(n);
	vector<int> distTime = DijkstraTime(src, prevTime);
	//cout << distTime[dest] << endl;
	vector<vector<int>> allTimePath = BuildPath(src, dest, prevTime);

	vector<int> fastTimeShortestPath;
	int minLen = INT_MAX;
	for (size_t i = 0; i < allTimePath.size(); ++i) {
		int temp = CountPathLength(allTimePath[i]);
		//cout << "temp:" << temp << endl;
		if (temp < minLen) {
			minLen = temp;
			fastTimeShortestPath = allTimePath[i];
		}
	}
	//PrintVec(fastTimeShortestPath);

	if (shortestMinTimePath == fastTimeShortestPath) {
		printf("Distance = %d; ", dist[dest]);
		printf("Time = %d: ", distTime[dest]);
		PrintVec(fastTimeShortestPath);
	} else {
		printf("Distance = %d: ", dist[dest]);
		PrintVec(shortestMinTimePath);
		printf("Time = %d: ", distTime[dest]);
		PrintVec(fastTimeShortestPath);
	}


	return 0;
}