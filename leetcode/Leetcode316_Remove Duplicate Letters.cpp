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


// µ¥µ÷stack chanllege problem
// Time: O(n)
// Space: O(n)
string removeDuplicateLetters(string s) {
    int n = s.size();
    map<char, int> char2cnt;
    for (int i = 0; i < n; ++i) {
        if (char2cnt.find(s[i]) == char2cnt.end()) {
            char2cnt[s[i]] = 1;
        }
        else {
            char2cnt[s[i]] += 1;
        }
    }

    set<char> instack;
    stack<char> S;

    for (int i = 0; i < n; ++i) {
        while (!S.empty() && S.top() > s[i] && instack.find(s[i]) == instack.end() && char2cnt[S.top()] >= 2) {
            char ch = S.top(); S.pop();
            char2cnt[ch] -= 1;
            instack.erase(ch);
        }

        if (instack.find(s[i]) == instack.end()) {
            S.push(s[i]);
            instack.insert(s[i]);
        }
        else {
            char2cnt[s[i]] -= 1;
        }

    }

    vector<int> v;
    while (!S.empty()) {
        v.push_back(S.top());
        S.pop();
    }
    string ans(v.rbegin(), v.rend());

    return ans;
}


int main() {
    string s = "bcabc";
    string s2 = "cbacdcbc";
    string ans  = removeDuplicateLetters(s2);
    cout << ans << endl;
    return 0;
}