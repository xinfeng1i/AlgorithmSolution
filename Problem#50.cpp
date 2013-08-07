#include <iostream>
#include <string>
#include <vector>
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

int main()
{
    const long UP_BOUND = 1000000;
    vector<long> primes;    // store all the primes under up_bound
    primes.reserve(1000);

    primes.push_back(2);
    for (long i = 3; i <= UP_BOUND; i += 2)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    cout << "size: " << primes.size() << endl;
    cout << primes[0] << endl;
    cout << primes[primes.size()-1] << endl;

    long max_max_cnt = 0;
    for (long i = 0; i < primes.size(); i++)
    {
        long max_cnt = 0;
        for (long start = 0; start < i; start++)
        {
            long sum = primes[start];
            long cnt = 1;
            long next = start + 1;
            while (sum < primes[i])
            {
                sum += primes[next];
                cnt++;
                next++;
            }
            if (sum == primes[i])
            {
                if (cnt > max_cnt)
                {
                    max_cnt = cnt;
                }
            }

        }

        if (max_cnt > max_max_cnt)
        {
            max_max_cnt = max_cnt;
        }
    }
    cout << "max_max_cnt: " << max_max_cnt << endl;
    return 0;
}
