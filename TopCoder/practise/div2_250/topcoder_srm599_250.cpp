#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 231 pt.
int maxMikan(vector <int> mikan, int weight)
{
    const int bound = 5000;
    int n = mikan.size();
    sort(mikan.begin(), mikan.end());
    int cnt = 0;
    for (int i = 0; i < n && mikan[i] + weight <= bound; ++i)
    {
        weight += mikan[i];
        cnt++;
    }

    return cnt;
}