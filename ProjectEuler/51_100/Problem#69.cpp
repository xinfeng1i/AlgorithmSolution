#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

int gcd(int a, int b)
{
    if (a >= b && a % b == 0)
    {
        return b;
    }
    if (b >= a && b % a == 0)
    {
        return a;
    }
    assert(a >= 0 && b >= 0);
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int totient(int n)
{
    int cnt = 1;
    for (int i = 2; i < n; ++i)
    {
        if (gcd(i, n) == 1)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    const int MAX_N = 1000000;
    double max_ratio = 0;
    int max_ratio_n = 0;
    for (int n = 2; n <= MAX_N; ++n)
    {
        double tmp = static_cast<double>(n) / totient(n);
        if (tmp > max_ratio)
        {
            max_ratio = tmp;
            max_ratio_n = n;
        }
    }
    cout << "n is " << max_ratio_n << " , max ratio is:" << max_ratio << endl;
    return 0;
}
