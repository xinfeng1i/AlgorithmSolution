#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long n)
{
    if (n <= 1)
        return false;

    long mid = sqrt(static_cast<double>(n));
    for (long i = 2; i <= mid; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    
    return true;
}
