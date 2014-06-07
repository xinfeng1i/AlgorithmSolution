#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Longest Bitonic Subsequence
 * 给定一个数组， 计算最长Bitonic Subsequence, Bitonic Subsequence是先增后
 * 降序列
 */

/*
 * 问题分析：LIS问题的变种
 * lis[i] = 以a[i]为结尾的最长Longest Incresing Subsequence
 * lds[i] = 以a[i]为开头的最长Longest Decresing Subsequence
 * 说明，lds其实就是反向数组的Lis
 *
 * 问题答案为 max(lis[i] + lds[i] - 1)
 */

int LongestBitonicSubsequence(int a[], int n)
{
	vector<int> lis(n);
	vector<int> lds(n);

	// Longest Incresing Subsequence (LIS)
	// lis[i] = then LIS ending with a[i]
	// lis[i] = max{lis[j] + 1}, i > j && a[i] > a[j]
	for (int i = 0; i < n; ++i) lis[i] = 1;
	for (int i = 1; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			if (a[i] > a[j] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	// Longest Decresing Subsequece (LDS)
	// lds[i] = the LDS starting with a[i]
	// lds[i] = max{lds[j] + 1},  if j > i && a[i] > a[j]
	for (int i = n - 1; i >= 0; --i) lds[i] = 1;	
	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = n - 1; j > i; --j)
		{
			if (a[i] > a[j] && lds[j] + 1 > lds[i])
			{
				lds[i] = lds[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, lis[i] + lds[i] - 1);
	}

	return ans;
}

int main()
{
	int a1[] = {1, 11, 2, 10, 4, 5, 2, 1};
	int a2[] = {12, 11, 40, 5, 3, 1};
	int a3[] = {80, 60, 30, 40, 20, 10};

	int ans1 = LongestBitonicSubsequence(a1, 8);
	int ans2 = LongestBitonicSubsequence(a2, 6);
	int ans3 = LongestBitonicSubsequence(a3, 6);
	
	cout << "test 1 ans : " << ans1 << endl;
	cout << "test 2 ans : " << ans2 << endl;
	cout << "test 3 ans : " << ans3 << endl;

}
