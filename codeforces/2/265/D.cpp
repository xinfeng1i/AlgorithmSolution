/*
 * 问题描述：
 * 给定一个cube，八个顶点放在xyz坐标系中，并且保证八个顶点的坐标值为
 * 整数，现在对每一个顶点的坐标进行随机的permutation后，问是否能够反过来
 * 确定之前的cube的顶点坐标，如果能则print任何一个可行解
 *
 * 基本思路：
 * 对每个顶点坐标进行全部permutation，这样总共有中configuration，对于
 * 每一种configuration，计算任意两个点之间的距离，每一个点到其他7个点
 * 的距离平方应该满足有3个为I，3个为2*I，1个为3*I；如果所有顶点都能满足
 * 该条件，则该种configuration可以是cube，反之，如果都不满足，则不是
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long llong;

llong a[8][3];
llong b[7];

// 计算顶点i，j之间的距离平方
llong dist(int i, int j)
{
    llong dx = a[i][0] - a[j][0];
    llong dy = a[i][1] - a[j][1];
    llong dz = a[i][2] - a[j][2];
    return dx * dx + dy * dy + dz * dz;
}

// 对于一种给定的configuration，计算8个点是否满足距离
// 条件，如果任意一个顶点到其他顶点的距离不满足条件，
// 则false， 否则true
bool check()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (j < i) b[j] = dist(i,j);
            else if (j > i) b[j-1] = dist(i, j);
            else continue;
        }
        sort(b, b + 7);
        llong t1 = b[0];
        llong t2 = 2 * b[0];
        llong t3 = 3 * b[0];
        if (t1 == 0 || b[0] != t1 || b[1] != t1 || b[2] != t1 ||
            b[3] != t2 || b[4] != t2 || b[5] != t2 || b[6] != t3)
        {
            return false;
        }
        
    }
    return true;
}

// 从当前第i个节点开始能够找到合适的configuration
bool isOK(int i)
{
    // 如果所有节点都已经permutation好，返回该格局的距离结果
    if (i == 8)
    {
        return check();
    }

    sort(a[i], a[i]+3);

    // 对于当前节点的每一个permutation
    do
    {
        // 如果下一个节点开始可以找到这样的permutation，返回true
        if (isOK(i+1)) return true;

    }while(next_permutation(a[i], a[i]+3));

    return false;
}

int main()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            scanf("%I64d", &a[i][j]);
        }
    }
    
    if (isOK(0))
    {
        printf("YES\n");
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (j == 0) printf("%I64d", a[i][j]);
                else printf(" %I64d", a[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
