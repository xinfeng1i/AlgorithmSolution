#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

int singleNumberII(int A[], int n)
{
	int nBits = sizeof(int) * 8;
	
	int ans = 0;
	int sum = 0;

	// compute the number of 1s in each bits
	for (int i = 0; i < nBits; ++i)
	{
		sum = 0;
		for (int j = 0; j < n; ++j)
		{
			if (A[j] & (1 << i)) sum++;
		}

		if (sum % 3 != 0) ans |= (1 << i);
	}
	return ans;

}

int main()
{
	int A[] = {2, 3, 3, 3};
	cout << singleNumberII(A, 4) << endl;
	return 0;
}