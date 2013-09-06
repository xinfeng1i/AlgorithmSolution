#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPandigital(long n)
{
    vector<int> cnt(10, 0);
    string str_n = to_string(n);
    for (size_t i = 0; i < str_n.size(); ++i)
    {
        cnt[str_n[i] - '0']++;
    }

    if (cnt[0] != 0)
    {
        return false;
    }

    for (int i = 1; i < 10; i++)
    {
        if (cnt[i] != 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    long max_pandigital_number = 0;
    cout << ">= 1000 pandigital:" << endl;
    for (int i = 1000; i <= 9999; ++i)
    {
        long num = i * 100000 + i * 2;
        if (isPandigital(num))
        {
            cout << num << endl;
            if (num > max_pandigital_number)
            {
                max_pandigital_number = num;
            }
        }
    }

    cout << ">= 100 pandigital: " << endl;
    for (int n = 100; n <= 999; ++n)
    {
        long num = n * 1000000 + n * 2 * 1000 + n * 3;
        if (isPandigital(num))
        {
            cout << num << endl;
            if (num > max_pandigital_number)
            {
                max_pandigital_number = num;
            }
        }
    }

    cout << ">= 10 pandigital: " << endl;
    for (int n = 10; n <= 99; ++n)
    {
        long num = n*10000000 + 2*n*100000 + 3*n*1000 + 4*n;
        if (isPandigital(num))
        {
            cout << num << endl;
            if (num > max_pandigital_number)
            {
                max_pandigital_number = num;
            }
        }
    }

    cout << ">=1 pandigital max: " << endl;
    cout << 918273645 << endl;

    cout << "max pandigital number: " << max_pandigital_number << endl;
    return 0;
}
