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

bool windowSatisfy(unordered_map<char, pair<int, int>>& cnt) {
    unordered_map<char, pair<int, int>>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        pair<int, int> p = it->second;
        if (p.first < p.second) return false;
    }
    return true;
}

void printMyCnt(unordered_map<char, pair<int, int>>& cnt) {
    unordered_map<char, pair<int, int>>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        pair<int, int> p = it->second;
        cout << ">>> " << it->first << " " << p.first << " " << p.second << endl;
    }
}

string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";

    int m = (int)s.size();
    int n = (int)t.size();

    int ans = INT_MAX;
    int ansIndex = -1;

    unordered_map<char, pair<int, int>> cnt;
    for (int i = 0; i < n; ++i) {
        if (cnt.find(t[i]) == cnt.end()) cnt[t[i]] = make_pair(0, 0);
        cnt[t[i]].second++;
    }

    int i = 0;
    int j = 0;
    while(j < m) {
        // 窗口right进入窗口
        if (cnt.find(s[j]) == cnt.end()) cnt[s[j]] = make_pair(0, 0);
        cnt[s[j]].first++;

        // 如果已经满足要求，则left缩减，直到不满足
        while (windowSatisfy(cnt)) {
            int curLen = j - i + 1;
            // Notice: 这里也能错？服了自己了
            if (curLen < ans) {
                ans = curLen;
                ansIndex = i;
            }
            cnt[s[i]].first--;
            i++;
        }

        // 不满足要求，right更新，继续下一轮探索
        j++;
    }

    if (ans == INT_MAX) {
        return "";
    }
    else {
        return s.substr(ansIndex, ans);
    }
}

int main() {
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    //cout << minWindow(s1, t1) << endl;

    string s2 = "aa";
    string t2 = "a";
    //cout << minWindow(s2, t2) << endl;

    // expected: "cwae"
    string s3 = "cabwefgewcwaefgcf";
    string t3 = "cae";
    cout << minWindow(s3, t3) << endl;

    return 0;
}