#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const long long remainer = 10000000000LL;

/* calculate last ten digits of power (n, n)
 * i.e. n^n % remainer
 */
long long lastTenDigitsOf(long long n)
{
    long long result = 1;
    for (long long i = 1; i <= n; ++i)
    {
        result = (result * n) % remainer;
    }

    return result;
}

int main()
{
    const long long n = 1000LL;
    long long sum = 0LL;
    for (long long i = 1; i <= n; ++i)
    {
        sum = (sum + lastTenDigitsOf(i)) % remainer;
    }
    cout << sum % remainer << endl;
    return 0;
}
