#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;


void printDP(const vector<vector<int>>& mat) {
    int n = (int) mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << " " << mat[i][j];
        }
        cout << endl;
    }
    
}


string longestPalindrome(string A) {
    if (A.empty()) return "";
    if (A.size() == 1) return A;
    
    // dp[i][j]: 以[i...j]开头结尾的最长回文子串的长度
    // ans = max dp[i][j]
    int n = (int) A.size();
    vector<vector<int>> dp;
    for (int i = 0; i < n; ++i) {
        vector<int> temp(n, 0);
        dp.push_back(temp);
    }
    
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (len == 1) {
                dp[i][j] = 1;
            } else if (len == 2) {
                if (A[i] == A[j]) dp[i][j] = 2;
                else dp[i][j] = 0;
            } else {
                if (A[i] == A[j]) {
                    if (dp[i+1][j-1] == 0) dp[i][j] = 0;
                    else dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
    }
    
    int maxLength = 1;
    int startIdx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (dp[i][j] > maxLength) {
                maxLength = dp[i][j];
                startIdx = i;
            }
        }
    }
    
    return A.substr(startIdx, maxLength);
}


#if 0
int main() {
    string s = "xyabcbaz";
    string s2 = "aaaaaaa";
    cout << longestPalindrome(s) << endl;
    
    return 0;
}
#endif // 0
