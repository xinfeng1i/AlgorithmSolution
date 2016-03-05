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


bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<int> inDegree(numCourses, 0);
	vector<vector<int>> adjList(numCourses);

	// init adjList and inDegree
	for (size_t i = 0; i < prerequisites.size(); ++i) {
		int u = prerequisites[i].first;
		int v = prerequisites[i].second;
		inDegree[v] += 1;
		adjList[u].push_back(v);
	}

	stack<int> s;
	vector<int> result;
	bool found = false;
	int n = numCourses;
	for (size_t i = 0; i < n; ++i) {
		if (inDegree[i] == 0) {
			found = true;
			s.push(i);
		}
	}

	while (!s.empty()) {
		int u = s.top();
		s.pop();
		result.push_back(u);
		for (size_t i = 0; i < adjList[u].size(); ++i) {
			int v = adjList[u][i];
			inDegree[v] -= 1;
			if (inDegree[v] == 0) {
				s.push(v);
			}
		}
	}

	if (result.size() == n) return true;
	else return false;        
}