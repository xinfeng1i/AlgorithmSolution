//
//  Leetcode1505_swap k 次.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/8/2.
//

#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;




/*
 * 贪心算法：每次将当前位置的数字，用右侧距离它小于等于k的最小数字进行相邻交换即可
 *
 * Time: O（n^2)
 * Space: O(1)
 */
void swapN(string& num, int left, int right, int k) {
    if (left >= right) return;
    if (k == 0) return;

    char curMin = num[left];
    int idx = left;
    for (int i = left + 1; i <= right; ++i) {
        int dist = i - left;
        if (dist <= k && num[i] < curMin) {
            curMin = num[i];
            idx = i;
        }
    }

    int cnt = 0;
    if (idx != left) {
        for (int j = idx; j >= left + 1; --j) {
            swap(num[j], num[j - 1]);
            cnt++;
        }
    }

    swapN(num, left + 1, right, k - cnt);
}


string minInteger(string num, int k) {
    string a = num;

    int n = (int)a.size();
    // 特殊判例，用于解决 TLE 问题
    if (k > n * n) k = n * n;

    swapN(a, 0, n - 1, k);
    return a;
}


int main() {
    string num = "9438957234785635408";
    int k = 23;

    string result = minInteger(num, k);
    cout << result << endl;

    return 0;
}
