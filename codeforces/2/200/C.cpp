#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long a = 0;
    long long b = 0;
    long long r = 0;
    
    cin >> a >> b;
    long long ans = 0;
    while (b != 0)
    {
        ans += a / b;
        r = a % b;
        a = b;
        b = r;
    }
    
    cout << ans << endl;
}

// The main idea behind this problem
//
// first, we have a/b (a > b, a % b = r), thus we need at least
// a/b resistors in sequence, thus left r/b resistance to be constructed
// we need two elements in parallel, i.e.
// 1 / ( (1 / RA) + (1 / RB) ) = r / b
// 1 / RA + 1 / RB = b / r  (where b > r)
// 1 / RA + 1 / RB = c + r2 / r
// so we need c in parallel to construct RA, so 
// 1 / RB = r2 / r   OR RB = r / r2
// so return back to our orignal problem, construct a r / r2 (where r > r2 )
// what we need is
// a / b = c1 .... r
// b / r = c2 .... r2
// r / r2 is our new problem, c1 + c2 is our current resistors we need
//
// so 
// Loop:
//      sum += a / b;
//      a % b = r;
//      a = b;
//      b = r
// This is typecially GCD Algorithm
