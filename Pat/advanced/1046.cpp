#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstdio>
using namespace std;

int main()
{
    long n = 0;
    scanf("%ld", &n);

    long long roundDist = 0LL;
    vector<long long> accu_dist(n+1);
    accu_dist[0] = 0LL;
    long long tmp = 0;
    for (long i = 0; i < n; ++i)
    {
        scanf("%lld", &tmp);
        roundDist += tmp;

        accu_dist[i+1] = accu_dist[i] + tmp;
    }


    int m = 0;
    scanf("%d", &m);

    long s, e;
    for (int i = 0; i < m; ++i)
    {
        scanf("%ld %ld", &s, &e);
        if (s > e)
        {
            swap (s, e);
        }

        long long sDist = accu_dist[e-1] - accu_dist[s-1];
        sDist = min(sDist, roundDist - sDist);
        printf("%lld\n", sDist);
    }

    return 0;

}
