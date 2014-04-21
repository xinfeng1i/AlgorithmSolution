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


// AC code: 239pts
// implementations
class SilverbachConjecture
{
public:

    bool isPrime(int n)
    {
        int mid = (int)sqrt(double(n));
        for (int i = 2; i <= mid; ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    vector <int> solve(int n)
    {
        vector<int> v(2, 0);
        for (int a = 2; a <= n; ++a)
        {
            int b = n - a;
            if (a > 1 && b > 1 && !isPrime(a) && !isPrime(b))
            {
                v[0] = a;
                v[1] = b;
                break;
            }
        }

        return v;
    }
};