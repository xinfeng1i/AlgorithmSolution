#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// AC code: 168pts
class CatchTheBeatEasy
{
public:
	struct Point
	{
		int x;
		int y;
		Point(int xx, int yy):x(xx),y(yy){}
	};	
	string ableToCatchAll(vector <int> x, vector <int> y)
	{
		vector<Point> v;
		int n = x.size();
		for (int i = 0; i < n; ++i)
		{
			Point p(x[i], y[i]);
			v.push_back(p);
		}

		sort(v.begin(), v.end(), [](Point p1, Point p2){ return p1.y < p2.y; });

		int curx = 0;
		int sumx = 0;
		for (int i = 0; i < n; ++i)
		{
			int dist = abs(curx - v[i].x);
			if (sumx + dist <= v[i].y)
			{
				curx = v[i].x;
				sumx = sumx + dist;
			}
			else
			{
				return "Not able to catch";
			}
		}
		return "Able to catch";
	}
};