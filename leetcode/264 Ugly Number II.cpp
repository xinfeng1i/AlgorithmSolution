#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int nthUglyNumber(int n) {
    if (n <= 0) return -1;
    vector<int> ugly(1, 1);
    int p2 = 0, p3 = 0; p5 = 0;
    while (ugly.size() < n) {
        int nextUgly = min(min(ugly[p2] * 2, ugly[p3] * 3), ugly[p5] * 5);
        ugly.push_back(nextUgly);
        if (nextUgly == ugly[p2] * 2) p2++;
        if (nextUgly == ugly[p3] * 3) p3++;
        if (nextUgly == ugly[p5] * 5) p5++;
    }
    return ugly[n-1];
}