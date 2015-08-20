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

int main()
{
    //freopen("in.txt", "r", stdin);
    double sum = 0.0;
    double money = 0.0;
    for (int i = 0; i < 12; ++i)
    {
        scanf("%lf", &money);
        sum += money;
    }
    sum = sum / 12.0;
    sum = round(sum * 100.0) / 100.0;
    printf("$%.2lf", sum);
    return 0;
}