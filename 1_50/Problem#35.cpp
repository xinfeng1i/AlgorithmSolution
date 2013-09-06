#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isPrime(long n)
{
    long  mid = sqrt(static_cast<double>(n));
    long  i = 2;
    for (i = 2; i <=mid; i++)
    {
        if (n % i == 0)
        {
            break;
        }
    }
    if (i > mid)
    {
        return true;
    }
    else
    {
        return false;
    }
}

long rotation(long  n, long step)
{
    string str_n = to_string(n);
    int length = str_n.size();

    string str_beg = str_n.substr(step, length-step);
    string str_end = str_n.substr(0, step);
    string result = str_beg + str_end;
    return atol(result.c_str());
    
}

bool isCircularPrime(long n)
{
    if (!isPrime(n))
    {
        return false;
    }
    int length = to_string(n).size();
    for (int step = 1; step <= length - 1; step++)
    {
        if (!isPrime(rotation(n, step)))
        {
            return false;
        }
    }

    return true;

}

long numCircularPrimeUnder(long bound)
{
    long cnt = 0;
    for (long i = 2; i < bound; i++)
    {
        if (isCircularPrime(i))
        {
            cout << " Circular Primes Under " << bound << " : "<< i << endl;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    clock_t time_begin = clock();
    cout << numCircularPrimeUnder(1000000) << endl;
    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << 1000 * time_cost << " ms" << endl;
    return 0;
}
