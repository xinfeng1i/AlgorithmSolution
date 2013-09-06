#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <ctime>
#include <cmath>

using namespace std;

bool isPrime(long n);
long largestPandigitalPrime(int nDigit);
bool isPandigital(long n);

int main()
{
    clock_t time_begin = clock();

#if 0   // Method 1
    const int UP_BOUND = 10000000;

    long cur_max = 0;
    for (long i = 12; i < UP_BOUND; i++)
    {
        if (isPandigital(i) && isPrime(i))
        {
            cout << "Pandigital Prime: " << i << endl;
            if (i > cur_max)
            {
                cur_max = i;
            }
        }
    }
    cout << "Largest Pandigital Prime: " << cur_max << endl;
#endif

#if 1   // Method 2, 10 times faster than method 1
    for (int i = 2; i <= 9; i++)
    {
        cout << i << "digit "<< "Largest Pandigital Prime " 
            << largestPandigitalPrime(i) << endl;
    }
#endif
    
    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << endl;

    return 0;
}

/**
 */
bool isPrime(long n)
{
    if (n <= 1)
    {
        return false;
    }

    long mid = (long)sqrt(static_cast<double>(n));
    for (long i = 2; i <= mid; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

/* return |nDigit|-digit largest Pandigital Prime 
 */
long largestPandigitalPrime(int nDigit)
{
    vector<int> number;
    long result = 0;
    long max = 0;
    for (int i = 1; i <= nDigit; i++)
    {
        number.push_back(i);;
    }

    do
    {
       result = 0;
       int exp = 0;
       for (auto it = number.rbegin(); it != number.rend(); it++)
       {
            result += (*it) * (long)(pow(10.0, exp));
            exp++;
       }
       if (isPrime(result) && result > max)
       {
            max = result;
       }
    }while(next_permutation(number.begin(), number.end()));

    return max;
}

/*
 * judge whether |n| is Pandigital 
 */
bool isPandigital(long n)
{
    string str_n = to_string(n);
    int length = str_n.size();
    if (length > 9)
    {
        return false;
    }

    array<int, 10> digits;  // digits[3] = 5, use number 3 five times
    digits.fill(0);

    for (auto iter = str_n.begin(); iter != str_n.end(); iter++)
    {
        digits[(*iter) - '0']++;
    }


    if (digits[0] != 0)
    {
        return false;
    }
    for (int i = 1; i <= length; i++)
    {
        if (digits[i] != 1)
        {
            return false;
        }
    }

    return true;
}
