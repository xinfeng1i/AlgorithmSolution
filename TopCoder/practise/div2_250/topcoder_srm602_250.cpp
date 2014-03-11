#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// AC code : 210 pt
int count(vector <int> rating)
{
    int n = rating.size();

    int cnt = 0;
    if (rating[0] >= 1200)
    {
        cnt++;
    }
    for (int i = 1; i < n; ++i)
    {
        if (   (rating[i-1] >= 1200 && rating[i] < 1200)
            || (rating[i-1] < 1200 && rating[i] >= 1200) )
        {
            cnt++;
        }
    }

    return cnt;
}