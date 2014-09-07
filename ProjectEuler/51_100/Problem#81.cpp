#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

typedef vector<vector<int> > matrix;

/*
 * Min Path from the top left to bottom right
 */
int minPath(matrix m)
{
    int n = m.size();
    matrix dp(n);
    for (int i = 0; i < n; ++i)
    {
        dp[i].resize(n);
    }
    // init: the first row
    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = 0;
        for (int i = 0; i <= j; ++i)
        {
            dp[0][j] += m[0][i];
        }
    }
    // init the first column
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 0;
        for (int j = 0; j <= i; ++j)
        {
            dp[i][0] += m[j][0];
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            dp[i][j] = min(dp[i-1][j] + m[i][j], dp[i][j-1] + m[i][j]);
        }
    }
    return dp[n-1][n-1];
}

int main()
{
    const int MATRIX_SIZE = 80;
    matrix a(MATRIX_SIZE); 
    for (int i = 0; i < MATRIX_SIZE; ++i)
    { 
        a[i].resize(MATRIX_SIZE);
    }

    ifstream fin("Problem#81_data.txt", ios::in);
    if (!fin.is_open())
    {
        cerr << "Cannot Open File to Read! Retry" << endl;
        exit(-1);
    }
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int j = 0; j < MATRIX_SIZE; ++j)
        {
            fin >> a[i][j];
        }
    }
    fin.close();
    cout << "min path:" << minPath(a) << endl;
    return 0;
}
