#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long llong;
const llong MOD = 1000000007;
const int MAX_N = 100010;
char s[MAX_N] = { '0' };
llong cntP[MAX_N]; // 如果放入main函数内作为局部变量会造成 stackoverflow 溢出
llong cntT[MAX_N];

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int n = strlen(s);
    llong ans = 0;

    for (int i = 0; i < MAX_N; ++i) cntP[i] = 0;
    for (int i = 0; i < MAX_N; ++i) cntT[i] = 0;

    // 基本思想：对于每一个 A 字符，假定知道 A 前面有 nP 个P字符，A 后面有
    // nT 个 T字符，则以该A字符为中心的PAT字符共有 nP * nT 个。
    // 计算每个A字符前面的P字符可以对数组做一次扫描，如果碰到P则比前一位+1，否则
    // 则等于前一位的P个数即可。这样总的时间复杂度可以降到 O(n)
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'P')
        {
            if (i - 1 >= 0) cntP[i] = cntP[i - 1] + 1;
            else cntP[i]++;
        }
        else
        {
            if (i - 1 >= 0) cntP[i] = cntP[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == 'T')
        {
            if (i + 1 < n) cntT[i] = cntT[i + 1] + 1;
            else cntT[i]++;
        }
        else
        {
            if (i + 1 < n) cntT[i] = cntT[i + 1];
        }

    }

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'A')
        {
            ans = (ans % MOD + (cntP[i] * cntT[i]) % MOD) % MOD;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}