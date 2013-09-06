#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    clock_t time_begin = clock();

    string total("");
    for (long i = 1; i <= 1000000;  i++)
    {
       total += to_string(i); 
    }

    long result = 1;
    for (long index = 1; index <= 1000000; index *= 10)
    {
        result *= total[index-1] - '0';
    }

    cout << "result: " << result << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost * 1000 << " ms" << endl;
    return 0;
}
