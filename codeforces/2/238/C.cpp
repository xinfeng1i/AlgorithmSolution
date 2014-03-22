#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef vector<vector<int> > Matrix;

void printVector(const Matrix& m)
{
    int n = m.size();
    cout << "***matirx:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n***ED***\n");
}
void flipRow(int i, Matrix& m)
{
    for (int j = 0; j < m.size(); j++)
    {
        m[i][j] = 1 - m[i][j];
    }
}
void flipCol(int j, Matrix& m)
{
    for (int i = 0; i < m.size(); ++i)
    {
        m[i][j] = 1 - m[i][j];
    }
}

int unusualSquare(const Matrix& m)
{
    int n = m.size();
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            sum += m[i][k] * m[k][i]; 
        }
    }
    return sum % 2;
}


int main()
{
    //freopen("data.txt", "r", stdin);

    int n = 0;
    scanf("%d", &n);

    vector<vector<int> > a(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    string ans;
    int type = 0;
    int row = 0;
    int col = 0;
    int q = 0;
    scanf("%d", &q);
    for (int k = 0; k < q; ++k)
    {
        scanf("%d", &type);
        if (type == 3)
        {
            int tmp = unusualSquare(a);
            ans.push_back(tmp + '0');
            cout << "tmp" << tmp << endl;
            printVector(a);
        }
        else if (type == 1)
        {
            scanf("%d", &row);
            flipRow(row, a);
            printVector(a);
        }
        else
        {
            scanf("%d", &col);
            flipCol(col, a);
            printVector(a);
        }
    }
    
    cout << ans << endl;
    return 0;

}
