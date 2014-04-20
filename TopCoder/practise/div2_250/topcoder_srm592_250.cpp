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


int getNumber(vector <int> pages, int number)
{
    sort(pages.begin(), pages.end());
    int cnt = 0;
    for (int i = 0; i < number - 1; ++i)
    {
        cnt += pages[i];
    }

    return cnt + pages[number];
}