#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int cnt_0 = 0;
    int cnt_5 = 0;
    int tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            cnt_0++;
        }
        else if (tmp == 5)
        {
            cnt_5++;
        }
    }

    if (cnt_0 < 1)
    {
        cout << -1 << endl;
        return 0;
    }

    bool flag = false;
    for (int i = 0; i < cnt_5 / 9; ++i)
    {
        cout << 555555555;
        flag = true;
    }
    if (flag)
    {
        for (int i = 0; i < cnt_0; ++i)
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
    cout << endl;
    return 0;
}
