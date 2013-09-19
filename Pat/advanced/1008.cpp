#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int UP_TIME   = 6;
const int DOWN_TIME = 4;
const int STOP_TIME = 5;
int main()
{
    queue<int> requestQueue;
    unsigned long long N = 0;
    int tmp = 0;
    cin >> N;
    for (unsigned long long i = 0; i < N; ++i)
    {
        cin >> tmp;
        requestQueue.push(tmp);
    }

    int cur = 0;    // current floor
    int next = 0;   // next floor to move
    unsigned long long costTime = 0;
    while (!requestQueue.empty())
    {
        next = requestQueue.front();
        requestQueue.pop();

        if (next > cur)
        {
            costTime += (next - cur) * UP_TIME + STOP_TIME;
        }
        else if (next < cur)
        {
            costTime += (cur - next) * DOWN_TIME + STOP_TIME;
        }
        else    // if already at the floor, add the STOP_TIME
        {
            costTime += STOP_TIME;
        }

        cur = next;
    }

    cout << costTime << endl;
    return 0;
}
