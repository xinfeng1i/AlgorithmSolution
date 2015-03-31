#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long llong;

llong MergeAndCount(vector<unsigned int> &a, int left, int mid, int right, vector<unsigned int> &temp);
llong MergeSortAndCount(vector<unsigned int>& a, int left, int right, vector<unsigned int>& temp);
llong CountInversions(vector<unsigned int>& a);

int main()
{
	freopen("data.in", "r", stdin);

	int N;
	cin >> N;

	vector<unsigned int> a(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}

	llong result = CountInversions(a);
	cout << result << endl;
	return 0;
}

llong MergeAndCount(vector<unsigned int> &a, int left, int mid, int right, vector<unsigned int> &temp)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	llong cnt = 0;

	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else 
		{
			temp[k++] = a[j++];
			cnt += mid - i + 1;	// key step
		}
	}

	while (i <= mid) temp[k++] = a[i++];
	while (j <= right) temp[k++] = a[j++];

	for (i = left; i <= right; ++i)
	{
		a[i] = temp[i];
	}
	return cnt;
}

llong MergeSortAndCount(vector<unsigned int>& a, int left, int right, vector<unsigned int>& temp)
{
	// base case
	if (left >= right) return 0;

	int mid = (left + right) / 2;
	
	llong InversionCnt1 = MergeSortAndCount(a, left, mid, temp);
	llong InversionCnt2 = MergeSortAndCount(a, mid+1, right, temp);
	llong MergeInversionCnt = MergeAndCount(a, left, mid, right, temp);

	return InversionCnt1 + InversionCnt2 + MergeInversionCnt;
}

llong CountInversions(vector<unsigned int>& a)
{
	int n = a.size();
	vector<unsigned int> temp(a.begin(), a.end());
	llong ans = MergeSortAndCount(a, 0, n-1, temp);
	return ans;
}