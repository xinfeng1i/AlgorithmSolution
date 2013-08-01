#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <cstdlib>

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

long rotation(long  n)
{
    string str_n = to_string(n);
    int length = str_n.size();
    
    char tmp = str_n[0];
    for (int i = 1; i < length; i++)
    {
        str_n[i-1] = str_n[i];
    }
    str_n[length - 1] = tmp;
    long result = atol(str_n.c_str());
    return result;
}

bool isCircularPrime(long n)
{
    string str_n = to_string(n);
    int length = str_n.size();
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if (!isPrime(n))
        {
            break;
        }
        n = rotation(n);
    }

    if (i < length)
    {
        return false;
    }
    else
    {
        return true;
    }
}

long numCircularPrimeUnder(long bound)
{
    long cnt = 0;
    for (long i = 2; i < bound; i++)
    {
        if (isCircularPrime(i))
        {
            cout << " == " << i << endl;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    cout << numCircularPrimeUnder(1000000) << endl;
    return 0;
}
