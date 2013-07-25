#include <iostream>
#include <string>
#include <set>
#include <cassert>
#include <ctime>

using namespace std;

bool ContainZero(long n)
{
    assert(n > 0);
    while (n != 0)
    {
        int remain = n % 10;
        if (remain == 0)
            return true;
        n /= 10;
    }
    return false;
}

bool IsPandigitalProduct(long multiplicand, long multiplier)
{
    assert(multiplicand > 0 && multiplier > 0);

    if (ContainZero(multiplicand) || ContainZero(multiplier))
    {
        return false;
    }
    long product = multiplicand * multiplier;
    if (ContainZero(product))
    {
        return false;
    }
    int count[10] = {0};
    while (multiplicand != 0)
    {
        int remain = multiplicand % 10;
        count[remain]++;
        multiplicand /= 10;
    }
    while (multiplier != 0)
    {
        int remain = multiplier % 10;
        count[remain]++;
        multiplier /= 10;
    }
    while (product != 0)
    {
        int remain = product % 10;
        count[remain]++;
        product /= 10;
    }

    for (int i = 1; i < 10; i++)
    {
        if (count[i] != 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    clock_t time_begin = clock();

    const int MAX_LIMIT = 10000;
    set<long> product;
    for (int i = 1; i < MAX_LIMIT; i++)
    {
        for (int j = i; j < MAX_LIMIT; j++)
        {
            if (IsPandigitalProduct(i, j))
            {
                cout << "i = " << i << "   " << "j = " << j 
                    << "   " << "product = " << i * j << endl;
                product.insert(i * j);
            }
        }
    }

    long sum = 0;
    for (set<long>::iterator it = product.begin(); it != product.end(); it++)
    {
        sum += *it;
    }
    cout << "Sum: " << sum << endl;

    clock_t time_end = clock();
    double time_cost = static_cast<double>(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << " seconds" << endl;
    return 0;
}
