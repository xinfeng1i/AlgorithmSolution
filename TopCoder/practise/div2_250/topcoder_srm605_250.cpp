#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 246pt
int getNumber(string S)
{
    int n = S.size();
    string tmp;
    set<string> ans;
    for (int i = 0; i < n; ++i)
    {
        tmp = S.substr(0, i) + S.substr(i + 1);
        ans.insert(tmp);
    }

    return ans.size();
}