#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int getMin(vector<int> position)
{
    int n = position.size();
    int min = 300;

    for (int skip = 1; skip <= n - 2; ++skip)
    {
        int tmp = 0;
        for (int i = 0; i <= n - 2; ++i)
        {
            int cur = i;
            int next = i + 1;
            if (cur == skip)
            {
                continue;
            }
            else
            {
                if (next == skip)
                {
                    next++;
                }
            }
            
            tmp += abs(position[cur] - position[next]);
        }

        if (tmp < min)
        {
            min = tmp;
        }
    }

    return min;
}

int main()
{
    vector<int> v(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i + 1;
    }
    cout << getMin(v) << endl;
    return 0;
    
}
