#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int SPIRAL_SIZE = 1001;
const long long UP_LIMIT = SPIRAL_SIZE * SPIRAL_SIZE;

int main()
{
    clock_t time_begin = clock();

    long long sum = 1;
    int nextNum = 1;
    int step = 0;

    while (1)
    {
        step += 2;
        for (int i = 0; i < 4; i++)
        {
            nextNum += step;
            sum += nextNum;
        }
        if (nextNum >= UP_LIMIT)
        {
            break;
        }
    }

    cout << "sum :" << sum << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << " s" << endl;
    return 0;
}


