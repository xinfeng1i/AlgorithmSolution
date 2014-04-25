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
    int n = 0;
    scanf("%d", &n);

    vector<int> v1(n);
    vector<int> v2(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v2[i]);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> ans(2 * n);
    auto it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), ans.begin());
    ans.resize(it - ans.begin());
    int k = ans.size();
    printf("%d\n", ans[(k-1) / 2]);
    return 0;
}