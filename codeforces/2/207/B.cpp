#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    long n, m;
    cin >> n >> m;

    vector<int> colors(n + 1, 0);

    long a, b, c;
    for (long i = 0; i < m; ++i)
    {
        set<int> cset;
        cset.insert(1);
        cset.insert(2);
        cset.insert(3);

        cin >> a >> b >> c;

        if (colors[a] != 0)
        {
            cset.erase(colors[a]);
        }
        if (colors[b] != 0)
        {
            cset.erase(colors[b]);
        }
        if (colors[c] != 0)
        {
            cset.erase(colors[c]);
        }

        if (colors[a] == 0)
        {
            colors[a] = *(cset.begin());
            cset.erase(colors[a]);
        }
        if (colors[b] == 0)
        {
            colors[b] = *(cset.begin());
            cset.erase(colors[b]);
        }
        if (colors[c] == 0)
        {
            colors[c] = *(cset.begin());
            cset.erase(colors[c]);
        }
    }

    cout << colors[1];
    for (long i = 2; i <= n; ++i)
    {
        cout << " " << colors[i]; 
    }
    cout << endl;

    return 0;
}
