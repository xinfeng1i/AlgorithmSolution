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


// AC code: 221pt.
int calculate(vector <int> seq)
{
    int n = seq.size();

    int cnt = 0;
    int last = -1;
    for (int i = 0; i < n; ++i)
    {
        if (seq[i] > last)
        {
            last = seq[i];
        }
        else
        {
            cnt++;
            last = seq[i];
        }
    }

    return cnt + 1;
}