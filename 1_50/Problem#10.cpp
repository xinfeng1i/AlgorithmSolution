#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

bool isPrime(long long n)
{
    long long mid = static_cast<long long>(sqrt(n));
    long long i = 2;
    for (i = 2; i <= mid; i++)
    {
        if (n % i == 0)
            break;
    }

    if (i > mid)
        return true;
    else
        return false;
}

int main()
{
    clock_t time_begin = clock();

    const long long MAX_LIMIT = 2000000;
    long long n = 0;
    long long sum = 2;
    for (n = 3; n <= MAX_LIMIT; n++)
    {
        if (n % 2 != 0 && isPrime(n))
        {
            sum += n;
        }
    }
    cout << "sum of primes under " << MAX_LIMIT << " :" << sum << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin)/CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << " s" << endl;
    return 0;
}
