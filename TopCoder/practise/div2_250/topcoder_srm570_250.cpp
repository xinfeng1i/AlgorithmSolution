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

// Ac: 239pts
class Chopsticks
{
public:
    int getmax(vector <int> length)
    {
        int n = length.size();
        vector<int> cnt(101, 0);
        for (int i = 0; i < n; ++i)
        {
            cnt[length[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < 101; ++i)
        {
            ans += cnt[i] / 2;
        }

        return ans;
    }
};