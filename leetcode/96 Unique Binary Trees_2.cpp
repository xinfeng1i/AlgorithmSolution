#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
using namespace std;


// 动态规划：
// 定义L(k)表示长度为1...k的BST所具有的形态数
// 则当选择以i为根节点时, 其左子树的形态数为L(i-1)，而右子树的形态数为L(n-i)
// 总的形态数量为L(i-1) * L(k-i)
// L(k) = sum_{i=1}^{k} L(i-1) * L(k-i)
int numTrees(int n) {
    vector<int> L(n+1, 0);
    L[0] = 1;
    L[1] = 1;
    for (int k = 1; k <= n; ++k) {
        int sum = 0;
        for (int i = 1; i <= k; ++i) {
            sum += L[i-1] * L[k-i];
        }
        L[k] = sum;
    }
    return L[n];     
}