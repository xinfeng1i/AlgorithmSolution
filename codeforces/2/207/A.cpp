#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m = 0;
    cin >> m;

    vector<int> cnt(m+1);
    int totalcnt = 0;
    vector<int> acc(m+1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> cnt[i];
        totalcnt += cnt[i];
        acc[i] = acc[i-1] + cnt[i];
    }

    int x, y;
    cin >> x >> y;

    for (int mark = 1; mark <= m; ++mark)
    {
        int lower_cnt = acc[mark] - cnt[mark];        
        int up_cnt = totalcnt - lower_cnt;
        if (lower_cnt >= x && lower_cnt <= y &&
            up_cnt >= x && up_cnt <= y)
        {
            cout << mark << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
