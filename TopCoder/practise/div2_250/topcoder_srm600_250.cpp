#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <cstdio>
using namespace std;

int getLeastCost(vector <int> cnt, int baseCost, int seatCost)
{
    int n = cnt.size();
    int ans = numeric_limits<int>::max();

    for (int x = 1; x <= 100; ++x)
    {
        // init position
        int number = 0;
        for (int i = 0; i < n; ++i)
        {
            number += (int)ceil((cnt[i] + 0.0) / x);
        }

        ans = min(ans, number * (baseCost + x * seatCost));
    }

    return ans;
}

#if 0
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int fix, cost;
    cin >> fix >> cost;
    cout << getLeastCost(v, fix, cost) << endl;
    return 0;
}
#endif //0