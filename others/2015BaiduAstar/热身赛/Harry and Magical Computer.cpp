#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef vector<vector<int> > Matrix;

int G_TIME = 0;
enum COLOR {WHITE = 0, GRAY, BLACK};

bool DFS_VISIT(int u, vector<COLOR>& color, vector<int>& s_time, vector<int>& f_time, const Matrix& graph)
{
	int n = graph.size();
	
	// is visiting its neighbors now
	color[u] = GRAY;
	// time to start visit neighbors
	G_TIME += 1;
	s_time[u] = G_TIME;
	 
	for (int v = 0; v < n; ++v)
	{
		if (graph[u][v] != 0)
		{
			if (color[v] == WHITE)
			{
				bool flag = DFS_VISIT(v, color, s_time, f_time, graph);
				if (flag) return true;
			}
			else if (color[v] == GRAY)
			{
				return true;
			}
		}
	}
	
	// has end to visiting all its neighbors
	color[u] = BLACK;
	
	// finishing time
	G_TIME += 1;
	f_time[u] = G_TIME;
	
	return false;
}

bool DFS(const Matrix& graph)
{
	int n = graph.size();
	vector<COLOR> color(n, WHITE);
	vector<int> s_time(n, 0);
	vector<int> f_time(n, 0);
	for (int i = 0; i < n; ++i)
	{	
		if (color[i] == WHITE)
		{
			if (DFS_VISIT(i, color, s_time, f_time, graph)) return true;
		}
	}
	return false;
}

int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		Matrix graph(n, vector<int>(n, 0));
		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			graph[b-1][a-1] = 1;
		}
		
		if (DFS(graph))
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}
