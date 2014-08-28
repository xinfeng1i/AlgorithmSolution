#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

typedef long long llong;

int main()
{
    llong NC, NP;
    cin >> NC;
    vector<llong> coupons(NC);
    for (llong i = 0; i < NC; ++i)
    {
        cin >> coupons[i];
    }

    cin >> NP;
    vector<llong> products(NP);
    for (llong i = 0; i < NP; ++i)
    {
        cin >> products[i];
    }

    llong ans = 0;

    sort(coupons.begin(), coupons.end(), greater<llong>());
    sort(products.begin(), products.end(), greater<llong>());
    for (llong i = 0; i < min(NC, NP); ++i)
    {
        if (coupons[i] > 0 && products[i] > 0)
        {
            ans += coupons[i] * products[i];
        }
    }

    sort(coupons.begin(), coupons.end(), less<llong>());
    sort(products.begin(), products.end(), less<llong>());
    for (llong i = 0; i < min(NC, NP); ++i)
    {
        if (coupons[i] < 0 && products[i] < 0)
        {
            ans += coupons[i] * products[i];
        }
    }

    cout << ans << endl;

    return 0;
}
