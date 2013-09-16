#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdio>
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
    long N = 0;
    cin >> N;
    long copyN(N);

    // special case
    if (N == 1)
    {
        cout << 1 << "=" << 1 << endl;
        return 0;
    }

    map<long, long> expression;
    for (long i = 2; i <= N; ++i)
    {
        if (isPrime(i) && N % i == 0)
        {
            int cnt = 0;
            do{
                N /= i;
                cnt++;
            }while(N % i == 0);

            expression.insert(pair<long, long> (i, cnt));
        }
    }

    bool flag = false;
    cout << copyN << "=";
    for (auto it = expression.begin(); it != expression.end(); ++it)
    {
        if (flag)
        {
            cout << "*";
        }
        else
        {
            flag = true;
        }

        if (it->second == 1)
        {
            cout << it->first;
        }
        else
        {
            cout << it->first << "^" << it->second;
        }
    }
    cout << endl;
    return 0;
}

// consider time cost
