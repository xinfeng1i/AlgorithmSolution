#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> ans;
	if (size == 0 || size > num.size()) return ans;
	
	int n = static_cast<int>(num.size());
	set<int, greater<int>> window;
	int i = 0;
	int j = i + size;
	
	for (int k = i; k < j; ++k) window.insert(num[k]);
	ans.push_back(*window.begin());
	for (int k = j; k < n; ++k) {
		window.erase(num[i++]);
		window.insert(num[k]);
		ans.push_back(*window.begin());
	}
	
	return ans;
}

int main()
{
	int a[] = {2,3,4,2,6,2,5,1};
	vector<int> v(a, a+8);
	vector<int> ans = maxInWindows(v, 3);
	for (int x : ans) cout << " " << x << endl;
	return 0;
}
