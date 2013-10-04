#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <set>
using namespace std;

#define EPS 1e-6

int main()
{
   int n = 0;
   cin >> n;
   double tmp;
   vector<double> floats;
   for (int i = 0; i < 2 * n; ++i)
   {
        cin >> tmp;
        if ( abs(tmp - static_cast<long>(tmp)) > EPS )
        {
            floats.push_back(tmp - static_cast<long>(tmp));
        }
   }

   sort(floats.begin(), floats.end(),less<double>());

   double ans = 0;
   long sz = floats.size();
   if (sz % 2 == 0)
   {
        for (long i = 0; i < sz / 2; ++i)
        {
            ans += -floats[i] + (1 - floats[sz-1-i]);
        }
   }
   else
   {
        for (long i = 0; i < sz / 2; ++i)
        {
            ans += -floats[i] + (1 - floats[sz-1-i]);
        }
        if (ans > 0)
        {
            ans = ans - floats[sz/2];
        }
        else if (ans < 0)
        {
            ans = ans + (1 - floats[sz/2]);
        }
        else if (ans == 0)
        {
            
            ans = min(abs(floats[sz/2]), abs(1 - floats[sz/2]));
        }

   }
   
   //cout << abs(ans) << endl;
   printf ("%0.3f\n", abs(ans));
   return 0;
}
