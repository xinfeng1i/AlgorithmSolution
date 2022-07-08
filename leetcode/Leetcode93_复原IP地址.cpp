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


bool isValidIPNum(const string& s) {
    if (s.empty()) return false;
    int num = atoi(s.c_str());
    if (num < 0 || num > 255) return false;
    if (num != 0 && s[0] == '0') return false;
    if (num == 0 && s.size() > 1) return false;
    return true;
}


string joinSofar(const vector<string>& sofar) {
    assert(sofar.size() == 4);
    string ans = "";
    for (size_t i = 0; i < sofar.size(); ++i) {
        if (i != 0) {
            ans += ".";    
        }
        ans += sofar[i];
    }
    return ans;
}


// Time: O(3^4)
// Space: O(n), where n = sofar.length()
void solveIPAddr(vector<string>& sofar, string& s, int idx, int n, int remainCnt, vector<string>& globalAns) {
    if (remainCnt == 0) {
        string last = s.substr(idx, n - idx);
        if (isValidIPNum(last)) {
            sofar.push_back(last);
            // cout << "found a solution: " << joinSofar(sofar) << endl;
            globalAns.push_back(joinSofar(sofar));
            sofar.pop_back();
        }
        return;
    }

    if (remainCnt > 0 && idx == n) {
        return;
    }

    for (int j = idx; j < n; ++j) {
        int len = j - idx + 1;
        string temp = s.substr(idx, len);
        if (isValidIPNum(temp)) {
            sofar.push_back(temp);
            solveIPAddr(sofar, s, j + 1, n, remainCnt - 1, globalAns);
            sofar.pop_back();
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    int n = (int)s.size();
    int remainCnt = 3;

    vector<string> sofar;
    vector<string> ans;

    solveIPAddr(sofar, s, 0, n, remainCnt, ans);

    return ans;
}

int main() {
    // string s = "25525511135";
    // string s = "0000";
    // string s = "101023";
    string s = "010010";

    vector<string> ans = restoreIpAddresses(s);
    for (string x : ans) {
        cout << x << endl;
    }
    
    return 0;
}