#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*
 * 问题描述：
 * 计算组合数C(n,k)
 */

/*
 * 解题思路：
 * 由组合数的性质：
 * C(n, k) = C(n-1, k) + C(n-1, k-1)
 * C(n, 0) = C(n, n) = 1
 *
 * 定义 C(i, j) = 从i选择j个的组合数(i >= j)
 * 则原问题等价于求解C(n, k)
 * C(i, j) = C(i-1, j-1) + C(i-1, j) j <= i
 * C(i, i) = C(i, 0) = 1
 */

int BinomialCoefficient(int n, int k)
{
    assert(n >= k);
    
    int C[n+1][k+1];


    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= min(k, i); ++j)
        {
            if (j == i || j == 0)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = C[i-1][j-1] + C[i-1][j]; 
            }
        }
    }

    return C[n][k];
}

int main()
{
    cout << "Enter n & k" << endl;
    int n, k;
    cin >> n >> k;
    cout << BinomialCoefficient(n, k) << endl;
    return 0;
}
