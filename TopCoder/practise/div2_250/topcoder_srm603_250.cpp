#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 193 pt
string encode(string s)
{
    string t;
    while (s.size() > 0)
    {
        int n = s.size();
        if (n % 2 == 1)
        {
            t.push_back(s[(n - 1)/2]);
            s = s.substr(0, (n - 1) / 2) + s.substr((n + 1) / 2);
        }
        else
        {
            if (s[n / 2 - 1] <= s[n / 2])
            {
                t.push_back(s[n / 2 - 1]);
                s = s.substr(0, n / 2 - 1) + s.substr(n / 2);
            }
            else
            {
                t.push_back(s[n / 2]);
                s = s.substr(0, n / 2) + s.substr(n / 2 + 1);
            }
        }
    }
    return t;
}