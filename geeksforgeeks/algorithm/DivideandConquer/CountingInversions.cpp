#include <iostream>
#include <string>
using namespace std;

int CountInversions(int a[], int n)
{
	int* temp = new int[n];
	return MergeSortAndCount(a, 0, n-1, temp);
}

int MergeSortAndCount(int a[], int left, int right, int temp[])
{
	if (left >= right) return 0;

	int mid = (left + right) / 2;
	int leftCnt = MergeSortAndCount(a, left, mid, temp);
	int rightCnt = MergeSortAndCount(a, mid + 1, right, temp);
	int mergeCnt = MergeAndCount(a, left, mid, right, temp);
	return leftCnt + rightCnt + mergeCnt;
}

int MergeAndCount(int a[], int left, int mid, int right, int temp[])
{
	int i = left;
	int j = mid + 1;
	int k = left;
	int cnt = 0;
	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];

		}
		else
		{
			temp[k++] = a[j++];
			cnt += mid - i + 1;
		}
	}
	while (i <= mid) temp[k++] = a[i++];
	while (j <= right) temp[k++] = a[j++];
	for (i = left; i <= right; ++i) a[i] = temp[i];

	return cnt;
}

int main()
{
	int a[] = {2, 4, 1, 3, 5}; //3
	int ans = CountInversions(a, 5);
	cout << ans << endl;
	return 0;
}