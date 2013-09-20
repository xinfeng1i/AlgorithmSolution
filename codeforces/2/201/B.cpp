#include <iostream>
#include <string>
#include <vector>
using namespace std;

long cntFixedPoints(vector<long> v)
{
    long sz = v.size();
    long cnt = 0;
    for (long i = 0; i < sz; ++i)
    {
        if (v[i] == i)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    long n = 0;
    cin >> n;
    vector<long> v(n, 0);
    for (long i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    long ans = cntFixedPoints(v);
    
    // special case, all at positions
    if (ans == n)
    {
        cout << ans << endl;
        return 0;
    }

    bool haveReverse = false;
    for (long i = 0; i < n; ++i)
    {
        if (i != v[i] && i == v[v[i]])
        {
            haveReverse = true;
            break;
        }
    }

    if (haveReverse)
    {
        ans += 2;
    }
    else
    {
        ans += 1;
    }
    cout << ans << endl;

    return 0;
}
