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
    long long n = 0;
    cin >> n;
    if (n == 1)
    {
        cout << "1=1" << endl;
        return 0;
    }

    cout << n << "=";
    bool flag = false;
    for (long long i = 2; i <= n; ++i)
    {
        if (!isPrime(i) || n % i != 0)
        {
            continue;
        }

        long long cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }
        
        if (flag)
        {
            cout << "*";
        }
        else
        {
            flag = true;
        }
        
        if (cnt == 1)
        {
            cout << i;
        }
        else
        {
            cout << i << "^" << cnt;
        }

    }
    cout << endl;
    return 0;
}
