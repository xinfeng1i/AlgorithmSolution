#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

int searchInsertUtil(int A[], int left, int right, int target);

int searchInsert(int A[], int n, int target)
{
	if (n <= 0) return 0;
	return searchInsertUtil(A, 0, n-1, target);
}

int searchInsertUtil(int A[], int left, int right, int target)
{
	if (left > right) return left;

	int mid = (left + right) / 2;
	if (A[mid] == target) return mid;
	else if (A[mid] < target) return searchInsertUtil(A, mid + 1, right, target);
	else return searchInsertUtil(A, left, mid - 1, target);
}

int main()
{
	const int N = 100;
	int A[N];
	cout << "Input n" << endl;
	int n;
	cin >> n;
	cout << "Input n numbers:" << endl;
	for (int i = 0; i < n; ++i) cin >> A[i];
	cout << searchInsert(A, n, 8) << endl;
	return 0;
}


