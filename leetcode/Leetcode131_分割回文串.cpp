//
//  Leetcode131_分割回文串.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/9.
//

#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;


bool isHuiWen(const string& s) {
    if (s.empty()) return true;
    int n = (int) s.size();
    
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

// Time: O(n*2^n) 在最差的情况下，所有的字符都相等
// Space: O(n)
void solvePartitionHuiWen(vector<string>& path, string& s, int idx, int n, vector<vector<string>>& globalAns) {
    if (idx == n) {
        globalAns.push_back(path);
        return;
        
    }
    
    for (int i = idx; i < n; ++i) {
        int len = i - idx + 1;
        string prefix = s.substr(idx, len);
        if (isHuiWen(prefix)) {
            // 1. try a choice
            path.push_back(prefix);
            
            // 2. check success recursively
            solvePartitionHuiWen(path, s, i + 1, n, globalAns);
            
            // 3. backtracking
            path.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) {
    int n = (int) s.size();
    vector<string> path;
    vector<vector<string>> ans;
    solvePartitionHuiWen(path, s, 0, n, ans);
    return ans;
}


int main() {
    string s = "aab";
    
    vector<vector<string>> ans = partition(s);
    cout << "ans: " << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    
    
    
    return 0;
    
}
