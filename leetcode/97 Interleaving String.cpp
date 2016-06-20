#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if (s3.size() != s1.size() + s2.size()) return false;
    
    int m = (int) s1.size();
    int n = (int) s2.size();
    // dp[i][j] = the first i chars in s1, the first j chars in s2
    // can or not can construct to the first (i+j) chars in s3
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    // base case
    for (int len = 0; len <= n; ++len) {
        dp[0][len] = (s2.substr(0, len) == s3.substr(0, len));
    }
    for (int len = 0; len <= m; ++len) {
        dp[len][0] = (s1.substr(0, len) == s3.substr(0, len));
    }
    
    // bottom to up
    // the last char in s3[i+j-1] either comes from s1[i-1] or s2[j-1]
    // one of them lead to true, then the result is true
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = false;
            if (s1[i-1] == s3[i+j-1] && dp[i-1][j] == true) {
                dp[i][j] = true;
            }
            if (s2[j-1] == s3[i+j-1] && dp[i][j-1] == true) {
                dp[i][j] = true;
            }
        }
    }
    return dp[m][n];
}


int main() {
	string s1 = "aabc";
	string s2 = "abad";
	string s3 = "aabadabc";
	cout << isInterleave(s1, s2, s3) << endl;
	return 0;
}
