#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

bool greaterOne(int x)
{
    return x >= 1;
}

// VERSION 1: Simulation method
#if 0
int main()
{
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> b(n, 0);

    int cnt = count_if(a.begin(), a.end(), greaterOne);
    while (cnt > 0)
    {
        // add 1 to the right cnt column of b
        for (int i = n - 1; i >= n - cnt; --i)
        {
            b[i]++;
        }

        // minus 1 to all the column of a
        for (int i = 0; i < n; ++i)
        {
            if (a[i] >= 1)
            {
                a[i]--;
            }
        }

        cnt = count_if(a.begin(), a.end(), greaterOne);
    }

    bool isFirst = true;
    for (int i = 0; i < n; ++i)
    {
        if (isFirst)
        {
            cout << b[i];
            isFirst = false;
        }
        else
        {
            cout << " " << b[i];
        }
    }
    cout << endl;


    return 0;
}
#endif //0

// version 2: the editorial version, sort problem
int main()
{
    int n = 0;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        cout << " " << v[i];
    }
    cout << endl;

    return 0;
}
