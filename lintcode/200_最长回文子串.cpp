#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

#if 0
// Wrong Method1: ת���� A �� B ��������Ӵ�
string longestCommonSubstrHelper(string& A, string& B) {
    if (A.empty() || B.empty()) return "";

    int m = (int)A.size();
    int n = (int)B.size();
    vector<vector<int>> dp;
    for (int i = 0; i <= m; ++i) {
        vector<int> temp(n + 1, 0);
        dp.push_back(temp);
    }

    int maxCnt = 0;
    string maxStr = "";
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxCnt) {
                    maxCnt = dp[i][j];
                    maxStr = A.substr(i - maxCnt, maxCnt);
                }
            }
        }
    }
    return maxStr;
}
#endif // 0


#if 0
// Wrong Method2: 
string longestPalindrome(string& s) {
    if (s.empty()) return "";
    
    // dp[j]:��j��β�������ĳ���
    int n = (int)s.size();
    vector<int> dp(s.size(), 1);
    for (int j = 1; j < n; ++j) {
        int cnt = dp[j - 1];
        int start = j - cnt - 1;
        if (start >= 0 && s[start] == s[j]) {
            dp[j] = dp[j - 1] + 2;
        }
        else if (j - 1 >= 0 && s[j - 1] == s[j]) {
            dp[j] = 2;
        }
        else {
            dp[j] = 1;
        }
    }

    int maxCnt = 0;
    string maxStr = "";
    for (int j = 0; j < n; ++j) {
        if (dp[j] > maxCnt) {
            maxCnt = dp[j];
            int start = j + 1 - maxCnt;
            maxStr = s.substr(start, maxCnt);
        }
    }
    return maxStr;
}
#endif // 0


// 
// ��̬�滮��dp[len][i] ��ʾ��i��ͷ�ĳ���Ϊlen���ַ����Ƿ�Ϊ���Ĵ��������ų��ȣ�������0
// ״̬ת�ƣ�if s[i] == s[j]���� dp[len][i] = dp[len-2][i+2] + 2 or = 0
// ע����� i+2, len-2 == 0�����ʾ�����ⲻ�ǻ��Ĵ�����ʱ�� dp[len][i] = 0
// ʱ�临�Ӷȣ�O(n * n)
// �ռ临�Ӷȣ�O(n * n)
string longestPalindrome(string& s) {
    if (s.size() <= 1) return s;

    int n = (int)s.size();
    vector<vector<int>> dp;
    for (int len = 0; len <= n; ++len) {
        vector<int> temp(n, 0);
        dp.push_back(temp);
    }

    // init
    for (int i = 0; i < n; ++i) dp[0][i] = 0;
    for (int i = 0; i < n; ++i) dp[1][i] = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[2][i] = 2;
        }
        else {
            dp[2][i] = 0;
        }
    }


    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i < n; ++i) {
            int j = len + i - 1;
            if (j < n) {
                if (s[i] == s[j]) {
                    if (dp[len - 2][i + 1] > 0) {
                        dp[len][i] = dp[len - 2][i + 1] + 2;
                    }
                    else {
                        dp[len][i] = 0;
                    }
                }
                else {
                    dp[len][i] = 0;
                }
            }
        }
    }

    int maxLen = 1;
    int maxIdx = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n; ++i) {
            if (dp[len][i] > maxLen) {
                maxLen = dp[len][i];
                maxIdx = i;
            }
        }
    }

    return s.substr(maxIdx, maxLen);
}

#if 0
int main() {
    string s = "abcdzdcab";
    cout << longestPalindrome(s) << endl;

    string s2 = "aba";
    cout << longestPalindrome(s2) << endl;

    // ע1��ʹ��s��s.reverse���������Ӵ�����ͨ����case
    string s3 = "abceefcba";
    cout << longestPalindrome(s3) << endl;

    return 0;
}
#endif // 0