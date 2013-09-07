#include <iostream>
#include <string>
using namespace std;

/*
 * compute C(n,k)
 * Even though we use long long the MAX_LONG_LONG is 
 * about 922*10^16, need to pay attention to overflow
 */
long long countCombinations(long long n, long long k)
{
    // C(n, k) == C(n, n-k)
    if (n - k < k)
    {
        k = n - k;
    }

    // calculate dividend
    long long a = 1;
    for  (long long i = 0; i < k; ++i)
    {
        a *= (n - i);
    }
    // calculate divisor
    long long b = 1;
    for (long long j = 1; j <= k; ++j)
    {
        b *= j;
    }

    return a / b;
}


int main()
{
    const long long UP_BOUND = 1000000;
    const long long MAX_N = 100;
    long long cnt = 0;
    for (long long n = 1; n <= 100; ++n)
    {
        for (long long k = 0; k <= n; ++k)
        {
            if (countCombinations(n, k) > UP_BOUND)
            {
                // if C(n, k) > 10^6, then the first C(n, 0), C(n, 1)
                // ...C(n, k-1) must <= 10^6, according to the symmetry
                // the last k must also <= 10^6. total number is (n+1)
                // so the >10^6 is (n+1-2*k)
                cnt += (n + 1 - 2 * k);
                break;
            }
        }
    }

    cout << "result: " << cnt << endl;
    return 0;
}
