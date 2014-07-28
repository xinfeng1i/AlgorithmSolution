#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

class BishopMove
{
public:
    int howManyMoves(int r1, int c1, int r2, int c2)
    {
        if (r2 == r1 && c2 == c1)
        {
            return 0;
        }
        else if (abs(r2 - r1) == abs(c2 - c1))
        {
            return 1;
        }
        else if (abs(r2 - r1) % abs(c2 - c1) == 0 || abs(c2 - c1) % abs(r2 - r1) == 0)
        {
            return 2;
        }
        else
        {
            return -1;
        }
    }
};

