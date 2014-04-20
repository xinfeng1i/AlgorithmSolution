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

// AC code: 200
// brute force
class ShoutterDiv2
{
public:

int count(vector <int> s, vector <int> t)
{
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int enteringTime = s[i];
        int leavingTime = t[i];
        for (int j = i + 1; j < n; ++j)
        {
            if ( !(t[j] < enteringTime || s[j] > leavingTime) )
            {
                cnt++;
            }
        }
    }

    return cnt;
}

};