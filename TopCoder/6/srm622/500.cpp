#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class BoxesDiv2
{
public:
	//int a[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

	int findSize(vector<int> candyCounts)
	{

		vector<int> a(11);
		a[0] = 1;
		for (int i = 1; i < 11; ++i)
		{
			a[i] = 2 * a[i-1];
		}


		int n = candyCounts.size();
		vector<int> boxes;
		boxes.reserve(n);
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				if (a[j] >= candyCounts[i])
				{	
					boxes.push_back(a[j]);
					ans += a[j];
					break;
				}
			}
		}

		// 装箱策略错误：
		// 本来以为，每两个装一个是最优的策略，但是
		// 对于16 1 1 1 1，来说，11装箱2， 11装箱2，22装箱4，最后4，16装箱32才是最优
		// TODO
		while (boxes.size() >= 2)
		{
			sort(boxes.begin(), boxes.end(), greater<int>());

			vector<int> tmp;
			for (int i = 0; i < boxes.size(); i += 2)
			{
				tmp.push_back(boxes[i] * 2);
				ans += boxes[i] * 2;
			}

			boxes.clear();
			swap(boxes, tmp);
		}

		return boxes[0];
	}
};