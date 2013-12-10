#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int loop = n / k;

    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int j = 0; j < loop; ++j)
        {
            if (v[i + j * k] == 1)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }

        ans += min(cnt1, cnt2);
    }

    cout << ans << endl;

    return 0;
}
