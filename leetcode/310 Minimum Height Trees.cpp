#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	// special case
	vector<int> roots;
	if (n <= 2) {
		for (int i = 0; i < n; ++i) roots.push_back(i);
		return roots;
	}
	
	vector<vector<int>> nbrs(n);
	vector<int> deg(n, 0); // degree of each node
	for (auto edge:edges) {
		nbrs[edge.first].push_back(edge.second);
		deg[edge.first]++;
		nbrs[edge.second].push_back(edge.first);
		deg[edge.second]++;
	}
	
	queue<int> q;
	int nodeCnt = n;
	
	while (true) {
	    // push all the node with degree == 1
		for (size_t i = 0; i < deg.size(); ++i) {
			if (deg[i] == 1) {
				q.push(i);
 			}
		}
		
		int sz = q.size();
		// remove all the nodes that is with degree = 1
		for (int i = 0; i < sz; ++i) {
			int u = q.front();
			q.pop();
			deg[u] = -1;
			nodeCnt--;
			// all its neibors' degree minus 1
			for (auto v : nbrs[u]) {
				if (deg[v] > 0) {
					cout << "v :" << v << endl;
					deg[v]--;
				}
				
			}
		}
		
		if (nodeCnt <= 2) {
			break;
		}
	}
	
	
	for (size_t i = 0; i < n; ++i) {
		if (deg[i] != -1) {
			roots.push_back(i);
		}
	}
	
	return roots;
	
}

int main()
{
	int n = 3;
	vector<pair<int, int>> edges;
	edges.push_back(make_pair(1, 0));
	edges.push_back(make_pair(0, 2));
	//edges.push_back(make_pair(1, 3));
	vector<int> ans = findMinHeightTrees(n, edges);
	for (int x : ans) {
		cout << " " << x << endl;
	}
	return 0;
	
}
