#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define N  15
#define M  15


int a[N][M] = {0};

void flood(int i, int j, int n ,int m)
{
    int curx = i;
    int cury = j;
    do{
        a[i][j] = 1;
        i = (i + 1) % n;
        j = (j + 1) % m;
    }while(i != curx || j != cury);
    return;
}

int cnt(int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            count += a[i][j];
        }
    }
    return count;
}

void clear(int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            a[i][j] = 0;
        }
    }
}

string ableTo(int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            clear(n, m);
            flood(i, j, n, m);
            if (cnt(n, m) == n * m)
            {
                return "Possible";
            }
        }
    }

    return "Impossible";
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << ableTo(n, m) << endl;
    return 0;
}
