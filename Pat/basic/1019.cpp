#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int increaseOrder(int n)
{
    vector<int> v(4, 0);
    v[0] = n / 1000;
    v[1] = (n % 1000) / 100;
    v[2] = (n % 100) / 10;
    v[3] = n % 10;
    sort(v.begin(), v.end(), less<int>());

    int ans = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
    return ans;
}


int decreaseOrder(int n)
{
    vector<int> v(4, 0);
    v[0] = n / 1000;
    v[1] = (n % 1000) / 100;
    v[2] = (n % 100) / 10;
    v[3] = n % 10;
    sort(v.begin(), v.end(), greater<int>());

    int ans = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n / 1000 == (n % 1000) / 100 && (n % 1000) / 100 == (n % 100) / 10 &&
        (n % 100) / 10 == n % 10)
    {
        printf("%04d - %04d = 0000\n", n, n);
        return 0;
    }

    if (n == 6174)
    {
        printf("7641 - 1467 = 6174\n");
        return 0;
    }

    while (n != 6174)
    {
        int a = decreaseOrder(n);
        int b = increaseOrder(n);
        int c = a - b;
        printf("%04d - %04d = %04d\n", a, b, c);

        n = c;
    }

    return 0;
}
