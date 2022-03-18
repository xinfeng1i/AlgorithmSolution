#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


bool checkSuccess(map<char, pair<int, int>>& cnt) {
    map<char, pair<int, int>>::const_iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        char ch = it->first;
        pair<int, int> p = it->second;
        if (p.first < p.second) {
            return false;
        }
    }
    return true;
}

// Notice Here: using two flags will import not key chars
bool isReduntChar(map<char, pair<int, int>>& cnt, char ch) {
    return cnt.find(ch) == cnt.end() || cnt[ch].first > cnt[ch].second;
}

void printCnt(map<char, pair<int, int>>& cnt) {
    map<char, pair<int, int>>::const_iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        char k = it->first;
        pair<int, int> p = it->second;
        cout << k << " " << p.first << " " << p.second << endl;
    }

}


void removeReduntChar(map<char, pair<int, int>>& cnt, char ch) {
    if (cnt.find(ch) == cnt.end()) {
        return;
    }
    else {
        cnt[ch].first -= 1;
    }
}


string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";

    int m = (int)s.size();
    int n = (int)t.size();
    map<char, pair<int, int>> cnt;  // char, current_cnt, target_cnt
    // init the T string char count
    for (int i = 0; i < n; ++i) {
        char ch = t[i];
        if (cnt.find(ch) == cnt.end()) {
            cnt[ch] = make_pair(0, 1);
        }
        else {
            int old = cnt[ch].second;
            cnt[ch] = make_pair(0, old + 1);
        }
    }

    int ans = INT_MAX;
    int ansStart = -1;
    int i = 0;
    int j = 0;
    while (j < m) {
        while (!checkSuccess(cnt) && j < m) {
            int ch = s[j];
            if (cnt.find(ch) != cnt.end()) cnt[ch].first += 1;
            j++;
        }

        if (j >= m && !checkSuccess(cnt)) {
            break;
        }
        
        while (isReduntChar(cnt, s[i])) {
            removeReduntChar(cnt, s[i]);
            i++;
        }
        if (j - i < ans) {
            ans = j - i;
            ansStart = i;
        }

        if (cnt.find(s[i]) != cnt.end()) cnt[s[i]].first -= 1;
        i++;
    }

    return ans == INT_MAX ? "" : s.substr(ansStart, ans);
    // 如果当前cnt不满足要求，则扩大右侧窗口直到满足要求
    // 然后如果左侧窗口不是关键字符，则不断缩进左侧窗口，直到到关键字符
    // 更新ans为当前窗口长度
    // 左侧窗口减去1，进行下一轮迭代
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string ans = minWindow(s, t);
    cout << ans << endl;

    return 0;
}
