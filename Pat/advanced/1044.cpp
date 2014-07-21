#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


int main()
{
    int n = 0; int m = 0;
    cin >> n >> m;
    
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
    }

    vector<pair<int, int> > ans; ans.reserve(n);
    vector<pair<int, int> > ans2; ans2.reserve(n);
    bool flag = false;
    int minLost = 1000000;

    vector<int> acc(n, 0);
    assert(acc.size() >= 1);
    acc[0] = v[0];
    for (int i = 1; i < n; ++i)
    {
        acc[i] = acc[i-1] + v[i];
    }

    int cursum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (i == 0) cursum = acc[j];
            else cursum = acc[j] - acc[i-1];
            if (cursum == m)
            {
                flag = true; 
                ans.push_back(make_pair(i, j));
                break;
            }
            else if (cursum > m && cursum - m < minLost)
            {
                minLost = cursum - m;
                ans2.clear();
                ans2.push_back(make_pair(i, j));
                break;
            }
            else if (cursum > m && cursum - m == minLost)
            {
                ans2.push_back(make_pair(i, j));
                break;
            }
        }
    }

    if (flag)
    {
        for (size_t i = 0; i < ans.size(); ++i)
        {
            printf("%d-%d\n", ans[i].first + 1, ans[i].second + 1);
        }
    }
    else
    {
        for (size_t i = 0; i < ans2.size(); ++i)
        {
            printf("%d-%d\n", ans2[i].first + 1, ans2[i].second + 1);
        }
    }

    return 0;
}
