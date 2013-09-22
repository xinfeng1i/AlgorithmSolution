#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long n)
{
    if (n <= 1) return false;

    long long mid = sqrt(static_cast<double>(n));
    for (long long i = 2; i <= mid; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

/*****************************************************************************
 * Reverse number in radix-d number system,
 * recover the decimal value as return value
 *
 * Input
 *  n - the number to be reversed
 *  d - radix
 *
 * Output
 *  return the reverse number in decimal number system
 *
 * Example
 *   23 = (10111)   // binary system
 *   (11101) = 29   // reverse in the binary system,calculate the decimal value
 *   return 29
 *
 *****************************************************************************/
long long reverseNumber(long long n, int d)
{
    stack<int> s;
    while (n != 0)
    {
        s.push(n % d);
        n /= d;
    }

    long long ans = 0;
    long long weight = 1;
    while (!s.empty())
    {
        ans += s.top() * weight;
        s.pop();
        weight *= d;
    }

    return ans;
}

int main()
{
    long long n;
    int d;
    vector<bool> v;
    while (true)
    {
        cin >> n;
        if (n < 0)
        {
            break;
        }
        cin >> d;

        if (isPrime(n) && isPrime(reverseNumber(n, d)))
        {
            v.push_back(true);
        }
        else
        {
            v.push_back(false);
        }
    }

    for (auto a:v)
    {
        if (a)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
