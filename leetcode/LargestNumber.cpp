#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

static bool cmpStr(string a, string b)
{
    return a + b < b + a;
}

string largestNumber(vector<int>& num)
{
	size_t n = num.size();
	vector<string> strs(n);
	for (size_t i = 0; i < n; ++i)
	{
		strs[i] = to_string(num[i]);
	}

	sort(strs.begin(), strs.end(), cmpStr);

	string ans = "";
	for (auto it = strs.rbegin(); it != strs.rend(); ++it)
	{
		ans += *it;
	}
	
	// special situations: leading '0's = 0
	if (ans.size() > 0 && ans[0] =='0') return "0";
	return ans;
}

int main()
{
	int a[] = {3, 30, 34, 5, 9};
	vector<int> v(a, a + 5);
	cout << largestNumber(v) << endl;
	return 0;
}
