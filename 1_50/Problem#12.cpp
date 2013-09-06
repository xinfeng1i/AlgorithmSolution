#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

long long numOfFactors(long long n)
{
    if (n == 1)
        return 1;
    double trueMid = sqrt(n);
    long long mid = static_cast<long long>(trueMid);
    long long cnt = 0;
    for (int i = 1; i <= mid; i++)
    {
        if (n % i == 0)
        {
            if (i == mid && (trueMid - mid) <= 0.001)
            {
                cnt += 1;
            }
            else
            {
                cnt += 2;
            }
        }
    }
    return cnt;
}

int main()
{
    #if 0
    cout << "1 factor num:" << numOfFactors(1) << endl;
    cout << "2 factor num:" << numOfFactors(2) << endl;
    cout << "3 factor num:" << numOfFactors(3) << endl;
    cout << "10 factor num:" << numOfFactors(10) << endl;
    cout << "25 factor num:" << numOfFactors(25) << endl;
    cout << "28 factor num:" << numOfFactors(28) << endl;
    #endif

    clock_t time_begin = clock();

    const long long NUM_OF_DIVISOR = 500;
    long long cnt = 1;
    long long triNum = 1;
    while (numOfFactors(triNum) <= NUM_OF_DIVISOR)
    {
        triNum += cnt + 1;
        cnt++;
    }
    cout << "The first triangle number to have over " << NUM_OF_DIVISOR 
        << " divisors is:" << endl;
    cout << "the " << cnt << "th triangle number:" << triNum << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << endl;
    return 0;
}
