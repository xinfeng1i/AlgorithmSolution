#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int firstCnt = count(v.begin(), v.end(), 1);
    int secondCnt = count(v.begin(), v.end(), 2);

    int ans = 0;
    m -= firstCnt;
    if (m > 0)
    {
        ans = max(secondCnt - (m + k), 0);
    }
    else
    {
        ans = abs(m) + max(secondCnt - k, 0);
    }

    cout << ans << endl;
    return 0;
}
