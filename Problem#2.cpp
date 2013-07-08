#include <iostream>
#include <string>

using namespace std;

long long fib(long n)
{
    long a = 1;
    long b = 1;
    if (n == 1)
        return b;

    long i = 1;
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
    cout << "fib(1)" << fib(1) << endl;
    cout << "fib(2)" << fib(2) << endl;
    cout << "fib(3)" << fib(3) << endl;
    return 0;
}
