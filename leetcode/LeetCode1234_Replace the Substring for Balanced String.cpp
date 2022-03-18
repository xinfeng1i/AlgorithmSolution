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


bool check(map<char, pair<int, int>>& cnt) {
    map<char, pair<int, int>>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        char k = it->first;
        if (cnt[k].first < cnt[k].second) {
            return false;
        }
    }
    return true;
}

int balancedString(string s) {
    int n = (int)s.size();
    vector<int> init = { 0, 0, 0, 0 };
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'Q') init[0]++;
        else if (s[i] == 'W') init[1]++;
        else if (s[i] == 'E') init[2]++;
        else if (s[i] == 'R') init[3]++;
    }
    int quad = n / 4;
    if (init[0] == quad && init[1] == quad && init[2] == quad && init[3] == quad) return 0;

    map<char, pair<int, int>> cnt;  // char, current_cnt, target_cnt
    if (init[0] > quad) cnt['Q'] = make_pair(0, init[0] - quad);
    if (init[1] > quad) cnt['W'] = make_pair(0, init[1] - quad);
    if (init[2] > quad) cnt['E'] = make_pair(0, init[2] - quad);
    if (init[3] > quad) cnt['R'] = make_pair(0, init[3] - quad);

    int i = 0;
    int j = 0;
    int ans = INT_MAX;
    while (j < n) {
        while (j < n && !check(cnt)) {
            if (cnt.find(s[j]) != cnt.end()) cnt[s[j]].first++;
            j++;
        }
        if (j >= n && !check(cnt)) break;

        while (check(cnt) && (cnt.find(s[i]) == cnt.end() || cnt[s[i]].first > cnt[s[i]].second)) {
            if (cnt.find(s[i]) != cnt.end()) cnt[s[i]].first--;
            i++;
        }
        ans = min(ans, j - i);

        cnt[s[i]].first--;
        i++;
    }
    return ans;
}


int balancedString_Implent2(string s) {
    int n = (int)s.size();
    vector<int> init = { 0, 0, 0, 0 };
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'Q') init[0]++;
        else if (s[i] == 'W') init[1]++;
        else if (s[i] == 'E') init[2]++;
        else if (s[i] == 'R') init[3]++;
    }
    int quad = n / 4;
    if (init[0] == quad && init[1] == quad && init[2] == quad && init[3] == quad) return 0;

    map<char, pair<int, int>> cnt;  // char, current_cnt, target_cnt
    if (init[0] > quad) cnt['Q'] = make_pair(0, init[0] - quad);
    if (init[1] > quad) cnt['W'] = make_pair(0, init[1] - quad);
    if (init[2] > quad) cnt['E'] = make_pair(0, init[2] - quad);
    if (init[3] > quad) cnt['R'] = make_pair(0, init[3] - quad);

    int i = 0;
    int ans = INT_MAX;
    for (int j = 0; j < n; ++j) {
        if (!check(cnt)) {
            if (cnt.find(s[j]) != cnt.end()) cnt[s[j]].first++;
        }
        
        while (check(cnt)) {
            ans = min(ans, j - i + 1);
            if (cnt.find(s[i]) != cnt.end()) cnt[s[i]].first--;
            i++;
        }
    }
    return ans;
}


#if 0
int main() {
    string s1 = "QWER";
    string s2 = "QQWE";
    string s3 = "QQQW";
    //cout << balancedString_Implent2(s1) << endl;
    //cout << balancedString_Implent2(s2) << endl;
    cout << balancedString_Implent2(s3) << endl;

    return 0;
}
#endif // 0