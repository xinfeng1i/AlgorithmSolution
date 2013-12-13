#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool isArithemic(vector<int> a, int &ans)
{
    assert(a.size() >= 2);
    int n = a.size();
    int constant = a[1] - a[0];

    bool flag = true;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] - a[i-1] != constant) 
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        ans = a[n-1] + constant;
    }

    return flag;
}

bool isGeometric(vector<int> a, int &ans)
{
    assert(a.size() >= 2);
    int n = a.size();

    if (a[1] % a[0] != 0)
    {
        return false;
    }

    int g = a[1] / a[0];
    bool flag = true;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] / a[i-1] != g)
        {
            flag = false;
        }
    }
    if (flag)
    {
        ans = a[n-1] * g;
    }

    return flag;
}


int theCount(vector<int> seq)
{
    int n = seq.size();
    if (n <= 1)
    {
        return -1;
    }

    int append1 = 0;
    int append2 = 0;
    bool flag1 = isArithemic(seq, append1);
    bool flag2 = isGeometric(seq, append2);

    if (!flag1 && !flag2)
    {
        return 0;
    }
    else if ((!flag1 && flag2) || (flag1 && !flag2))
    {
        return 1;
    }
    else
    {
        return append1 == append2 ? 1 : 2;
    }
}


int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    int ans = theCount(v);
    cout << ans << endl;

    return 0;
}
