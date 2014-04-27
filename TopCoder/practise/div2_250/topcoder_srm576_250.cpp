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

// AC: 151pts
class TheExperimentDiv2
{
public:
    vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd)
    {
        int n = intensity.size();
        int m = leftEnd.size();
        vector<int> flag(n, 0);
        vector<int> ans(m, 0);

        for (int k = 0; k < m; ++k)
        {
            int s = leftEnd[k] + 1;
            int e = leftEnd[k] + L;
            int tmp = 0;
            for (int i = s; i <= e; ++i)
            {
                if (flag[i-1] == 0)
                {
                    tmp += intensity[i-1];
                    flag[i-1] = 1; 
                }
                
            }
            ans[k] = tmp;
        }

        return ans;

    }
};