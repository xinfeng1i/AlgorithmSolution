#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

const int NODE_NUM = 5;
bool HamiltonianCycle(const vector<vector<int> >& graph, int curNode, int curCnt, vector<int>& path)
{
	// base case
	if (curCnt == NODE_NUM)
	{
		// the last element has edge with the first element, form a cycle
		if (graph[path.back()][path[0]] == 1) return true;
		// otherwise
		else return false;
	}

	// for all the neighbor, that not included in current path
	for(size_t j = 0; j < graph[curNode].size(); ++j)
	{
		if (graph[curNode][j] == 1 && find(path.begin(), path.end(), j) == path.end())
		{
			// try a choice
			path.push_back(j);	
			bool success = HamiltonianCycle(graph, j, curCnt+1, path);
			// if lead to a solution, return true
			if (success) return true;
			// otherwise, backtracking, try an alternative choice
			else path.pop_back();
		}
	}

	return false;
}

int main()
{
	vector<vector<int> > graph(NODE_NUM, vector<int>(NODE_NUM, 0));
	graph[0][1] = 1; graph[0][3] = 1;
	graph[1][0] = 1; graph[1][2] = 1; graph[1][3] = 1; graph[1][4] = 1;
	graph[2][1] = 1; graph[2][4] = 1;
	graph[3][0] = 1; graph[3][1] = 1; graph[3][4] = 1;
	graph[4][1] = 1; graph[4][2] = 1; graph[4][3] = 1;

	//graph[3][4] = 0; graph[4][3] = 0;

	vector<int> path;
	path.push_back(0);
	bool ok = HamiltonianCycle(graph, 0, 1, path);
	if (ok)
	{
		cout << "Find Solution" << endl;
		copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	else
	{
		cout << "Solution Does not Exist" << endl;
	}

	return 0;
}
