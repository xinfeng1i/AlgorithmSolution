#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

long gcd(long a, long b)
{
    // make a low mistake, wirte equal== as assign=, what a shame. 
    return b == 0 ? a : gcd(b, a % b);
}
long lcm(long a, long b)
{
    long g = gcd(a, b);
    return g * (a / g) * (b / g);
}
string include(vector<int> S, long x)
{
    vector<int> maybe;
    for (int i = 0; i < S.size(); ++i)
    {
        if (x % S[i] == 0)
        {
            maybe.push_back(S[i]);
        }
    }

    if (maybe.size() == 0 ||
        (maybe.size() == 1 && maybe[0] != x))
    {
        return "Impossible";
    }

    sort(maybe.begin(), maybe.end());
    while(maybe.size() > 1)
    {
        vector<int> tmp_ret;
        for (int i = 0, j = maybe.size() - 1; i <= j; i++, j--)
        {
            tmp_ret.push_back(lcm(maybe[i], maybe[j]));
        }
        maybe.clear();
        maybe.assign(tmp_ret.begin(), tmp_ret.end());
    }
    if (maybe[0] == x)
    {
        return "Possible";
    }
    else
    {
        return "Impossible";
    }
}

#if 0
int main()
{
    
    cout << "input your vector size:" << endl;
    int n;
    cin >> n;
    cout << "input your vector elems:" << endl;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << "Input x:" << endl;
    int x;
    cin >> x;
    cout << include(v,x) << endl;

    return 0;
}
#endif //0