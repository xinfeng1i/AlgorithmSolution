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

// AC: 218pts
class CityMap
{
public:
    
    string getLegend(vector <string> cityMap, vector <int> POIs)
    {
        vector<int> cnt(30, 0);
        int n = cityMap.size();
        int m = cityMap[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                char ch = cityMap[i][j];
                if (ch != '.')
                {
                    cnt[ch - 'A']++; 
                }
            }
        }

        string ans;
        for (int i = 0; i < POIs.size(); ++i)
        {
            int curCnt = POIs[i];
            for (int k = 0; k < 30; ++k)
            {
                if (cnt[k] == curCnt)
                {
                    ans.push_back('A' + k);
                }
            }
        }

        return ans;
    }

};