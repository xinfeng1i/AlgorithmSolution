#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


int minDistance(string A, string B) {
    if (A.empty() && B.empty()) return 0;
    if (A.empty() && !B.empty()) return (int)B.size();
    if (!A.empty() && B.empty()) return (int)A.size();

    int m = (int)A.size();
    int n = (int)B.size();
    // dp[i][j] 长度为i的A串与长度为j的B串之间的编辑距离
    // ans = dp[m][n]

    vector<vector<int>> dp;
    for (int i = 0; i <= m; ++i) {
        vector<int> temp = vector<int>(n + 1, 0);
        dp.push_back(temp);
    }

    // init: base case
    for (int j = 0; j <= n; ++j) dp[0][j] = j;
    for (int i = 0; i <= m; ++i) dp[i][0] = i;

    // bottom to up
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                int a = dp[i - 1][j] + 1;
                int b = dp[i][j - 1] + 1;
                int c = dp[i - 1][j - 1] + 1;
                dp[i][j] = min(min(a, b), c);
            }
        }
    }

    return dp[m][n];
}


#if 0
int main() {
    string s1 = "horse";
    string s2 = "ros";
    cout << minDistance(s1, s2) << endl;

    string w1 = "intention";
    string w2 = "execution";
    cout << minDistance(w1, w2) << endl;

    return 0;

}
#endif // 0