#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

string ableTo(int n, int m)
{
    vector<vector<int> > v(n, vector<int>(m, 0));

    int x = 0, y = 0;
    int cnt = 0;
    while (!v[x][y])
    {
        v[x][y] = 1;
        cnt++;

        x = (x + 1)%n;
        y = (y + 1)%m;
    }

    if (cnt == n * m)
    {
        return "Possible";
    }
    else
    {
        return "Impossible";
    }
}