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


// Ac code: 243pts;
// brute force
string check(int n)
{
    int mid = (int)sqrt(double(n));

    for (int a = 1; a <= mid; ++a)
    {
        for (int b = 1; b <= mid; ++b)
        {
            if (a < b && a * b * b == n)
            {
                return "Yes";
            }
        }
    }

    return "No";
}