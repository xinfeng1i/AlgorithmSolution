#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 110;
int hashTable[MAX_N];

int main()
{
    //freopen("in.txt", "r", stdin);
    for (int i = 0; i < MAX_N; ++i) hashTable[i] = 0;
    int n = 0; int k = 0;
    int score = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &score);
        hashTable[score]++;
    }

    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &score);
        if (i == 0) printf("%d", hashTable[score]);
        else printf(" %d", hashTable[score]);
    }

    return 0;

}