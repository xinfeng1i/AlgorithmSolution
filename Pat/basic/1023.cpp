#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a[10];
    for (int i = 0; i < 10; ++i)
    {
        cin >> a[i];
    }

    string ans;
    for (int i = 0; i < 10; ++i)
    {
        if (a[i] != 0)
        {
            ans += string(a[i], i + '0');
        }
    }

    if (ans[0] == '0')
    {
        for (int i = 1; i < ans.size(); ++i)
        {
            if (ans[i] != '0')
            {
                swap(ans[0], ans[i]);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

