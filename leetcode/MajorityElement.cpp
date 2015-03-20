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

/*
 * Return a position k, such that all the elements in [left, k)
 * are smaller than or equal to num[k] && all the elements in
 * (k, right] are larger than num[k]
 * 
 * Note that here is the randomize version of partition, every time
 * we choose a random number as the pivot.
 */
int RandomPartition(vector<int> &num, int left, int right)
{	
	// random partition
	int rnd = rand() % (right - left + 1) + left;
	swap(num[rnd], num[right]);

	// pivot
	int x = num[right];
	int i = left - 1;
	for (int j = left; j < right; ++j)
	{
		if (num[j] <= x)
		{
			swap(num[j], num[i + 1]);
			i += 1;
		}
	}
	swap(num[right], num[i+1]);
	return i + 1;
}

/*
 * Return the i-th ordered element in num[left, right] but without
 * sorting the array.
 */

int RandomSelect(vector<int> &num, int left, int right, int i)
{
	if (right - left + 1 < i || left > right) return -1;

	// partition the num[], return the pivot position m
	int m = RandomPartition(num, left, right);

	// k is the number of element in num[left, m]
	int k = m - left + 1;

	if (k == i)
	{
		return num[m];
	}
	else if (k > i)
	{
		// find the i-th ordered element in num[left, m-1]
		return RandomSelect(num, left, m - 1, i);
	}
	else
	{
		// find the (i-k)-th ordered element in num[m+1, right]
		return RandomSelect(num, m + 1, right, i - k);
	}
}

/*
 * return the median of num[]
 */
int majorityElement(vector<int> &num)
{
	int n = num.size();
	int mid = n / 2;
	return RandomSelect(num, 0, n-1, mid);
}

int majorityElement2(vector<int>& num)
{
	int n = num.size();
	if (n < 0) return -1;
	if (n == 1) return num[0];

	int x = num[0];
	int mark = 1;
	for (int i = 1; i < n; ++i)
	{
		if (mark == 0)
		{
			mark = 1;
			x = num[i];
		}
		else if (num[i] == x)
		{
			mark++;
		}
		else if (num[i] != x)
		{
			mark--;
		}
	}
	return x;
}

int main()
{
	int a[] = {3, 2, 2};
	int b[] = {3, 2, 2, 2};

	vector<int> v1(a, a + 3);
	vector<int> v2(b, b + 4);

	cout << majorityElement2(v1) << endl;
	cout << majorityElement2(v2) << endl;

	return 0;
}