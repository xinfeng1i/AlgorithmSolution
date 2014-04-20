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

// AC code: 243 pts.
string simulate(string s)
{
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i + 1 < s.size(); ++i)
        {
            if (s[i] == s[i + 1])
            {
                flag = true;
                s = s.substr(0, i) + s.substr(i + 2);
            }
        }
    }
    return s;
    
}