#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 30000;

vector<vector<int> > FloydWarshall(vector<vector<int> >& graph)
{
	int n = graph.size();
	vector<vector<int> > dist(n, vector<int>(n));
	
	//init
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dist[i][j] = graph[i][j];
		}
	}

	// floyd warshall algorihm O(N^3)
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dist[i][k] != INF && dist[k][j] != INF &&
					dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return dist;
}

int main()
{
	/*        10
	 * (0)---------->(3)
	 *  |            /|\
	 *  |             |
	 *  |5            | 1
	 *  |             |
	 * \|/            |
	 * (1)---------->(2)
	 *         3
	 */
	vector<vector<int> > graph(4, vector<int>(4, INF));
	for (int i = 0; i < 4; ++i) graph[i][i] = 0;
	graph[0][1] = 5;
	graph[0][3] = 10;
	graph[1][2] = 3;
	graph[2][3] = 1;

	vector<vector<int> > dist = FloydWarshall(graph);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << " " << dist[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
