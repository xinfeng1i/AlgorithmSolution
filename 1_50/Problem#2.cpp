#include <iostream>
#include <string>

using namespace std;

long long fib(long long n)
{
    long long a = 1;
    long long b = 1;
    if (n == 1)
        return b;

    long long i = 1;
    long long tmp = 0;
    while (i < n)
    {
        tmp = a + b;
        a = b;
        b = tmp;

        i++;
    }

    return b;
}

int main()
{
    long long i = 1;
    long long term = fib(1);
    unsigned long long sum = 0;
    while (term < 4000000)
    {
        if (term % 2 == 0)
        {
            sum += term;
        }
        i++;
        term = fib(i);
    }
    cout << "sum :" << sum << endl;
    return 0;
}
