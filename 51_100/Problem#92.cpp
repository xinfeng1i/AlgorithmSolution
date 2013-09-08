#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* return sum of all digits quare 
 * for example:
 * input: 32
 * since: 32 = 3^2 + 2^2 = 13
 * output: 13
 */
long digitsSquareSum(long n)
{
    long sum = 0;
    string str_n = to_string(n);
    for (int i = 0; i < str_n.size(); ++i)
    {
        sum += (str_n[i] - '0') * (str_n[i] - '0');
    }
    return sum;
}

/* Judge whether a number through Square gigit chains
 * can reach 89
 *
 * For example:
 * 44 -> 32 -> 13 -> 10 -> 1 return false
 * 85 -> 89  return true
 */
bool canReach89(long n)
{
    while (n != 1 && n != 89)
    {
        n = digitsSquareSum(n);
    }

    if (n == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    const long UP_LIMIT = 10000000;
    long cnt = 0;
    for (long i = 1; i < UP_LIMIT; ++i)
    {
        if (canReach89(i))
        {
            cnt++;
        }
    }
    cout << "How many numbers below ten million can reach 89 ? "
        << cnt << endl;
    return 0;
}
