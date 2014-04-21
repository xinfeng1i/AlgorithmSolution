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

// AC code: 251.3pts
class SlimeXSlimonadeTycoon
{
public:
    int sell(vector <int> morning, vector <int> customers, int stale_limit)
    {
        int ans = 0;
        int n= morning.size();
        for (int i = 0; i < n; ++i)
        {
            int supply = morning[i];
            for (int j = 0; j < stale_limit; ++j)
            {
                if (supply <= customers[i+j])
                {
                    ans += supply;
                    customers[i+j] -= supply;
                    break;
                }
                else
                {
                    ans += customers[i+j];
                    supply -= customers[i+j];
                    customers[i+j] = 0;
                }
            }
        }

        return ans;
    }
};