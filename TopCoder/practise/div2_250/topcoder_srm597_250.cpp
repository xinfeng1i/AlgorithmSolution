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
using namespace std;


// AC code: 229 pt
int getMin(vector <int> position)
{
    int ans = numeric_limits<int>::max();
    int n = position.size();
    for (int skip = 1; skip <= n - 2; ++skip)
    {
        vector<int> tmp;
        for (int i = 0; i < n; ++i)
        {
            if (i != skip)
            {
                tmp.push_back(position[i]);
            }
        }

        int dist = 0;
        for (int i = 0; i + 1 < tmp.size(); ++i)
        {
            dist += abs(tmp[i] - tmp[i+1]);
        }

        ans = min(ans, dist);
    }

    return ans;
}