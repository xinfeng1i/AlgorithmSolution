#include <iostream>
#include <string>
#include <vector>
using namespace std;

int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int main()
{
    int dp[9][201] = {0};
    //init
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 201; ++j)
        {
            dp[i][j] = 0;
        }
    }
    // base case
    for (int j = 1; j < 201; ++j)
    {
        dp[1][j] = 1;
    }

    for (int i = 2; i < 9; ++i)
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

    cout << "1st row:" << endl;
    cout << "2rd row:" << endl;
    for (int i = 0; i < 201; ++i)
    {
        cout << dp[1][i] << "," ;
    }
    cout << endl;
    for (int i = 0; i < 201; ++i)
    {
        cout << dp[2][i] << "," ;
    }
    cout << endl;
    return 0;
}


