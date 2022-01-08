#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

/*
 * fake definition
 */
int rand7() {
    return 2;
}


/* 
 * 基本思路： 通过分析发现 r1+r2 符合高斯分布 [2, 14]，在 8 处取得峰值，概率为 1/49x7
 * 因此，通过讲不同的数的进行映射，保证返回的每个数的概率为1/7即可
 */
int rand10() {
    int r1 = rand7();
    int r2 = rand7();
    int sum = r1 + r2;

    if (sum == 8) {
        return 8;
    } else if (sum == 9 || sum == 14) {
        return 9;
    } else if (sum == 10 || sum == 13) {
        return 10;
    } else {
        return r1;
    }
}