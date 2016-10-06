#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 采用数学公式求解
 *
 * 其他解法：
 * 可以采用双指针法，如果和太小，则移动big指针；否则，
 * 如果和太大，则移动small指针
 */

vector<vector<int> > FindContinuousSequence(int S) {
	vector<vector<int> > ans;
	int max_len = ceil((sqrt(1.0+8*S)-1)/2.0);
	for (int len = 2; len <= max_len; ++len) {
		if ((2 * S) % len != 0) {
			continue;
		} else {
		    int basum = (2 * S)/len;
		    int badiff = len - 1;
		    int b = 0; int a = 0;
		    if ((basum + badiff) % 2 != 0 || (basum - badiff) % 2 != 0) {
		    	continue;
			} else {
				b = (basum + badiff) / 2;
		    	a = (basum - badiff) / 2;
			}
			
			if (a >=1 && a < b) {
				vector<int> temp;
				for (int i = a; i <= b; ++i) {
					temp.push_back(i);
				}
				ans.push_back(temp);
			}
			
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

void PrintVec(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) cout << " " << v[i];
	cout << endl;
}

int main()
{
	vector<vector<int>> ans = FindContinuousSequence(100);
	cout << "size = " << ans.size() << endl;
	for (size_t i = 0; i < ans.size(); ++i) {
		PrintVec(ans[i]);
	}
	cout << endl;
	return 0;
}
