#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    clock_t time_begin = clock();

    int a = 1;
    int b = 1;
    int c = 1;
    for (a = 1; a <= 1000; a++)
    {
        for (b = a + 1; b <= 1000; b++)
        {
            c = 1000 - a - b;
            if (pow(a, 2.0) + pow(b, 2.0) == pow(c, 2.0))
            {
                cout << "a = " << a << endl;
                cout << "b = " << b << endl;
                cout << "c = " << c << endl;
                cout << "abc = " << a * b * c << endl;
            }
        }
    }
    
    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << endl;
    return 0;
}
