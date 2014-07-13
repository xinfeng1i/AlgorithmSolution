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
class BubbleSortWithReversals
{
public:
	// return the number of nixu with index >= x
	int getCurNiXuNumber(vector<int> A, int x)
	{
		int n = A.size();
		int cnt = 0;
		for (int i = x; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (A[j] > A[i])
				{
					cnt++;
				}
			}
		}

		return cnt;
	}

	// DP solution:
	// Define: f(x, k) = the number of nixu with indices i >= x that can reverse
	//         at most k subarray without overlap, thea number of xinu at index i,
	//         is the number of index j with j < i && A[j] > A{i]
	//
	//         Then the f(0, K) is the answer of original problem
	//
	// Base Case: f(n, k) = 0 with k = 0, 1, 2, ... MAX_K;
	// Recursive relationship:
	// Case 1: A[x] is not in the reversed subarray, which means A[x] stays in index
	//         x after the most k reverses of subarray, Note that the order of elems
	//         A[j] with j < x do not affect the the number of Nixu at index x
	//         So in this case
	//         f(x, k) = The number of nixu at index x + f(x + 1, k)
	// Case 2: A[x] is in the reversed subarray, we only need to consider the reversed	  //	     subarray (A[x], A[x+1], ..., A[y-1], A[y]), cause if the reversing 
	//         start before index x such as (A[a], A[b], A[c], A[x], ...), then when
	//         x = a, it equals exactly the situation of current time
	//         So in this Case:
	//         We first revere (A[x], A[x+1], ..., A[y-1], A[y]) to obtain
	//         (A[0],...A[x-1], A[y], A[y-1], ..., A[x+1], A[x])
	//         Then we caculate The number of nixu at index x + f(y+1, k-1)
	//         f(x, k) = the number of nixu at x + f(y + 1, k - 1);
	// Compare case 1 and case 2 to get the minimum


	int getMinSwaps(vector<int> A, int K)
	{
		int n = A.size();
		int f[MAX_K][MAX_K] = {0};	
		// init
		for (int k = 0; k < MAX_K; ++k) f[n][k] = 0;

		//
		for (int x = n - 1; x >= 0; --x)
		{
			for (int k = 0; k <= K; ++k)
			{
				// Case 1: x not in the reversed subarray
				vector<int> B1(A.begin(), A.begin() + x + 1);
				f[x][k] = getCurNiXuNumber(B1, x) + f[x+1][k];

				// Case 2: x in the reversed subarray
				if (k >= 1)
				{
					for (int y = x + 1; y < n; ++y)
					{
						vector<int> B2(A.begin(), A.begin() + y + 1);
						reverse(B2.begin() + x, B2.begin() + y + 1);
						f[x][k] = min(f[x][k],
								      getCurNiXuNumber(B2, x) + f[y+1][k-1]);
					}
				}
			}
		}

		return f[0][K];
	}
public:
	static const int MAX_K = 51;
};
