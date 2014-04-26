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
#include <cassert>
using namespace std;

// AC: 228pts
class DeerInZooDivTwo
{
public:
    vector <int> getminmax(int N, int K)
    {
        vector<int> ans(2);
        assert(K <= 2 * N);
        if (K < N)
        {
            ans[0] = N - K;
            ans[1] = (K % 2 == 0 ? N - K / 2 : N - (K / 2 + 1) );
        }
        else
        {
            ans[0] = 0;
            ans[1] = (K % 2 == 0 ? N - K / 2 : N - (K / 2 + 1) );
        
        }

        return ans;
    }
};