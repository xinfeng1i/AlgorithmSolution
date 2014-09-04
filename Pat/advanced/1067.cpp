#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

// 计算v[0]!= 0时的循环长度，数值上等于交换次数
int cntSwap(vector<int>& v)
{
    int ans = 0;
    while (v[0] != 0)
    {
        int x = v[0];
        swap(v[0], v[x]);
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) // 对于每一个数字，判断是否归位
    {
        if (v[i] != i)          // 如果该数字尚未归为
        {
            if (v[0] == 0)      // 进一步判断v[0]是否等于0，如果等于0
                                // 需要首先和v[0] swap 一次
            {
                swap(v[0], v[i]);
                cnt++;
            }

            cnt += cntSwap(v);  // 然后加上循环的长度
        }
    }

    printf("%d\n", cnt);
    return 0;
}

/*
 * 分析
 * 1. 如果v[0] != 0, 则v[0] = x, v[x] = y, v[y] = z, ..., v[z] = 0，
 *    swap的次数等于该循环链的长度
 * 2. 如果v[0] == 0, 则后面对于v[i]!=i的数字来说，swap的过程中不会有0的参与，
 *    为了保证swap(0, *)，需要首先swap(v[0], v[i])一次，然后转换为1的情况
 * 参考：
 * tech-wonderland.net/blog/pat-1067-sort-with-swap-zero.html
 */
