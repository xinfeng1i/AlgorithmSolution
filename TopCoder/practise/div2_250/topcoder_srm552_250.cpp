#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 202pts
// brute force
class FoxAndFlowerShopDivTwo
{
public:
    int theMaxFlowers(vector <string> flowers, int r, int c)
    {
        int n  = flowers.size();
        int m  = flowers[0].size();
        int a1 = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (flowers[i][j] == 'F') a1++;
            }
        }
        int a2 = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = c+1; j < m; ++j)
            {
                if (flowers[i][j] == 'F') a2++;
            }
        }

        int maxa = max(a1, a2);

        int b1 = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (flowers[i][j] == 'F') b1++;
            }
        }
        int b2 = 0;
        for (int i = r+1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (flowers[i][j] == 'F') b2++;
            }
        }

        int maxb = max(b1, b2);

        return max(maxa, maxb);
    }

};
