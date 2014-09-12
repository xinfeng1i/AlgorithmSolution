#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

void PrintVector(const vector<int>& v)
{
	cout << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << " "  << v[i];
	}
	cout << endl;
}


int main()
{
	int n = 0;
	cin >> n;
	vector<int> v1(n, 0);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v1[i];
		sum += v1[i];
	}

	if (sum % 3 != 0)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<int> v2(v1);
	for (int i = 1; i < n; ++i)
	{
		v1[i] += v1[i-1];
	}
	for (int j = n-2; j >= 0; --j)
	{
		v2[j] += v2[j+1];
	}

	int num1 = 0;
	vector<int> is;
	for (int i = 0; i < n; ++i)
	{
		if (v1[i] == sum / 3)
		{
			num1++;
			is.push_back(i+1);
		}
	}

	int num2 = 0;
	vector<int> js;
	for (int j = n-1; j >= 0; --j)
	{
		if (v2[j] == sum / 3)
		{
			num2++;
			js.push_back(j-1);
		}
	}

	sort(is.begin(), is.end());
	sort(js.begin(), js.end());

	int cnt = 0;
	vector<int>::iterator low;
	for (int i = 0; i < is.size(); ++i)
	{
		int ii = is[i];
		low = lower_bound(js.begin(),js.end(), ii);
		cnt += (js.end() - low);
	}

	cout << cnt << endl;
	

	/*
	//set<pair<int, int> > ans;
	int cnt = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = n-2; j >= i; --j)
		{
			if (v1[i-1] == v2[j+1] && sum == 3 * v1[i-1])
			{
				cnt++;
				//ans.insert(make_pair(i, j));	
			}
		}
	}
	cout << cnt << endl;
	*/
	return 0;
}
