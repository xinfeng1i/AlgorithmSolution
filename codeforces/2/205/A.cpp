#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("Adata.txt", "r", stdin);
    int n;
    cin >> n;

    int cnt11 = 0;
    int cnt12 = 0;
    int cnt21 = 0;
    int a, b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        if (a % 2 == 0 && b % 2 == 0)
        {
            continue;
        }
        else if (a % 2 == 1 && b % 2 == 1)
        {
            cnt11++;
        }
        else if (a % 2 == 1 && b % 2 == 0)
        {
            cnt12++;
        }
        else
        {
            cnt21++;
        }
    }

    cnt11 = cnt11 % 2;
    cnt12 = cnt12 % 2;
    cnt21 = cnt21 % 2;
    if (cnt11 == 0)
    {
        if (cnt12 == 1 && cnt21 == 1)
        {
            cout << 1 << endl;
        }
        else if (cnt12 == 0 && cnt21 == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        if (cnt12 == 1 && cnt21 == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
