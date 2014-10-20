#include <iostream>
#include <string>
using namespace std;
/*
 * Count the number of bits set in binary representation of
 * all numbers from 1 to n
 */

// Method 1: Brute Force
// Time Complexity: O(number of bits from 1 to n)
// Return the number of bit set of x
unsigned long CountBitSetNumber(unsigned long x)
{
    unsigned long cnt = 0;
    while (x)
    {
        x = x & (x - 1);
        cnt++;
    }
    return cnt;
}

unsigned long CountAllBitSetFrom1ToN(unsigned long n)
{
    unsigned long ans = 0;
    for (unsigned long i = 1; i <= n; ++i)
    {
        ans += CountBitSetNumber(i); 
    }
    return ans;
}

int main()
{
    unsigned long n;
    cin >> n;
    cout << CountAllBitSetFrom1ToN(n) << endl;
    return 0;
}
