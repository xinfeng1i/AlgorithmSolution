#include <iostream>
#include <string>
#include <set>
#include <ctime>
#include <cmath>

using namespace std;

bool isPrime(long n)
{
    if (n <= 1)
        return false;

    long mid = (long)sqrt(static_cast<double>(n));
    for (long i = 2; i <= mid; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

/*******************************************************************
 * Return the number of distinct prime factors for given parameter n.
 */
long numDistinctPrimeFactors(long n)
{
    set<long> factors;
    long mid = (long)sqrt(static_cast<double>(n));
    for (long i = 2; i <= mid; i++)
    {
        if (!isPrime(i))
            continue;

        while (n % i == 0)
        {
            factors.insert(i);
            if (isPrime(n/i))
            {
                factors.insert(n/i);
            }
            n /= i;
        }
    }
    return factors.size();
}

int main()
{
    clock_t time_begin = clock();

    // The minimum number that can be expressed by four distinct prime factors
    // is 2 * 3 * 5 * 7 = 210, so we start by 210
    for (long a = 210; a < 1000000; a++)
    {
        if (numDistinctPrimeFactors(a) == 4 && numDistinctPrimeFactors(a+1) == 4
                && numDistinctPrimeFactors(a+2) ==4 && numDistinctPrimeFactors(a+3) == 4)
        {
            cout << "a = " << a << endl;
            cout << "b = " << a+1 << endl;
            cout << "c = " << a+2 << endl;
            cout << "d = " << a+3 << endl;
            break;
        }
    }

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << 1000 * time_cost << " ms" << endl;
    return 0;
}
