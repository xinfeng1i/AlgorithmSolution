#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Maximum Chain Pairs
 * Given n pairs of numbers, s.t for every pair (a, b), a < b;
 * A pair(c, d) can follow a pair (a, b) iff b < c
 *
 * Find the longest Chain which can be formed.
 */

/*
 * Problem Analysis
 * 
 * See every pair as a int number, then the problem can be seen
 * a typical Longest Incresing Subsequence
 */

struct Pair
{
	int first;
	int second;
	Pair():first(0), second(0){}
	Pair(int a, int b):first(a), second(b){}
	bool operator<(const Pair& other) const
	{
		return second < other.first;
	}
};

int MaximumLengthChain(Pair a[], int n)
{
	vector<int> lis(n);

	//init
	for (int i = 0; i < n; ++i) lis[i] = 1;
	
	// bottom to up
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0;  j < i; ++j)
		{
			if (a[j] < a[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, lis[i]);
	}
	
	return ans;
}

int main()
{
	Pair a[5];
	a[0] = Pair(5, 24);
	a[1] = Pair(39, 60);
	a[2] = Pair(15, 28);
	a[3] = Pair(27, 40);
	a[4] = Pair(50, 90);
	
	int ans = MaximumLengthChain(a, 5);
	cout << "test ans : " << ans << endl;

	return 0;
}
