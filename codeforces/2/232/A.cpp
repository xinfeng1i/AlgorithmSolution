#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    vector<int> v(101, 0);
    int n;
    cin >> n;
    int s, e;
    cin >> s >> e;
    for (int i = s + 1; i <= e; ++i)
    {
        v[i] = 1;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> s >> e;
        for (int k = s + 1; k <= e; ++k)
        {
            v[k] = 0;
        }
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == 1)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
