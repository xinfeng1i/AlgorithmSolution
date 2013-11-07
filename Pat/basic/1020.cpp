#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

struct Item
{
    long amount_;
    long price_;
};


// dynamic problem
double max_profit(const vector<Item> &v, long n, long d)
{
    // dp[i][j] = max profit can be obtained from the first
    // i kinds of items, when market demand is j
    vector<vector<double> > dp(n + 1, vector<double>(d + 1,0.0));
    for (long i = 0; i <= n; ++i)
    {
        for (long j = 0; j <= d; ++j)
        {
            dp[i][j] = 0.0;
        }
    }

    for (long i = 1; i <= n; ++i)
    {
        for (long j = 1; j <= d; ++j)
        {
            double tmp_max = 0.0;
            long i_amount = v[i-1].amount_;
            long i_price = v[i-1].price_;
            double i_single_price = (double)i_price / i_amount;
            long i_max_amount = min(i_amount, d);
            for (long k = 0; k <= i_max_amount; ++k)
            {
                if (k <= j)
                {
                    double tmp = dp[i-1][j-k] + k * i_single_price; 
                    if (tmp > tmp_max)
                    {
                        tmp_max = tmp;
                    }
                }
            }
            dp[i][j] = tmp_max;
        }
    }

    return dp[n][d];
}


int main()
{
    //freopen("1020data.txt", "r", stdin);
    long n = 0;
    long d = 0;
    cin >> n >> d;

    vector<Item> v(n);
    for (long i = 0; i < n; ++i)
    {
        cin >> v[i].amount_;
    }

    for (long i = 0; i < n; ++i)
    {
        cin >> v[i].price_;
    }

    double ans = max_profit(v, n, d);
    printf("%0.2f\n", ans);
    return 0;
}
