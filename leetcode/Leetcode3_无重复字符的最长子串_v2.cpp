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


int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    if (s.size() == 1) return 1;

    unordered_set<char> visited;
    int ans = 1;

    int n = (int) s.size();
    int i = 0;
    int j = 0;
    while (j < n) {
        char tmpChar = s[j];
        
        // find repeated chars
        while (visited.find(tmpChar) != visited.end()) {
            visited.erase(s[i]);
            i++;
        }

        // now we have remove all the repeated chars
        visited.insert(tmpChar);
        int curLen = j - i + 1;
        ans = max(ans, curLen);

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
