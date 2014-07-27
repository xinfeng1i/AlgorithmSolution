#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 3000000;
const int NIL = -1;

void printAllPairPath(const vector<vector<int> >& parent, int i, int j);
void printMatrix(const vector<vector<int> >& v);

vector<vector<int> > FloydWarshall(const vector<vector<int> >& graph)
{
	// INIT
	int n = graph.size();
	vector<vector<int> > dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dist[i][j] = graph[i][j];
		}
	}

	vector<vector<int> > parent(n, vector<int>(n, NIL));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j || graph[i][j] == INF) parent[i][j] = NIL;
			else parent[i][j] = i;
		}
	}

	// Floyd-Warshall
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if ( dist[i][k] != INF && dist[k][j] != INF &&
					 dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					if (k >= 1)
					{
						parent[i][j] = parent[k][j];
					}
				}
			}
		}
	}
	printMatrix(parent);

	// OUTPUT Path
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d to %d path:\n", i, j);
			printAllPairPath(parent, i, j);
			printf("\n\n");
		}
	}
	
	return dist;
}

void printMatrix(const vector<vector<int> >& v)
{
	int n = v.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == INF) printf(" INF");
			else printf(" %d", v[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

void printAllPairPath(const vector<vector<int> >& parent, int i, int j)
{
	
	if (i == j) 
	{ 
		printf(" %d", i);
	}
	else if (parent[i][j] == NIL)
	{
		printf("%d to %d has no path", i, j);
	}
	else
	{
		printAllPairPath(parent, i, parent[i][j]);
		printf(" %d", j);
	}
}

int main()
{
	int n = 4;
	vector<vector<int> > graph(n, vector<int>(n, INF));
	for (int i = 0; i < n; ++i) graph[i][i] = 0;
	graph[0][1] = 5;
	graph[0][3] = 10;
	graph[1][2] = 3;
	graph[2][3] = 1;

	vector<vector<int> > dist = FloydWarshall(graph);

	printf("Dist Matrix:\n");
	printMatrix(dist);

	return 0;
}
