#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 240 point.
int minimalMoves(string S)
{
    int cnt = 0;
    int n = S.size();
    for (int i = 0; i < n / 2; ++i)
    {
        if (S[i] == '<')
        {
            cnt++;
        }
    }
    for (int i = n / 2; i < n; ++i)
    {
        if (S[i] == '>')
        {
            cnt++;
        }
    }

    return cnt;
}