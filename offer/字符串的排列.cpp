#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 经典的Permutation问题:回溯
 */

void PermutationHelper(string str, int lo, int hi, set<string>& ans)
{
	if (lo > hi) {
		ans.insert(str);
		return;
	}

	for (int i = lo; i <= hi; ++i) {
		swap(str[i], str[lo]);
		PermutationHelper(str, lo+1, hi, ans);
		swap(str[i], str[lo]);
	}
}


vector<string> Permutation(string str)
{
    vector<string> ans;
    if (str.empty()) return ans;
    
	sort(str.begin(), str.end());
	int n = static_cast<int>(str.size());
	set<string> s;
	PermutationHelper(str, 0, n-1, s);
	return vector<string>(s.begin(), s.end());
}

int main()
{
	vector<string> ans = Permutation("aa");
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
