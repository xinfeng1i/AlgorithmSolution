#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

bool isPrime(long n)
{
    if (n == 1)
    {
        return false;
    }

    long mid = (long)sqrt(static_cast<double>(n));
    for (long i = 2; i <= mid; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isTruncatablePrime(long n)
{
    if (!isPrime(n))
    {
        return false;
    }
    string left = to_string((long long)(n));
    string right(left);
    long length = left.size();
    for (int i = 1; i <= length - 1; i++)
    {
        left.erase(0, 1);
        if (!isPrime(stol(left)))
        {
            return false;
        }
    }
    
    for (int i = 1; i <= length - 1; i++)
    {
        right.pop_back();
        if (!isPrime(stol(right)))
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
#if 0
    long cnt = 0;
    for (long n = 11; n < 1000000; n++)
    {
        if (isTruncatablePrime(n))
        {
            cout << "*** " << n << endl;
            cnt++;
        }
    }
#endif

    clock_t time_begin = clock();

    long cnt = 0;
    long n = 10;
    long sum = 0;
    while (cnt < 11)
    {
        if (isTruncatablePrime(n))
        {
            cout << "Truncatable Prime: " << n << endl;
            sum += n;
            cnt++;
        }
        n++;
    }
    cout << cnt << " Truncatable Primes, Total Sum: " << sum << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << 1000 * time_cost << " ms" << endl;

    return 0;
}
