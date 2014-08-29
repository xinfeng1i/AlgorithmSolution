#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

bool canFindMatch(const vector<vector<int> > &graph, int u, deque<bool>& visited, vector<int>& matchR)
{
    int m = graph.size();
    int n = graph[0].size();
    for (int v = 0; v < n; ++v)
    {
        if (graph[u][v] > 0 && !visited[v])
        {
            visited[v] = true;
            if (matchR[v] == -1 || canFindMatch(graph, matchR[v], visited, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm(const vector<vector<int> >& graph)
{
    int cnt = 0;
    int m = graph.size();
    int n = graph[0].size();
    vector<int> matchR(n, -1);

    for (int u = 0; u < m; ++u)
    {
        deque<bool> visited(n, false);
        if (canFindMatch(graph, u, visited, matchR))
        {
            cnt++;
        }
    }

    return cnt;
}


int main()
{
	int m = 6;
	int n = 6;
	vector<vector<int> > bpGraph(m, vector<int>(n, 0));
	bpGraph[0][1] = 1; bpGraph[0][2] = 1;
	bpGraph[1][0] = 1; bpGraph[1][3] = 1;
	bpGraph[2][2] = 1;
	bpGraph[3][2] = 1; bpGraph[3][3] = 1;
	bpGraph[5][5] = 1;
	int result = bpm(bpGraph);
	cout << "The maximum biparite matching:" << result << endl;
	return 0;
}
