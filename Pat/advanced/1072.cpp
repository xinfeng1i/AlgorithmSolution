#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

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

const long INF = 1E8;
int main()
{
	freopen("input.txt", "r", stdin);
	int n; int m; int k; long d;
	scanf("%d %d %d %ld\n", &n, &m, &k, &d);

	int n1 = n + m;
	vector<vector<long> > dist(n1, vector<long>(n1, INF));
	
	string start; string end; long dd;
	for (int i = 0; i < k; ++i)
	{
		cin >> start >> end >> dd;
		int s = string2Int(start, n);
		int e = string2Int(end, n);
		dist[s][e] = dd;
		dist[e][s] = dd;
	}

	int sz = dist.size();
	for (int kk = 0; kk < sz; ++kk)
	{
		if (kk != n && kk != sz- 1)
		{
		for (int i = 0; i < sz; ++i)
		{
			if (i != n && i != sz- 1)
			{
			for (int j = 0; j < sz; ++j)
			{
				if (j != n && j != sz- 1)
				{
				if (dist[i][kk] != INF && dist[kk][j] != INF &&
						dist[i][kk] + dist[kk][j] < dist[i][j])
				{
					dist[i][j] = dist[i][kk] + dist[kk][j];
				}
				}
			}
			}
		}
		}
	}

	double globalAvg = INF;
	double globalMinDist = INF;
	int globalMIndex = -1;
	for (int i = 1; i <= m; ++i)
	{
		string gas = string("G") + to_string(i);
		int gasInt = string2Int(gas, n);
		cout << "gas=" << gas <<"; gasInt=" << gasInt << endl; 
		printMatrix(dist);

		bool flag = true;
		for (int j = 0; j < n; ++j)
		{
			if (dist[gasInt][j] > d)
			{
				flag = false;
				break;
			}
		}

		if(flag)
		{
			double avg = 0.0;
			double minDist = INF;
			for (int j = 0; j < n; ++j)
			{
				avg += dist[gasInt][j];	
				if (dist[gasInt][j] < minDist)
				{
					minDist = dist[gasInt][j];
				}
			}
			avg /= n;	

			if (avg < globalAvg)
			{
				globalAvg = avg;
				globalMinDist = minDist;
				globalMIndex = i;
			}
		}

		
	}

	if (globalMIndex == -1)
	{
		printf("No Solution\n");
	}
	else
	{
		printf("G%d\n", globalMIndex);
		printf("%.1f %.1f\n", globalMinDist, globalAvg);
	}

	return 0;

}
