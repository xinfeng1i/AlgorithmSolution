#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <cctype>
#include <cstdlib>
using namespace std;


/************************************************************* 
 * This problem is much easier than you thought.
 * No matter how the k bags are chosen, there must be a
 * smallest elem, is we sort the k elems, then the 
 * kth - 1th = min iff we choose the continous k elems.
 *
 * For example:
 * 1, 2, 3, 4, 5, 6;
 * k = 3
 * 
 * then if we choose 2 as the min, the diff is smallest iff
 * we choose 2,3,4, because if we skip some elems, for example
 * 2,4,5 or 2,4,6. the diff will get bigger.
 *
 **************************************************************/
int getNumber(vector <int> bags, int k)
{
    int n = bags.size();
    sort(bags.begin(), bags.end());

    int ans = numeric_limits<int>::max();
    for (int i = 0; i <= n - k; ++i)
    {
        ans = min(ans, bags[i + k - 1] - bags[i]);
    }
    return ans;
}