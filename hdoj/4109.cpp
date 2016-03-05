#include <iostream>
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
#include <string.h>
using namespace std;

// toposort to solve the earlist finishing time
// AOE problem

struct Node {
	int dest;
	int weight;
	Node(int _dest, int _weight) : dest(_dest), weight(_weight) {}
};

struct ReverseNode {
	int src;
	int weight;
	ReverseNode(int _src, int _weight) : src(_src), weight(_weight) {}
};

int main()
{
	//freopen("input.txt", "r", stdin);
	int n = 0, m = 0;
	while (scanf("%d %d", &n, &m) != EOF) {
		vector<int> indeg(n, 0);
		vector<vector<Node>> adjList(n);
		vector<vector<ReverseNode>> reverseAdjList(n);
		int u = 0, v = 0, weight = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &v, &u, &weight);
			adjList[u].push_back(Node(v, weight));
			reverseAdjList[v].push_back(ReverseNode(u, weight));
			indeg[v]++;
		}

		stack<int> s;
		vector<int> topoResult;
		vector<int> earlist(n, 0);
		for (int i = 0; i < n; ++i) {
			if (indeg[i] == 0) {
				earlist[i] = 1;
				s.push(i);
			}
		}

		// toposort and compute earlist time of each node
		while (!s.empty()) {
			int u = s.top();
			s.pop();
			topoResult.push_back(u);
			for (size_t i = 0; i < adjList[u].size(); ++i) {
				int v = adjList[u][i].dest;
				int cost = adjList[u][i].weight;
				if (earlist[u] + cost > earlist[v]) {
					earlist[v] = earlist[u] + cost;
				}
				indeg[v]--;
				if (indeg[v] == 0) {
					s.push(v);
				}
			}
		}
		
		// compute lastest time of each node
		int maxEarlistTime = *max_element(earlist.begin(), earlist.end());
		vector<int> lastest(n, maxEarlistTime);
		for (auto it = topoResult.rbegin(); it != topoResult.rend(); ++it) {
			int v = *it;
			for (size_t i = 0; i < reverseAdjList[v].size(); ++i) {
				int u = reverseAdjList[v][i].src;
				int cost = reverseAdjList[v][i].weight;
				if (lastest[v] - cost < lastest[u]) {
					lastest[u] = lastest[v] - cost;
				}
			}
		}

		// key activity
		/*
		int ans = 0;
		for (int u = 0; u < n; ++u) {
			for (int j = 0; j < adjList[u].size(); ++j) {
				int v = adjList[u][j].dest;
				int cost = adjList[u][j].weight;
				if (earlist[u] + cost == lastest[v]) {
					//printf("%d -> %d\n", u, v);
					ans += cost;
				}
			}
		}
		*/


		printf("%d\n", maxEarlistTime);

	}
	return 0;
}