#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(long long n)
{
    if (n <= 1)
    {
        return false;
    }
    
    long long mid = sqrt(static_cast<double>(n));
    for (long long i = 2; i <= mid; ++i)
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
    const int MAX_SIZE = 10000;
    vector<long long> primes;
    for (long long i = 2; primes.size() < MAX_SIZE; ++i)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }
    
    int m = 0, n = 0;
    cin >> m >> n;
    vector<long long> v(primes.begin()+m-1, primes.begin()+n);
    int sz = v.size();
    //int remainder = sz % 10;
    bool flag = false; // control whether print space character
                       // indicate whether there is a number before
    for (int i = 0; i < sz; ++i)
    {
        if (flag)
        {
            cout << " ";
        }
        else
        {
            flag = true;
        }
        cout << v[i];
        if ((i + 1) % 10 == 0 || (i + 1) == sz)
        {
            cout << endl;
            flag = false;
        }
    }

    return 0;
}
