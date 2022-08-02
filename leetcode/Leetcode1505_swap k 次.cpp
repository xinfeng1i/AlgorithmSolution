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



void swapN(string& num, int left, int right, int k) {
    if (left >= right) return;
    if (k == 0) return;
    
    char pMin = num[left];
    int idx = left;
    for (int i = left + 1; i <= right; ++i) {
        int dist = i - left;
        if (dist <= k && num[i] < num[left]) {
            pMin = num[i];
            idx = i;
        }
    }
    
    int cnt = 0;
    if (idx != left) {
        swap(num[left], num[idx]);
        cnt = idx - left;
    }
    
    swapN(num, left + 1, right, k - cnt);
}


int main() {
    string num = "54321";
    int n = (int) num.size();
    int k = 4;
    
    swapN(num, 0, n - 1, k);
    
    cout << num << endl;
    
    return 0;
}
