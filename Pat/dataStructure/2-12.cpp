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

#if 0
int main()
{
    vector<int> v1;
    vector<int> v2;
    int tmp;
    while (true)
    {
        scanf("%d", &tmp);
        if (tmp == -1) break;
        else v1.push_back(tmp);
    }

    while(true)
    {
        scanf("%d", &tmp);
        if (tmp == -1) break;
        else v2.push_back(tmp);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int> ans(v1.size() + v2.size());
    auto it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), ans.begin());
    ans.resize(it - ans.begin());

    if (ans.size() == 0)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); ++i)
        {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }

    return 0;
}
#endif //0