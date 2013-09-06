#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

/***********************************************
 * Sum of p powers of digits included in n
 *
 * Example:
 * Input: n = 123, p = 3;
 * Output: 1^3 + 2^3 + 3^3
 * 
 ***********************************************/
long long sumOfDigitPowers(long long n, long long p)
{
   if (n <= 0)
   {
        cerr << "n must be positive !!!" << endl;
        return -1;
   }
   if (p < 1)
   {
        cerr << "p must equal or greater than 1 !" << endl;
        return -1;
   }

   long long sum = 0;
   long long digit = 0;
   while (n > 0)
   {
        digit = n % 10;
        sum += pow(digit, p);
        n = n / 10;
   }
   return sum;
}

int main()
{
    clock_t time_begin = clock();

    const long long UP_LIMIT = 1000000;

    long long sum = 0;
    for (long long i = 10; i <= UP_LIMIT; i++)
    {
        if (sumOfDigitPowers(i,5) == i)
        {
            cout << i << endl;
            sum += i;
        }
    }
    cout << "**************************************" << endl;
    cout << "Total sum of numbers above is: " << sum << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << " s" << endl;
    return 0;
}
