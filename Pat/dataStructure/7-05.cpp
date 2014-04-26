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
#include <cassert>
using namespace std;

int main()
{
    long n, m;
    vector<long long> coupons_positive, coupons_negative;
    vector<long long> item_positive, item_negative;
    long long tmp;

    scanf("%ld", &n);
    for (long i = 0; i < n; ++i)
    {
        scanf("%lld", &tmp);
        if (tmp > 0) coupons_positive.push_back(tmp);
        else if (tmp < 0) coupons_negative.push_back(tmp);
        else continue;
    }

    scanf("%ld", &m);
    for (long i = 0; i < m; ++i)
    {
        scanf("%lld", &tmp);
        if (tmp > 0) item_positive.push_back(tmp);
        else if (tmp < 0) item_negative.push_back(tmp);
        else continue;
    }

    long long ans = 0;
    sort(coupons_positive.begin(), coupons_positive.end(), greater<long long>());
    sort(item_positive.begin(), item_positive.end(), greater<long long>());
    sort(coupons_negative.begin(), coupons_negative.end());
    sort(item_negative.begin(), item_negative.end());
    for (long i = 0; i < min(coupons_positive.size(), item_positive.size()); ++i)
    {
        ans += coupons_positive[i] * item_positive[i];
    }
    for (long i = 0; i < min(coupons_negative.size(), item_negative.size()); ++i)
    {
        ans += coupons_negative[i] * item_negative[i];
    }
    printf("%lld\n", ans);
    return 0;
}