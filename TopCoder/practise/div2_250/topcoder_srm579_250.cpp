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


// AC code: 241pts
class PrimalUnlicensedCreatures
{
public:
    int maxWins(int initialLevel, vector <int> grezPower)
    {
        sort(grezPower.begin(), grezPower.end());

        int cnt = 0;
        for (int i = 0; i < grezPower.size(); ++i)
        {
            if (initialLevel > grezPower[i])
            {
                initialLevel += grezPower[i]/2;
                cnt++;
            }
            else
            {
                break;
            }
        }

        return cnt;
    }
};