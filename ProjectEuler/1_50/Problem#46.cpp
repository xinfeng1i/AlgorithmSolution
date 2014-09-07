#include <iostream>
#include <string>
#include <set>
#include <cassert>
#include <ctime>
#include <cmath>

using namespace std;

bool isPrime(long n)
{
    if (n <= 1)
    {
        return false;
    }
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


bool isConjectureNumber(long n)
{
    assert(n % 2 == 1);
    for (long i = 3; i < n; i +=2)
    {
        if (isPrime(i))
        {
            long j = (n - i) / 2;
            long mid = (long)sqrt(static_cast<double>(j));
            if (mid * mid == j)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    clock_t time_begin = clock();

    for (long i = 9; ; i +=2)
    {
        if (isPrime(i))
        {
            continue;
        }
        if (!isConjectureNumber(i))
        {
            cout << "Minimum Non-Conjecture Number: " << i << endl;
            break;
        }
    }

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << 1000 * time_cost << " ms" << endl;
    return 0;
}
