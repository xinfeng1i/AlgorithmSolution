#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#if 0
unordered_map<char, int> cnt1;
unordered_map<char, int> cnt2;
int main()
{
	freopen("input.txt", "r", stdin);
	string s1, s2;
	cin >> s1 >> s2;
	for (size_t i = 0; i < s1.size(); ++i) {
		cnt1[s1[i]] += 1;
	}

	for (size_t i = 0; i < s2.size(); ++i) {
		cnt2[s2[i]] += 1;
	}

	bool ok = true;
	int extra = 0;
	int missing = 0;
	for (auto it = cnt2.begin(); it != cnt2.end(); ++it) {
		char ch = it->first;
		if (cnt1.find(ch) == cnt1.end() || cnt1[ch] < cnt2[ch]) {
			ok = false;
			break;
		}
	}

	if (ok) {
		cout << "Yes " << s1.size() - s2.size() << endl;
	} else {
		for (auto it = cnt2.begin(); it != cnt2.end(); ++it) {
			char ch = it->first;
			if (cnt1.find(ch) == cnt1.end()) {
				missing += cnt2[ch];
			} else if (cnt1[ch] < cnt2[ch]) {
				missing += (cnt2[ch] - cnt1[ch]);
			}
		}
		cout << "No " << missing << endl;
	}
	return 0;

}
#endif // 0