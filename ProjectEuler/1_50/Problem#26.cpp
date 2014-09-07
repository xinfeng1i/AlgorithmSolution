#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

/******************************************************************
 * return the number of digits that repeated in a / b
 *
 * For example:
 * 1 / 7 = 0.142857 142857 142857
 * return 6 (the length of 142857)
 *
 * 1 / 6 = 0.16666666...
 * return 1 (the lengh of 6)
 *****************************************************************/
int repeatedDecimal(int a, int b)
{
    vector<int> v;

    while (true)
    {

        while (a < b) { a *= 10; }

        // not find a in array v
        if (find(v.begin(), v.end(), a) == v.end())
        {
            v.push_back(a);
        }
        // find a in the array, it have been seen before
        // thus we've find the repeated decimal
        else
        {
            auto iter = find(v.begin(), v.end(), a); 
            return distance(iter, v.end());
        }
        
        if (a % b == 0)
        {
            return 0;
        }
        else
        {
            a = a % b;
        }
    }

}

int main()
{
    int maxCycle = 0;
    int maxd = 0;
    for (int d = 2; d < 1000; ++d)
    {
        int cycle = repeatedDecimal(1, d);
        if (cycle > maxCycle)
        {
            maxCycle = cycle;
            maxd = d;
        }
    }
    cout << "maxCycle: " << maxCycle << endl;
    cout << "max d : " << maxd << endl;
    return 0;
}
