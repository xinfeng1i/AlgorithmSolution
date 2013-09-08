#include <iostream>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

/*
 * given an n-digit number n, return whether it can be expressed as some other
 * number's n-th power
 *
 * For example:
 * Input:   16807
 *          since 16807 = 7^5, 16807 is a 5-digit number, can be expressed as
 *          the 5-th power of 7
 * Output:  true
 */
bool isnthPower(long long n)
{
    string str_n = to_string(n);
    int ndigits = str_n.size();
    for (int i = 1; i < 10; ++i)
    {
        if (pow(i, ndigits) == n)
        {
            cout << "pow (" << i << ", " << ndigits << ")" << "=" << n << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    long long cnt = 0;
    for (long long i = 1; i <= numeric_limits<long long>::max(); ++i)
    {
        if (isnthPower(i))
        {
            cnt++;
        }
    }
    cout << "result: " << cnt << endl;
    return 0;
}
