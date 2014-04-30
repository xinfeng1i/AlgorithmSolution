#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class TheSimilarNumbers
{
public:
    bool isSimilar(int a, int b)
    {
        assert(a > 0);
        assert(b > 0);
        return a <= 10 * b && b <= 10* a;
    }

    int find(int lower, int upper)
    {
        for (int i = lower; i <= upper; ++i)
        {
            for (int j = i + 1; i <= upper; ++j)
            {
                if(j <= 10 * i && flag[j] == 0)
                {
                    flag[j] = -1;
                }
            }
        }

        int cnt = 0;
        for (int i = lower; i <= upper; ++i)
        {
            if (flag[i] != -1) cnt++;
        }

        return cnt;
    }

private:
    int flag[1000000 + 5];
};
