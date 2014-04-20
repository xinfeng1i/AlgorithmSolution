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

// AC: 239pt
int possibleHandles(string familyName, string givenName)
{
    int n1 = familyName.size();
    int n2 = givenName.size();

    set<string> handles;
    for (int i = 1; i <= n1; ++i)
    {
        for(int j = 1; j <= n2; ++j)
        {
            handles.insert(familyName.substr(0,i) + givenName.substr(0, j));
        }
    }

    return handles.size();
}