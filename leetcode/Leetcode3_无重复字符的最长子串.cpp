#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


bool hasDuplicateChar(unordered_map<char, int>& cnt) {
    unordered_map<char, int>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second >= 2) return true;
    }
    return false;
}


int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    if (s.size() == 1) return 1;

    unordered_map<char, int> cnt;
    int ans = 1;
    int n = (int)s.size();
    int i = 0;
    int j = 0;
    while (j < n) {
        if (cnt.find(s[j]) == cnt.end()) {
            cnt[s[j]] = 1;
        }
        else {
            cnt[s[j]]++;
        }

        while (hasDuplicateChar(cnt)) {
            cnt[s[i]]--;
            i++;
        }

        int len = j - i + 1;
        ans = max(ans, len);
        j++;
    }

    return ans;
}


int main() {
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";

    cout << lengthOfLongestSubstring(s1) << endl;
    cout << lengthOfLongestSubstring(s2) << endl;
    cout << lengthOfLongestSubstring(s3) << endl;

    return 0;
}