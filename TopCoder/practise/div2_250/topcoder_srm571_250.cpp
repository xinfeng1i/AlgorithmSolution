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

// AC: 246pts
class FoxAndGame
{
public:
    int countStars(vector <string> result)
    {
        int cnt = 0;
        for (size_t i = 0; i < result.size(); ++i)
        {
            if (result[i] == "---") cnt += 0;
            else if (result[i] == "o--") cnt += 1;
            else if (result[i] == "oo-") cnt += 2;
            else if (result[i] == "ooo") cnt += 3;
        }

        return cnt;
    }
};