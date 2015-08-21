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
#include <algorithm>
using namespace std;

bool isUgly(int num)
{
    if (num <= 0) return false;

    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return (num == 1);
}

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        cout << "Ugly:" << isUgly(n) << endl;
    }
    return 0;
}