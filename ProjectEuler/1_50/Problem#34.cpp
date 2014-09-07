#include <iostream>
#include <string>
#include <cassert>
#include <ctime>

using namespace std;

long long factorial(long long n)
{
    assert(n >= 0);
    long long result = 1;
    for (long long i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

bool IsCuriousNumber(long long n)
{
    long long sum = 0;
    string n_str = to_string(n);
    for (size_t i = 0; i < n_str.size(); i++)
    {
        sum += factorial(n_str[i] - '0');
    }
    if (sum == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    clock_t time_begin = clock();

    const int UP_LIMIT = 1000000;
    long long sum = 0;
    for (long long i = 10; i <= UP_LIMIT; i++)
    {
        if (IsCuriousNumber(i))
        {
            cout << i << endl;
            sum += i;
        }
    }
    cout << "Sum is: " << sum << endl;
    
    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << 1000 * time_cost << " ms" << endl;
    return 0;
}
