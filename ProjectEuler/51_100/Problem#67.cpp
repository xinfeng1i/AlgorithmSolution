#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

typedef vector<vector<int> > matrix;
int maxPath(matrix m)
{
    int n = m.size();
    
    matrix dp(n);
    for (int i = 0; i < n; ++i)
    {
        dp[i].resize(n);
    }
    // init: first column
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 0;
        for (int ii = 0; ii <= i; ++ii)
        {
            dp[i][0] += m[ii][0];
        }
    }
    for (int i = 1; i < n; ++i)
    {
        for(int j = 1; j < i; ++j)
        {
            dp[i][j] = max(dp[i-1][j] + m[i][j], dp[i-1][j-1] + m[i][j]); 
        }
        dp[i][i] = dp[i-1][i-1] + m[i][i];
    }

    int max_num = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dp[n-1][i] > max_num)
        {
            max_num = dp[n-1][i];
        }
    }

    return max_num;
}

int main()
{
    const int MATRIX_SIZE = 100;
    matrix a(MATRIX_SIZE);
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        a[i].resize(MATRIX_SIZE);
    }

    ifstream fin("Problem#67_data.txt", ios::in);
    if (!fin.is_open())
    {
        cerr << "Cannot open file to read" << endl;
        exit(-1);
    }
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            fin >> a[i][j];
        }
    }
    fin.close();

    cout << "max path:" << maxPath(a) << endl;
    return 0;
}
