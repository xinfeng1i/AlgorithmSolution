#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/*
 * In the Collatz Iterative Sequence:
 * Calculate the number of terms from the given parameter
 *
 * Example:
 * Input: 13
 * Output: 10
 * Since: 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 */
long long numTermFrom(long long n)
{
    long long cnt = 1;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        cnt++;
    }
    return cnt;
}


int main()
{
    clock_t time_begin = clock();

    const long long MAX_LIMIT = 1000000;

    long long maxNumTerms = 0;
    long long startNum = 1;
    long long curNumTerms = 0;
    for (long long i = 1; i <= MAX_LIMIT; i++)
    {
        curNumTerms = numTermFrom(i);
        if (curNumTerms > maxNumTerms)
        {
            maxNumTerms = curNumTerms;
            startNum = i;
        }
    }
    cout << "Which Start number, under one million," << 
        "produces the longest chain ? " << endl;
    cout << "Start Number: " << startNum  << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << " s" << endl;

    return 0;
}
