#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 3000000;
const int NIL = -1;

int findMinDistElem(const vector<int>& dist, const deque<bool>& visited)
{
	int n = dist.size();

	int minDist = INF;
	int minDistIndex = -1;
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i] && dist[i] < minDist)
		{
			minDist = dist[i];
			minDistIndex = i;
		}
	}

	return minDistIndex;
}

void printPath(int dest, int src, vector<int> parent)
{
	if (parent[dest] == NIL)
	{
		printf("%d ", dest);
	}
	else
	{
		printPath(parent[dest], src, parent);
		printf("%d ", dest);
	}
}

// Time Complexity : O(V^2)
// DO NOT WORK ON NEGATIVE WEIGHT GRAPH
void Dijkstra(vector<vector<int> > adjMatrix, int src)
{
	int n = adjMatrix.size();
	deque<bool> visited(n, false);
	vector<int> dist(n, INF);
	dist[src] = 0;
	vector<int> parent(n, NIL);

	// Dijkstra
	for (int i = 0; i < n; ++i)
	{
		int u = findMinDistElem(dist, visited);
		visited[u] = true;
		for (int v = 0; v < n; ++v)
		{
			if (!visited[v] && adjMatrix[u][v] != INF && dist[u] != INF
				            && dist[u] + adjMatrix[u][v] < dist[v])
			{
				dist[v] = dist[u] + adjMatrix[u][v];	
				parent[v] = u;
			}
		}
	}

	// output minimum dist
	for (int i = 0; i < n; ++i)
	{
		cout << src << "-" << i << " : " << dist[i] << endl;
	}
	
	// output minimum path;
	for (int i = 0; i < n; ++i)
	{
		printPath(i, src, parent);
		printf("\n");
	}

	return;
}

int main()
{
	int n = 9; int src = 0;
	vector<vector<int> > adjMatrix(n, vector<int>(n, INF));
	adjMatrix[0][1] = 4; adjMatrix[1][0] = 4;
	adjMatrix[0][7] = 8; adjMatrix[7][0] = 8;
	adjMatrix[1][7] = 11; adjMatrix[7][1] = 11;
	adjMatrix[1][2] = 8; adjMatrix[2][1] = 8;
	adjMatrix[2][8] = 2; adjMatrix[8][2] = 2;
	adjMatrix[7][8] = 7; adjMatrix[8][7] = 7;
	adjMatrix[6][8] = 6; adjMatrix[8][6] = 6;
	adjMatrix[6][7] = 1; adjMatrix[7][6] = 1;
	adjMatrix[2][3] = 7; adjMatrix[3][2] = 7;
	adjMatrix[2][5] = 4; adjMatrix[5][2] = 4;
	adjMatrix[5][6] = 2; adjMatrix[6][5] = 2;
	adjMatrix[3][5] = 14; adjMatrix[5][3] = 14;
	adjMatrix[3][4] = 9; adjMatrix[4][3] = 9;
	adjMatrix[4][5] = 10; adjMatrix[5][4] = 10;
	
	Dijkstra(adjMatrix, src);
	return 0;
}
