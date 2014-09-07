#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

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
    cout << primes[primes.size()-2] << endl;
    cout << primes[primes.size()-3] << endl;
    cout << primes[primes.size()-4] << endl;
    cout << primes[primes.size()-5] << endl;

    /*
    long max_prime_con_sum_length = 0;
    for (long i = 0; i < primes.size(); i++)
    {
        long prime = primes[i];
        long prime_con_sum_length = 0;

        vector<long>::iterator it_beg, it_end;
        for(it_end == primes.begin(); it_end != primes.end(); it_end++)
        {
            long tmp = accumulate(primes.begin(), it_end, 0) 
            if (tmp > prime)
            {
                prime_con_sum_length = 0; 
                break;
            }
            else if (tmp == prime)
            {
                prime_con_sum_length = it_end - primes.begin();
                break;
            }
        }
    }
    */

    /*
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
                    break;
                }
            }

        }

        if (max_cnt > max_max_cnt)
        {
            max_max_cnt = max_cnt;
        }
    }
    cout << "max_max_cnt: " << max_max_cnt << endl;
    */
    cout << "====================" << endl;
    long up_bd = 546;
    for (long up_bd = 550; up_bd >= 500; up_bd--)
    {
        cout << "up_bd: " << up_bd << " ::: " << endl;
        long tmp =  accumulate(primes.begin()+3, primes.begin() + up_bd, 0);
        if (isPrime(tmp))
        {
            cout << tmp <<endl;
        }
    }
    return 0;
}
