#include <iostream>
#include <vector>
using namespace std;

bool fullFilled(const vector<int>& x)
{
	for (size_t i = 0; i < x.size(); ++i)
	{
		if (x[i] == -1)
		{
			return false;
		}
	}
	return true;
}

string possible(int n, vector<int> A, vector<int> B, vector<int> G, vector<int> L)
{
	vector<int> x(n, -1);
	for (int i = 0; i < n; ++i)
	{
		int idx = A[i];
		int idy = B[i];
		int g = G[i];
		int l = L[i];

	}
}
