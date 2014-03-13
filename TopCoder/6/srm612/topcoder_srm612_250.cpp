#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 241pt
int count(string S)
{
    int n = S.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (S[i] == 'R' && S[i+1] == 'L')
        {
            cnt++;
        }
    }
    return cnt;
}