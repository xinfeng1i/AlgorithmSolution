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


bool hasRepeatingChars(unordered_map<char, int>& cnt) {
    unordered_map<char, int>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second >= 2) return true;
    }
    return false;
}


// Given a string s, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    if (s.size() == 1) return 1;

    int n = (int)s.size();
    unordered_map<char, int> cnt;
    int ans = 0;
    
    int i = 0, j = 0;
    while (j < n) {
        // add current char
        if (cnt.find(s[j]) == cnt.end()) cnt[s[j]] = 1;
        else cnt[s[j]]++;

        // check if there is repeating chars
        while (hasRepeatingChars(cnt)) {
            cnt[s[i]]--;
            i++;
        }

        // here, no repeating chars
        int curLength = j - i + 1;
        ans = max(ans, curLength);
        j++;
    }
    return ans;
}

#if 0
int main() {
    string s1 = "abc";
    cout << lengthOfLongestSubstring(s1) << endl;

    string s2 = "aaa";
    cout << lengthOfLongestSubstring(s2) << endl;

    string s3 = "aab";
    cout << lengthOfLongestSubstring(s3) << endl;

    return 0;
}
#endif // 0