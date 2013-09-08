#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

/*
 * return the number of permutations of given the parameter n
 *
 * For example:
 * Input:   n = 41063625
 *          do all kinds of permutations of n, we can find that:
 *          41063625 = 345^3
 *          56623104 = 384^3
 *          66430125 = 405^3
 * Output: 3
 */
int numOfCubicPermutations(long n)
{
    string str_n = to_string(n);
    long cnt = 0;
    do{
        long tmp = atol(str_n.c_str());
        long cubic_root = static_cast<long>(cbrt(static_cast<double>(tmp)));
        if (cubic_root * cubic_root * cubic_root == tmp)
        {
            cnt++;
        }

    }while(next_permutation(str_n.begin(), str_n.end()));
    return cnt;
}

bool isCubicNumber(long n)
{
    long cubic_root = static_cast<long>(cbrt(static_cast<double>(n)));
    if (cubic_root * cubic_root * cubic_root == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    const long LOW_BOUND = 41063625;
    long i = LOW_BOUND;
    while (true)
    {
       if (isCubicNumber(i) && numOfCubicPermutations(i) == 5)
       {
            cout << "result: " << i << endl;
            break;
       }
       i++;
    }
    return 0;
}
