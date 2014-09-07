#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int MAX_LENGTH = 500;
const int MAX_POWER = 1000;

int main()
{
    clock_t time_begin = clock();

    int a[MAX_LENGTH] = {0};
    a[0] = 1;
    for (int i = 1; i <= MAX_POWER; i++)
    {
        for (int k = 0; k < MAX_LENGTH; k++)
        {
            a[k] *= 2;
        }
        for (int k = 0; k < MAX_LENGTH; k++)
        {
            if (a[k] >= 10)
            {
                a[k+1] += a[k] / 10;
                a[k] = a[k] % 10;
            }
        }
    }

    cout << "The power(2,"<< MAX_POWER << ") is:" << endl;
    int firstNoZeros = MAX_LENGTH - 1;
    while (a[firstNoZeros] == 0)
    {
        firstNoZeros--;
    }
    for (int i = firstNoZeros; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << endl;
    
    cout << "The sum of the digits is: " << endl;
    long long sum = 0;
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        sum += a[i];
    }
    cout << sum << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << " s" << endl;
    return 0;
}
