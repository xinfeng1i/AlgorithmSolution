#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

// bipartie-matching
bool bpm(const vector<vector<int> >& bpGraph, int u, deque<bool>& visited, vector<int>& matchR)
{
	// check the job (right) one by one
	for (int v = 0; v < bpGraph[0].size(); ++v)
	{
		// if u is interested in job v, and the job v has not been visited
		if (bpGraph[u][v] == 1 && !visited[v])
		{
			// visite the job v
			visited[v] = true;	

			// if the job v has not been assigned to others, or has been assigned to x, but 
			// x has an alternative, then u can get job v
			if (matchR[v] < 0 || bpm(bpGraph, matchR[v], visited, matchR))
			{
				matchR[v] = u;	
				return true;
			}
		}
	}
	return false;
}

int maxBPM(const vector<vector<int> >& bpGraph)
{
	int m = bpGraph.size();
	int n = bpGraph[0].size();
	vector<int> matchR(n, -1);

	int result = 0;
	for (int u = 0; u < m; ++u)
	{
		// every application has its visited job list
		deque<bool> visited(n, false);
		if (bpm(bpGraph, u, visited, matchR))
		{
			result++;
		}
	}
	return result;
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
	int result = maxBPM(bpGraph);
	cout << "The maximum biparite matching:" << result << endl;
	return 0;
}
