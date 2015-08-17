#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 1010;
char s1[MAX_N];
char s2[MAX_N];
int cnt[256];

int main()
{
    //freopen("in.txt", "r", stdin);
    memset(s1, '\0', MAX_N);
    memset(s2, '\0', MAX_N);
    memset(cnt, 0, sizeof(int)* 256);

    scanf("%s", s1);
    scanf("%s", s2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    for (int i = 0; i < n1; ++i)
    {
        int ch = s1[i];
        cnt[ch]++;
    }

    for (int i = 0; i < n2; ++i)
    {
        int ch = s2[i];
        cnt[ch]--;
    }

    bool ok = true;
    for (int i = 0; i < 256; ++i)
    {
        if (cnt[i] < 0) ok = false;
    }

    if (ok)
    {
        int sum = 0;
        for (int i = 0; i < 256; ++i) sum += cnt[i];
        printf("Yes %d\n", sum);
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < 256; ++i)
        {
            if (cnt[i] < 0) sum += cnt[i];
        }
        printf("No %d\n", -sum);
    }
    return 0;
}