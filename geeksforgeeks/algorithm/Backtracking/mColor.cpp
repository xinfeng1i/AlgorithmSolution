#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

const int NODE_NUM = 4;
const int COLOR_NUM = 3;


bool mColor(const vector<vector<int> >& graph, int curNode, vector<int>& colors);
bool IsSafe(const vector<vector<int> >& graph, int curNode, int curColor, vector<int>& colors);

int main()
{
	vector<vector<int> > graph(NODE_NUM, vector<int>(NODE_NUM, 0));
	graph[0][1] = 1; graph[0][2] = 1; graph[0][3] = 1;
	graph[1][0] = 1; graph[1][2] = 1;
	graph[2][0] = 1; graph[2][1] = 1; graph[2][3] = 1;
	graph[3][0] = 1; graph[3][2] = 1;

	vector<int> colors(NODE_NUM, 0);

	bool ok = mColor(graph, 0, colors);
	if (ok)
	{
		cout << "Find Solution" << endl;
		copy(colors.begin(), colors.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	else
	{
		cout << "Solution does not exist" << endl;
	}
	return 0;
}

bool mColor(const vector<vector<int> >& graph, int curNode, vector<int>& colors)
{
	// base case
	if (curNode == NODE_NUM) return true;	

	// for every color choice
	for (int i = 1; i <= COLOR_NUM; ++i)
	{
		if (IsSafe(graph, curNode, i, colors))
		{
			// try one choice
			colors[curNode] = i;
			bool success = mColor(graph, curNode+1, colors);
			// if lead to a solution, return true
			if (success) return true;
			// else rest color, try an alternative choice
			else colors[curNode] = 0;
		}
	}
	// try all the choice, still not find solutions
	return false;
}

bool IsSafe(const vector<vector<int> >& graph, int curNode, int curColor, vector<int>& colors)
{
	for (int j = 0; j < graph[curNode].size(); ++j)
	{
		// j is curNode neighbor
		if (graph[curNode][j] == 1)
		{
			// curNode color is same with its neighbor, not safe
			if (curColor == colors[j])
			{
				return false;
			}
		}
	}

	return true;
}
