#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getCloseNumber(int x) {
	int low_bit = x & (-x);
	int larger = x + low_bit;
	int smaller = x - (low_bit >> 1);
	vector<int> ans;
	ans.push_back(smaller);
	ans.push_back(larger);
	return ans;
}

int main()
{
	vector<int> ans = getCloseNumber(2);
	cout << ans[0] << endl;
	cout << ans[1] << endl;
	return 0;
}
