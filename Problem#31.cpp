#include <iostream>
#include <string>
#include <vector>
using namespace std;

int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};
/*
 * Dynamic Programming
 *
 * dp[i][j] = using the first i kinds of coins to construct sum j
 * then dp[i][j] = dp[i-1][j - k * coins[i - 1]], k = 0, 1, ... ,j / coins[i-1]
 *
 * init
 * dp[i][0] = 1, where i = 0, 1, 2, ... ,8
 */
int main()
{
    int dp[9][201] = {0};
    //init
    for (int i = 0; i < 9; ++i)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < 9; ++i)
    {
        for (int j = 1; j < 201; ++j)
        {
            int n = j / coins[i-1];
            int tmp = 0;
            for (int d = 0; d <= n; ++d)
            {
                tmp += dp[i-1][j - coins[i-1]*d];
            }
            dp[i][j] = tmp;
        }
    }

    cout << "the number of ways using 8 coins to make is : "
        << dp[8][200] << endl;

    return 0;
}


