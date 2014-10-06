#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

void rotation(int x, int y, int a, int b)
{
	int x1 = -y + a + b;
	int y1 = x - a + b;
	cout << x1 << " " << y1 << endl;

	int x2 = -y1 + a + b;
	int y2 = x1 - a + b;
	cout << x2 << " " << y2 << endl;

	int x3 = -y2 + a + b;
	int y3 = x2 - a + b;
	cout << x3 << " " << y3 << endl;

	int x4 = -y3 + a + b;
	int y4 = x3 - a + b;
	cout << x4 << " " << y4 << endl;
	return;
}

bool FormSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	vector<int> dist;
	int d;
	d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	dist.push_back(d);

	d = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
	dist.push_back(d);

	d = (x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4);
	dist.push_back(d);

	d = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
	dist.push_back(d);

	d = (x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4);
	dist.push_back(d);

	d = (x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4);
	dist.push_back(d);

	sort(dist.begin(), dist.end());

	if (dist[0] == dist[1] && dist[1] == dist[2] && dist[2] == dist[3] &&
			dist[4] == dist[5] && dist[0] < dist[4])
		return true;
	else
		return false;
}

int main()
{
	//rotation(-1, 1, 0, 0);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int k = 0; k < n; ++k)
	{
		//cout << "point " << k+1 << endl;
		vector<vector<pair<int, int> > > v(4);
		for (int i = 0; i < 4; ++i)
		{
			int x, y, a, b;
			cin >> x >> y >> a >> b;

			// no roration
			v[i].push_back(make_pair(x, y));
			
			// rotation once
			int x1 = -y + a + b;
			int y1 = x - a + b;
			v[i].push_back(make_pair(x1, y1));

			// rotation twice
			int x2 = -y1 + a + b;
			int y2 = x1 - a + b;
			v[i].push_back(make_pair(x2, y2));

			// rotation three times
			int x3 = -y2 + a + b;
			int y3 = x2 - a + b;
			v[i].push_back(make_pair(x3, y3));
		}

		bool flag = false;
		int ans = 300000;
		for (int j1 = 0; j1 < 4; ++j1)
		{
			int x1 = v[0][j1].first;
			int y1 = v[0][j1].second;

			for (int j2 = 0; j2 < 4; ++j2)
			{
				int x2 = v[1][j2].first;
				int y2 = v[1][j2].second;
				for (int j3 = 0; j3 < 4; ++j3)
				{
					int x3 = v[2][j3].first;
					int y3 = v[2][j3].second;
					for (int j4 = 0; j4 < 4; ++j4)
					{
						int x4 = v[3][j4].first;
						int y4 = v[3][j4].second;
						/*
							if (j1 + j2 + j3 + j4 == 3) 
							{
								cout << j1 << " " << j2 << " " << j3 << " " << j4 << endl;
								cout << x1 << " " << y1 << endl;
								cout << x2 << " " << y2 << endl;
								cout << x3 << " " << y3 << endl;
								cout << x4 << " " << y4 << endl;
							}
							*/
						if (FormSquare(x1,y1,x2,y2,x3,y3,x4,y4))
						{
							flag = true;
							ans = min(j1+j2+j3+j4, ans);
						}
					}
				}
			}
		}
		if (flag) cout << ans << endl;
		else cout << -1 << endl;
	}

	return 0;
}
