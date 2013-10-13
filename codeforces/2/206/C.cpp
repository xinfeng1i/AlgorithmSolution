#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp problem
//   0 1 2 3 4 5
// 0
// 1
// 2 
// 3 
// 4
// 5
int main()
{
    long n;
    int l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;

    vector<int> w(n);
    for (long i = 0; i < n; ++i)
    {
        cin >> w[i];
    }

    vector<vector<long> > dp(n + 1, vector<long>(n + 1));
    dp[0][0] = 0;
    dp[0][1] = w[1] * l;
    for (long j = 2; j <= n; ++j)
    {
        dp[0][j] = dp[0][j - 1] + w[j] * l + ql;
    }

    return 0;

}
