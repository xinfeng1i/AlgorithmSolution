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

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> result;
	int n = numCourses;

	// init adjlist and indegree
	vector<int> indeg(n, 0);
	vector<vector<int>> adjList(n);
	for (size_t i = 0; i < prerequisites.size(); ++i) {
		int u = prerequisites[i].second;
		int v = prerequisites[i].first;
		adjList[u].push_back(v);
		indeg[v]++;
	}

	// toposort
	stack<int> s;
	for (size_t i = 0; i < n; ++i) {
		if (indeg[i] == 0) {
			s.push(i);
		}
	}

	while (!s.empty()) {
		int u = s.top();
		s.pop();
		// output current node
		result.push_back(u);
		// the neighbors of u in degree -= 1
		for (size_t i = 0; i < adjList[u].size(); ++i) {
			int v = adjList[u][i];
			indeg[v]--;
			if (indeg[v] == 0) {
				s.push(v);
			}
		}
	}

	// has cicle in the graph, no toposort exist
	if (result.size() != n) {
		result.clear();
	}

	return result;
}