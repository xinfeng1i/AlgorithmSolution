#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int a = 0;
int b = 0;
int n = 0;
int m = 0;
int i = 0; 
int j = 0;
vector<vector<int> > matrix;

void init()
{
    matrix.resize(n + 1);
    for (int i = 0; i < n + 1; ++i)
    {
        matrix[i].resize(m + 1); 
    }

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < m + 1; ++j)
        {
            matrix[i][j] = 0;
        }
    }
}

void printMatrix()
{
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void flood(int i, int j, int deep)
{
    if (matrix[i][j] != 0)
    {
        return;
    }

    matrix[i][j] = deep;
    
    if (i - a >= 1 && j - b >= 1 && matrix[i-a][j-b] == 0)
    {
        flood(i - a, j - b, deep + 1);
    }

    if (i + a <= n && j - b >= 1 && matrix[i+a][j-b] == 0)
    {
        flood(i + a, j - b, deep + 1);
    }

    if (i - a >= 1 && j + b <= m && matrix[i-a][j+b] == 0)
    {
        flood(i - a, j + b, deep + 1);
    }
    
    if (i + a <= n && j + b <= m && matrix[i+a][j+b] == 0)
    {
        flood(i + a, j + b, deep + 1);
    }
}

int main()
{
    cin >> n >> m >> i >> j >> a >> b;
    
    init();
    flood(i, j, 1);

    if (matrix[1][m] == 0 && matrix[n][1] == 0 &&
        matrix[n][m] == 0 && matrix[1][1] == 0)
    {
        cout << "Poor Inna and pony!" << endl; 
    }
    else
    {
        int ans = max(n, m) + 1;
        if (matrix[1][m] != 0 && matrix[1][m] < ans)
        {
            ans = matrix[1][m];
        }

        if (matrix[n][1] != 0 && matrix[n][1] < ans)
        {
            ans = matrix[n][1];
        }

        if (matrix[n][m] != 0 && matrix[n][m] < ans)
        {
            ans = matrix[n][m];
        }

        if (matrix[1][1] != 0 && matrix[1][1] < ans)
        {
            ans = matrix[1][1];
        }

        cout << ans << endl;
        printMatrix();
    }

    return 0;
}
