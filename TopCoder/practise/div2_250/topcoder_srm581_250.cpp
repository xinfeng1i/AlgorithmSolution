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


// AC code: 236pts
// Brute force
int minimumTurns(string cardFront)
{
    int n = cardFront.size();
    string firstType(n, 'B');
    for (int i = 1; i < n; i += 2) firstType[i] = 'W';

    string secondType(n, 'W');
    for (int i = 1; i < n; i += 2) secondType[i] = 'B';

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cardFront[i] != firstType[i]) cnt1++;
        if (cardFront[i] != secondType[i]) cnt2++;
    }

    return min(cnt1, cnt2);
}