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


bool exceedQuota(unordered_map<char, int>& cnt, int quota) {
    int totCnt = 0;
    int maxCnt = 0;
    unordered_map<char, int>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        totCnt += it->second;
        if (it->second > maxCnt) maxCnt = it->second;
    }
    return totCnt - maxCnt > quota;
}


int characterReplacement(string s, int k) {
    unordered_map<char, int> cnt;

    int ans = 0;

    int n = (int)s.size();
    int i = 0;
    int j = 0;
    while (j < n) {
        // add this char to window
        if (cnt.find(s[j]) == cnt.end()) cnt[s[j]] = 1;
        else cnt[s[j]]++;

        while (exceedQuota(cnt, k)) {
            cnt[s[i]]--;
            i++;
        }

        int curLength = j - i + 1;
        ans = max(ans, curLength);
        j++;
    }

    return ans;
}


#if 0
int main() {
    string s1 = "AABABBA";
    cout << characterReplacement(s1, 2) << endl;
    cout << characterReplacement(s1, 1) << endl;
    cout << characterReplacement(s1, 0) << endl;
    return 0;
}
#endif // 0