#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// greatest common divisor
long long gcd(long long a, long long b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

// find the fators (2, 3, 5) count in number of n
// return true if n only contains factor 2, 3, 5
// or return false;
bool factorsIn(long long n, int &cnt2, int &cnt3, int &cnt5)
{
    while (n % 2 == 0)
    {
        n /= 2;
        cnt2++;
    }

    while (n % 3 == 0)
    {
        n /= 3;
        cnt3++;
    }

    while (n % 5 == 0)
    {
        n /= 5;
        cnt5++;
    }

    if (n != 1)
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
    long long a, b;
    cin >> a >> b;

    // find gcd
    long long d = gcd(a, b);

    // a and b cannot reduce futhermore
    a /= d;
    b /= d;

    int cnt2_a = 0, cnt3_a = 0, cnt5_a = 0;
    bool a_flag = factorsIn(a, cnt2_a, cnt3_a, cnt5_a);

    int cnt2_b = 0, cnt3_b = 0, cnt5_b = 0;
    bool b_flag = factorsIn(b, cnt2_b, cnt3_b, cnt5_b); 
    
    // have some other factors, then must not be reduce
    if (a_flag || b_flag)
    {
        cout << -1 << endl;
        return 0;
    }

    int cnt2 = max(cnt2_a, cnt2_b);
    int cnt3 = max(cnt3_a, cnt3_b);
    int cnt5 = max(cnt5_a, cnt5_b);
    cout << cnt2 + cnt3 + cnt5 << endl;
    return 0;

}
