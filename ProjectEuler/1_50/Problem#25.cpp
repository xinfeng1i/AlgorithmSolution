#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 1000;

int main()
{
    clock_t time_begin = clock();

    int a[ARRAY_SIZE] = {0};    // init first term

    int b[ARRAY_SIZE] = {0};    // init second term 
    b[0] = 1;

    int result[ARRAY_SIZE] = {0};   // init fib term
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        result[i] = a[i] + b[i];
    }
    long long cnt = 2;

    while (result[ARRAY_SIZE-1] == 0)   // not contain 1000 digits
    {
       for (int i = 0; i < ARRAY_SIZE; i++) // a = b
       {
            a[i] = b[i];
       }

       for (int i = 0; i < ARRAY_SIZE; i++) // b = tmp
       {
            b[i] = result[i];
       }

       for (int i = 0; i < ARRAY_SIZE; i++) // tmp = a + b
       {
            result[i] = a[i] + b[i];
       }
       for (int i = 0; i < ARRAY_SIZE; i++)
       {
            if (result[i] >= 10)
            {
                result[i+1] += result[i] / 10;
                result[i] = result[i] % 10;
            }
       }

       cnt++;
    }

    cout << "The first item contains " << ARRAY_SIZE << " digits is:" << cnt << endl;
    cout << "The " << ARRAY_SIZE << " number is: " << endl;
    long long firstNoZeros = ARRAY_SIZE - 1;
    while (result[firstNoZeros] == 0)
    {
        firstNoZeros--;
    }
    for (int i = firstNoZeros; i >= 0; i--)
    {
        cout << result[i];
    }
    cout << endl;
    
    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << " s" << endl;

    return 0;
}
