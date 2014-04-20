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


// AC code: 207pt
// brute force
string minNumber(string num)
{
    string ans(num);
    string curNum;
    int n = num.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            curNum = num;
            swap(curNum[i], curNum[j]);
            if (curNum[0] != '0')
            {
                if (curNum < ans)
                {
                    ans = curNum;
                }
            }
        }
    }

    return ans;
}

