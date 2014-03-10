#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 234
int finalPosition(string commands, int A, int B)
{
    int n = commands.size();
    int pos = 0;
    for (int i = 0; i < n; ++i)
    {
        if (commands[i] == 'L')
        {
            if (pos > -A)
            {
                pos--;
            }
        }
        else if (commands[i] == 'R')
        {
            if (pos < B)
            {
                pos++;
            }
        }
    }
    return pos;
}
