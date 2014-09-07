#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

bool isPrime(long long n)
{
    long long mid = static_cast<long long>(sqrt(n));
    long long i = 2;
    for (i = 2; i <= mid; i++)
    {
        if (n % i == 0)
        {
            break;
        }
    }

    if (i <= mid)
    {
        return false;
    }
    else
    {
        return true;
    }
}


long long func(long long a, long long b, long long n)
{
    return n * n + a * n + b;
}

int main()
{
    clock_t time_begin = clock();

    const int UP_LIMIT = 1000;
    long long max_number_primes = 0;
    long long max_a = 0;
    long long max_b = 0;
    for (int a = -UP_LIMIT; a <= UP_LIMIT; a++)
    {
        for (int b = -UP_LIMIT; b <= UP_LIMIT; b++)
        {
            // b must be prime, if not, goto next b
            if (!isPrime(abs(b)))
            {
                continue;
            }

            // count starting n = 0 to which n led to f(n) is not prime
            long long n = 0;
            while (isPrime(abs(func(a, b, n))))
            {
                n++;
            }
            // update max_n
            if (n > max_number_primes)
            {
                max_number_primes = n;
                max_a = a;
                max_b = b;
            }
        }
    }
    
    cout << "Max Number of Primes is : " << max_number_primes << endl;
    cout << "a is : " << max_a << endl;
    cout << "b is : " << max_b << endl;
    cout << "a * b is : " << max_a * max_b << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << " s" << endl;
    return 0;
}
