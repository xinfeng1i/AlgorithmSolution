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


bool check(map<char, int>& cnt) {
    return cnt['a'] >= 1 && cnt['b'] >= 1 && cnt['c'] >= 1;
}

int numberOfSubstrings(string s) {
    int n = (int)s.size();
    map<char, int> cnt;
    cnt['a'] = 0; cnt['b'] = 0; cnt['c'] = 0;

    int i = 0;
    int j = 0;
    int ans = 0;
    while (j < n) {
        while (j < n && !check(cnt)) { cnt[s[j]]++; j++; }
        if (j >= n && !check(cnt)) break;

        int prefix = 0;
        while (i < n && cnt[s[i]] >= 2) { prefix++; cnt[s[i]]--; i++; }
        ans += prefix + 1;
        ans += (n - j) * (prefix + 1);

        cnt[s[i]]--;
        i++;
    }
    return ans;
}