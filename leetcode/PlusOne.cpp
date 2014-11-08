#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
	vector<int> ans(digits.begin(), digits.end());
	int n = ans.size();
	ans[n-1] += 1;
	
	// handle carrys
	for (int j = n-1; j >= 1; j--)
	{
		if (ans[j] >= 10)
		{
			// NOTE: change the significant digit first
			ans[j-1] += ans[j] / 10;
			ans[j] = ans[j] % 10;
		}
	}

	// handle the first carry, may cause dynamic increse size
	if (n >= 1 && ans[0] >= 10)
	{
		int tmp = ans[0];
		ans[0] = tmp % 10;
		ans.insert(ans.begin(), tmp / 10);
	}
	return ans;
}

int main()
{
	vector<int> v(2, 9);
	vector<int> ans = plusOne(v);
	for (size_t i = 0; i < ans.size(); ++i) cout << ans[i];
	cout << endl;
	return 0;
}
