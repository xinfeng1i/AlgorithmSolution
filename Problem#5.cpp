#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/*
 * judge whether a integer is divisible from 1 to 20
 *
 * Notice: when the number can divide number from 11 to 20 without remainder
 * , it can certainly divide number from 1 to 10. So we can only judge
 * from 11 to 20.
 */
bool isDivisibleFrom1To20(long long n)
{
    int i = 0;
    for (i = 11; i <= 20; i++)
    {
        if (n % i != 0)
        {
            break;
        }
    }

    if (i <= 20)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    clock_t time_begin = clock();
    long long min_multiple = 2520;
    while (1)
    {
        if (isDivisibleFrom1To20(min_multiple))
        {
            break;
        }
        min_multiple++;
    }

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "smallest multiple:" << min_multiple << endl;
    cout << "TIME COST:" << time_cost << " s" << endl;

    return 0;
}

