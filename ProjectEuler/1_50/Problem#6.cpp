#include <iostream>
#include <string>
#include <cmath>

using namespace std;


/*
 * Sum of Arithmetic Series
 *
 * @start -- start of arithmetic series
 * @end -- end of arithmetic series
 * @cd -- common difference of arithmetic series
 *
 * @return -- sum of arithmetic series
 */
long long sumArithmeticSeries(long long start, long long end, long long cd)
{
   long long numOfTerms = (end - start) / cd + 1;

   return (start + end) * numOfTerms / 2;
}

int main()
{
    // test function sumArithmeticSeries
    #if 0
    cout << "sum 1 + 2 + ... + 100 : " << sumArithmeticSeries(1, 100, 1) << endl;
    cout << "sum 1 + 3 + ... + 99 : " << sumArithmeticSeries(1, 99, 2) << endl;
    cout << "sum 2 + 4 + ... + 100 : " << sumArithmeticSeries(2, 100, 2) << endl;
    cout << "sum 3 + 4: " << sumArithmeticSeries(3, 4, 1) << endl;
    cout << "sum 3 : " << sumArithmeticSeries(3, 3, 1) << endl;
    #endif // 1

    clock_t time_begin = clock();

    long long sum = 0;
    for (int i = 1; i <= 99; i++)
    {
       sum += 2 * i * sumArithmeticSeries(i+1, 100, 1); 
    }
    cout << "Sum square difference: " << sum << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;

    cout << "TIME COST: " << time_cost << "s" << endl;
    return 0;
}
