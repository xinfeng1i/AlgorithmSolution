#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 210 pt
string getMin(string S, int L)
{
    string ans(S);
    int n = S.size();
    for (int i = 0; i <= n - L; ++i)
    {
        string magic = S.substr(i, L);
        sort(magic.begin(), magic.end());
        string cur = S.substr(0, i) + magic + S.substr(i + L);
        if (cur < ans)
        {
            ans = cur;
        }
    }
    return ans;
}