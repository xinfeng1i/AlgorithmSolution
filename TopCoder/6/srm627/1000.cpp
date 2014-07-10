#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

// nSwap == nNiXuNumber
Class BuddleSortWithReversals
{
public:
	int getCurNiXuNumber(vector<int> A)
	{
		int n = A.size();
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (A[i] > A[j])
				{
					cnt++;
				}
			}
		}

		return cnt;
	}

	int getMaxNixuNumber(vector<int> A)
	{
		int n = A.size();
		return n * (n - 1) / 2;
	}

	int getMinSwaps(vector<int> A, int K)
	{
		
	}
};
