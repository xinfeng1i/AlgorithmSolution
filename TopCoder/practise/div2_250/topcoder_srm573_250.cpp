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

// AC: 244pts;
class SkiResortsEasy
{
public:
    int minCost(vector <int> altitude)
    {
        int n = altitude.size();
        int cost = 0;
        for (int i = 1; i < n; ++i)
        {
            if (altitude[i] > altitude[i-1])
            {
                cost += altitude[i] - altitude[i-1];
                altitude[i] = altitude[i-1];
            }
        }
        return cost;
    }
};