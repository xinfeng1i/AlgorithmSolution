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


bool checkSatisfy(unordered_map<char, pair<int, int>>& cnt) {
    unordered_map<char, pair<int, int>>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second.first < it->second.second) return false;
    }
    return true;
}

int balancedString(string s) {
    int n = (int)s.size();

    // count the number of each char
    unordered_map<char, pair<int, int>> cnt;
    for (int i = 0; i < n; ++i) {
        if (cnt.find(s[i]) == cnt.end()) cnt[s[i]] = make_pair(0, 1);
        else cnt[s[i]].second++;
    }
    
    // calcuate the exceed chars that more than n/4
    int quota = n / 4;
    unordered_map<char, pair<int, int>>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        it->second.second -= quota;
    }

    int i = 0; 
    int j = 0;
    int ans = INT_MAX;
    while (j < n) {
        cnt[s[j]].first++;

        while (checkSatisfy(cnt)) {
            int curLength = j - i + 1;
            ans = min(ans, curLength);

            cnt[s[i]].first--;
            i++;
        }

        j++;
    }

    return ans == n ? 0 : ans;
}

#if 0
int main() {
    string s1 = "AAAD";
    cout << balancedString(s1) << endl;

    return 0;
}
#endif //0