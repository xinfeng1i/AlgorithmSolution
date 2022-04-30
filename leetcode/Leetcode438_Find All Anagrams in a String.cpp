#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

pair<bool, int> getExceedCount(unordered_map<char, pair<int, int>>& cnt) {
    bool ok = true;
    int exceedNum = 0;
    unordered_map<char, pair<int, int>>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second.second > 0 && it->second.first < it->second.second) {
            ok = false;
            return make_pair(ok, exceedNum);
        }
        exceedNum += it->second.first - it->second.second;
    }
    return make_pair(ok, exceedNum);
}


vector<int> findAnagrams(string s, string p) {
    unordered_map<char, pair<int, int>> cnt;
    for (size_t i = 0; i < p.size(); ++i) {
        if (cnt.find(p[i]) == cnt.end()) cnt[p[i]] = make_pair(0, 1);
        else cnt[p[i]].second++;
    }

    vector<int> ans;
    int n = (int)s.size();
    int i = 0;
    int j = 0;
    while (j < n) {
        // add current char to window
        if (cnt.find(s[j]) == cnt.end()) cnt[s[j]] = make_pair(1, 0);
        else cnt[s[j]].first++;

        // check the number of chars is satisfy requirement
        while(true) {
            pair<bool, int> check = getExceedCount(cnt);
            if (!check.first) break;

            if (check.second == 0) {
                ans.push_back(i);
            }

            cnt[s[i]].first--;
            i++;
        }

        j++;
    }

    return ans;
}

int main() {
    string s1 = "cbaebabacd";
    string p1 = "abc";
    vector<int> ans = findAnagrams(s1, p1);
    for (int x : ans) cout << " " << x;
    cout << endl;
    return 0;
}