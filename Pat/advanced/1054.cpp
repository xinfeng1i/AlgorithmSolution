#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    map<long, long> cnt;
    long color;
    for (long i = 0; i < m * n; ++i)
    {
        scanf ("%ld", &color);
        cnt[color]++;
    }

    long maxcnt = 0;
    long maxcolor = 0;
    for (auto it = cnt.begin(); it != cnt.end(); ++it)
    {
        if (it->second > maxcnt)
        {
            maxcnt = it->second;
            maxcolor = it->first;
        }
    }

    printf("%ld\n", maxcolor);

    return 0;
}
