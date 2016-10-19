#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*
 * 递归解法，包含大量的重叠子问题
 */
int numDistinct(string s, string p) {
    if (p.size() > s.size()) return 0;
    if (p.size() == s.size()) return p == s?1:0;

    int pn = p.size();
    int sn = s.size();

    char last_ch = p[pn-1];
    int cnt  = 0;
    for (int j = sn-1; j >= max(0, pn-1); --j) {
        if (last_ch == s[j]) {
            cnt += numDistinct(s.substr(0, j), p.substr(0, pn-1));
        }
    }
    return cnt;
}

/*
 * 动态规划
 * dp[i][j] = p的前i个字符与s的前j个字符的具有的不同子序列数目
 * dp[i][j] = \sum_k {dp[i][k]}; k <= j && s[k-1] == p[i-1]
 */

int numDistinct2(string s, string p) {
	int pn = p.size();
	int sn = s.size();
	vector<vector<int>> dp(pn+1, vector<int>(sn+1, 0));
	for (int j = 0; j <= sn; ++j) dp[0][j] = 1;
	for (int i = 1; i <= pn; ++i) dp[i][0] = 0;

	for (int i = 1; i <= pn; ++i) {
		for (int j = i; j <= sn; ++j) {
			dp[i][j] = 0;
			char ch = p[i-1];
			for (int k = i-1; k <= j-1; ++k) {
				if (s[k] == ch) {
					dp[i][j] += dp[i-1][k];
				}
			}
		}
	}
	return dp[pn][sn];
}

/*
 * 方法二时间复杂度仍然过高，存在进一步优化的空间
 * 如果最后一个字符不相等，那么就是求dp[i][j-1]的值
 * 否则，最后一个字符相等，存在两种情况：
 *    情况一：最后一个字符配对,则需要求dp[i-1][j-1]的值
 *    情况二: 没有与最后一个字符配对，则需要求dp[i][j-1]的值
 */
int numDistinct3(string s, string p) {
	int pn = p.size();
	int sn = s.size();
	vector<vector<int>> dp(pn+1, vector<int>(sn+1, 0));
	for (int j = 0; j <= sn; ++j) dp[0][j] = 1;
	for (int i = 1; i <= pn; ++i) dp[i][0] = 0;

	for (int i = 1; i <= pn; ++i) {
		for (int j = i; j <= sn; ++j) {
			if (p[i-1] != s[j-1]) {
				dp[i][j] = dp[i][j-1];
			} else {
				dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
			}
		}
	}
	return dp[pn][sn];
}

int main()
{
	string s = "rabbbit";
	string p = "rabbit";
	cout << numDistinct2(s, p) << endl;
	return 0;
}

