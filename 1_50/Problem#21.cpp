#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/** 
 * Compute the sum of proper divisors of n
 *
 * Example:
 * Input: n = 220
 * Output: 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55
 */
long long sumProperDivisors(long long n)
{
    if (n <= 0)
    {
        cerr << "Parameter Wrong !" << endl;
        return -1;
    }
    long long result = 1;   // all integers have divisor 1
    for (long long i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            result += i;
        }
    }
    return result;
}

int main()
{
    clock_t time_begin = clock();

    long long UP_LIMIT = 10000;

    long long sum = 0;
    long long a = 0; 
    long long b = 0;
    for (a = 1; a < UP_LIMIT; a++)
    {
        b = sumProperDivisors(a);
        if (sumProperDivisors(b) == a && a != b)
        {
            sum += a;
        }
    }
    cout << "Sum of all the amicable numbers under 10000 is : " << sum 
        << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << " s" << endl;
    return 0;
}
