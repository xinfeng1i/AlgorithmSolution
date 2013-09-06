#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>

using namespace std;

/* 
 * Compute how many divisors a number |n| contains
 * Input:
 * n --- number
 * Output:
 * the number of divisors contained by |n|
 */
int DivisorNumber(int n)
{
    int mid = static_cast<int>(sqrt(n));
    int cnt = 1;
    for (int i = 2; i <= mid; i++)
    {
        if (n % i == 0)
        {
            cnt += 2;
        }
    }
    if (mid * mid == n)
    {
        cnt -= 1;
    }
    return cnt;
}
/**
 * Is |n| is a perfect number
 */
bool IsPerfectNumber(long long n)
{
    long long sum = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    if (sum == n)
        return true;
    else
        return false;
}

/*
 * Is number |n| is abundant number
 */
bool IsAbundantNumber(long long n)
{
    long long mid = static_cast<long long>(sqrt(n));
    long long sum = 1;
    for (long long i = 2; i <= mid; i++)
    {
        if (n % i == 0)
        {
            sum += (i + n/i);
        }
    }
    if (mid * mid == n)
    {
        sum -= mid;
    }

    if (sum > n)
        return true;
    else 
        return false;
}
int main()
{
    cout << "******************************" << endl;
    clock_t time_begin = clock();

    const int UP_LIMIT = 28123;
    vector<int> ivec;   // store all the abundant number under UP_LIMIT
    for (int i = 1; i <= UP_LIMIT; i++)
    {
        if (IsAbundantNumber(i))
        {
            ivec.push_back(i);
        }
    }

    set<int> iset;  // store all the numbers that equal sum of two abundants
    for (int i = 0; i < ivec.size(); i++)
    {
        for (int j = i; j < ivec.size(); j++)
        {
            long long tmp = ivec[i] + ivec[j];
            if (tmp <= UP_LIMIT)
            {
                iset.insert(tmp);
            }
        }
    }

    cout << "The number of Numbers that equals to sum of two abundants is: " 
        << iset.size() << endl;
    cout << "The number of Numbers that not equals to sum of two abundants is: "  
        << UP_LIMIT - iset.size() << endl;

    long long totalSum = (1 + UP_LIMIT) * UP_LIMIT / 2;
    
    // sum of numbers that equals to sum of two abundants
    long long tmpSum = 0;
    for (set<int>::iterator iter = iset.begin(); iter != iset.end(); iter++)
    {
        tmpSum += *iter;
    }

    cout << "Sum of Numbers that equals to sum of two abundants is: "
        << tmpSum << endl;
    cout << "Sum of Numbers that not equals to sum of two abundants is: "
        << totalSum - tmpSum << endl;

    clock_t time_end = clock();
    double time_cost = static_cast<double>(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << " seconds" << endl;

    return 0;
}
