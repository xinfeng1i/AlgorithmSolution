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

// VERSION1: last sample TLE
int getNumber(string S)
{
    int n = S.size();
    if (S == string(n, 'R') || S == string(n, 'G') || S == string(n, 'B'))
    {
        return 0;
    }
    else
    {
        return min(getNumber(S.substr(1)) + 1, getNumber(S.substr(0, n-1)) + 1);
    }
}

/*
// VERSION 2: O(n^3) complexity.
int getNumber(string S)
{
    int n = S.size();
    int ans = n - 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // left i, right j, between is [i...n-j-1]
            char ch = S[i];
            bool valid = true;
            for (int k = i + 1; k <= n -j - 1; ++k)
            {
                if (S[k] != ch)
                {
                    valid = false;
                }
            }

            if (valid == true)
            {
                ans = min(ans, i + j);
            }
        }
    }

    return ans;
}
*/

/* TODO
// find the longest continu
int getNumber(string S)
{
    int n = S.size();
    int ans = n - 1;

    int equalCnt = 1;
    for (int i = 1; i < n; ++i)
    {
        if (S[i] == S[i-1])
        {
            equalCnt++;
        }
        else
        {
            ans = min(ans, equalCnt);
            equalCnt = 1;
        }
    }
}
*/

int getNumber(string S)
{
    int n = S.size();
    char last = ' ';
    int cnt = 1;
    int maxCnt =  0;

    for (int i = 0; i < n; ++i)
    {
        char ch = S[i];
        if (S[i] == last) cnt++;
        else 
        {
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
            last = ch;
        }
    }
    return n - maxCnt;
}
