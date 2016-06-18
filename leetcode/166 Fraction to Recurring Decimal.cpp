#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

string fractionToDecimal(int a, int b) {
	if (b == 0) return "";
	int flag = (a * b >= 0) ? 1 : -1;
	long long x = abs(long long (a));
	long long y = abs(long long (b));
	if (x % y == 0) {
		return to_string(x/y);
	} else {
		long long zhengPart = x / y;

		size_t idx = 0;
		vector<pair<long long, string>> v;
		x = x % y;
		while (x != 0) {
			bool found = false;
			for (size_t i = 0; i < v.size(); ++i) {
				if (v[i].first == x) {
					idx = i;
					found = true;
					break;
				}
			}
			// has found the loop position
			if (found) {
				string ans = "";
				ans += to_string(zhengPart);
				ans += ".";
				for (size_t i = 0; i < v.size(); ++i) {
					if (i == idx) {
						ans += "(";
					}
					ans += v[i].second;
					if (i + 1 == v.size()) {
						ans += ")";
					}
				}
				if (flag == -1) {
					ans = "-" + ans;
				}
				return ans;
			}


			string temp = "";
			temp += to_string(x/y);
			v.push_back(make_pair(x, temp));
			x *= 10;
			x %= y;
		}
		string ans = "";
		ans += to_string(zhengPart);
		ans += ".";
		for (size_t i = 0; i < v.size(); ++i) {
			ans += v[i].second;
		}
		if (flag == -1) {
			ans = "-" + ans;
		}
		return ans;
	}
}

int main()
{
	int a = 1;
	int b = 90;
	cout << fractionToDecimal(a, b) << endl;
	return 0;
}