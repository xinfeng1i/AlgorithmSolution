#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n)
{
    long long i;
    long long mid = n / 2;
    for  (i = 2; i <= mid; i++)
    {
        if (n % i == 0)
        {
            break;
        }
    }

    if (i > mid)
        return true;
    else
        return false;
}


int main()
{
    long long x = 600851475143;

    while (!isPrime(x))
    {
        for (long long i = 2; i <= x / 2; i++)
        {
            if (x % i == 0)
            {
                x /= i;
            }
        }
    }
    cout << "Largest Prime Factor is :" << x << endl;
    return 0;
}
