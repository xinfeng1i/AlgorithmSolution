#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <set>
using namespace std;

#define EPS 1e-6

int main()
{
    int n = 0;
    scanf("%d", &n);
    double x = 0.0;
    double s1 = 0.0;
    long long s2 = 0;
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        scanf("%lf", &x);
        s1 += x;
        s2 += (int)x;

        // cnt - count the number of integers
        if (x - (int)x < EPS)
        {
            cnt++;
        }
    }

    long long smin = s2 + (cnt < n ? (n - cnt) : 0);
    long long smax = s2 + (cnt < n ? n : (2 * n - cnt));

    double ans = 1e9;
    for (long long i = smin; i <= smax; ++i)
    {
        ans = min(ans, abs(s1 - i));
    }

    printf("%0.3f\n", ans);
    return 0;
}

// Summary:
// 1. Main idea find the mimimum integer and max integer after the round down
//    round up, it can take. discuss the two different conditions
// 2. Involve large amount of I/O, use scanf/printf
//
// Created by python27
// 2013/10/07
