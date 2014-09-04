#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

// Dijkstra choose the unvisited mindist node
int choose(const vector<long>& dist, const deque<bool>& visited)
{
    int n = dist.size();

    int minIndex = -1;
    long minDist = LONG_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && dist[i] < minDist)
        {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

//Dijkstra
void Dijkstra(const vector<vector<long> >& graph, int src, vector<long>& dist)
{
    int n = graph.size();
    dist.resize(n); for (int i = 0; i < n; ++i) dist[i] = LONG_MAX;
    deque<bool> visited(n, false);
    dist[src] = 0;

    for (int k = 0; k < n; ++k)
    {
        int u = choose(dist, visited);
        visited[u] = true;
        for (int v  = 0;  v < graph[u].size(); ++v)
        {
            if (!visited[v] && dist[u] != LONG_MAX && graph[u][v] != LONG_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return;
}


void printMatrix(const vector<vector<long> >& v)
{
	int n = v.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int string2Int(string s, int n)
{
	if (s[0] != 'G')
	{
		return atoi(s.c_str()) - 1;
	}
	else
	{
		return atoi((s.substr(1)).c_str()) + (n-1);
	}
}

struct Gas
{
    long minHouseDist;
    long totalDist;
    double avgDist;
    int intID;
    string strID;

    bool operator<(const Gas& other) const
    {
        if (minHouseDist != other.minHouseDist)
        {
            return minHouseDist > other.minHouseDist;
        }
        else if (totalDist != other.totalDist)
        {
            return totalDist < other.totalDist;
        }
        else
        {
            return intID < other.intID; 
        }
    }
};

const long INF = LONG_MAX;
int main()
{
	freopen("input.txt", "r", stdin);
	int n; int m; int k; long d;
	scanf("%d %d %d %ld\n", &n, &m, &k, &d);

	int n1 = n + m;
	vector<vector<long> > dist(n1, vector<long>(n1, INF));
    for (int i = 0; i < n1; ++i) dist[i][i] = 0;
	
	string start; string end; long dd;
	for (int i = 0; i < k; ++i)
	{
		cin >> start >> end >> dd;
		int s = string2Int(start, n);
		int e = string2Int(end, n);
		dist[s][e] = dd;
		dist[e][s] = dd;
	}

    // Floyd-Warshall algorithm, O((N+M)^3), last sample TLE
    /*
    for (int k = 0; k < n1; ++k)
    {
        for (int i = 0; i < n1; ++i)
        {
            for (int j = 0; j < n1; ++j)
            {
                if (dist[i][k] != INF &&  dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        
    }
    */

    vector<vector<long> > dist2(m, vector<long>(n+m));
    for (int i = 0; i < m; ++i)
    {
        int u = i + n;
        Dijkstra(dist, u, dist2[i]);
    }

    vector<Gas> stations;
	for (int i = 1; i <= m; ++i)
	{
        string istr;
        if (i == 10) istr += "10";
        else istr += string(1, i+'0');
		string gas = string("G") + istr;
		int gasInt = string2Int(gas, n);

		bool flag = true;
		for (int j = 0; j < n; ++j)
		{
			if (dist2[gasInt-n][j] > d)
			{
				flag = false;
				break;
			}
		}

		if(flag)
		{
            Gas g;
			double total = 0.0;
			double minDist = INF;
			for (int j = 0; j < n; ++j)
			{
				total += dist2[gasInt-n][j];	
				if (dist2[gasInt-n][j] < minDist)
				{
					minDist = dist2[gasInt-n][j];
				}
			}
			g.minHouseDist = minDist;
            g.totalDist = total;
            g.avgDist = (double)g.totalDist / (double)(n);
            g.strID = gas;
            g.intID = gasInt;
            stations.push_back(g);
		}
	}

    sort(stations.begin(), stations.end());
    if (stations.size() == 0)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        cout << stations[0].strID << endl;

        double ans1 = stations[0].minHouseDist;
        double ans2 = stations[0].avgDist;
        printf("%.1f %.1f\n", ans1, ans2);
    }

	return 0;

}

/*
 * 总结：考察Dijkstra算法和按照规则进行排序
 * 如果采用Floyd-Warshall算法，算法复杂度太高，导致
 * 最后一个测试点过不去
 * 难点：对于排序规则的理解
 * 1. 加油站距离house的的最小距离最大的优先
 * 2. 如果1相等，则距离house平均距离最小的加油站优先
 * 3. 如果2也相等，index小的加油站优先
 *
 * 坑点，对于排序规则1容易忽略
 */
