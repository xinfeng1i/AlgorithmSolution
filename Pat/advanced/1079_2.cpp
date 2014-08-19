#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int cntLevel(const vector<int>& prev, int i)
{
    int ans = 0;
    int cur = i;
    while (prev[cur] != -1)
    {
        ++ans;
        cur = prev[cur];
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n = 0;
    double p = 0.0;
    double r = 0.0;
    cin >> n >> p >> r;

    // init
    int k = 0;
    int nr = 0;
    int ac = 0;
    vector<int> prev(n, -1);
    vector<int> amount(n, 0);
    vector<int> level(n, -1);
    vector<int> leaves;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &k);
        if (k != 0)
        {
            for (int j = 0; j < k; ++j)
            {
                scanf("%d", &nr); 
                prev[nr] = i;
            }
        }
        else
        {
            scanf("%d", &ac); 
            amount[i] = ac; 
            leaves.push_back(i);
        }

    }

    double ans = 0.0;
    int maxLevel = 0;
    vector<double> price(n, 0.0);
    price[0] = p;
    for (size_t i = 0; i < leaves.size(); ++i)
    {
        int x = leaves[i];
        level[x] = cntLevel(prev, x);
        maxLevel = max(level[x], maxLevel);
    }

    for (int j = 1; j <= maxLevel; ++j)
    {
        price[j] = price[j-1] * (1 + r/100.0);
    }

    for (size_t i = 0; i < leaves.size(); ++i)
    {
        int x = leaves[i];
        double curPrice = price[level[x]];
        ans += curPrice * amount[x];
    }

    printf("%.1f\n", ans);
    return 0;
}
