#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    int B;

    cin >> s >> B;
    int sz = s.size();

    // init a[];
    vector<int> a(sz, 0);
    for (int i = 0; i < sz; ++i)
    {
        a[i] = s[i] - '0';
    }
    

    int r = 0;
    for (int i  = 0; i < sz; ++i)
    {
        // first compute r, then change a[i]
        r = a[i] % B;
        a[i] = a[i] / B;

        if (i + 1 < sz)
        {
            a[i + 1] += 10 * r;
        }
    }

    int pos = 0;
    while (pos < sz && a[pos] == 0)
    {
        pos++;
    }

    if (pos >= sz)
    {
        cout << 0 << " " << r << endl;
    }
    else
    {
        for (int i = pos; i < sz; ++i)
        {
            cout << a[i];
        }

        cout << " " << r << endl;
    }
    return 0;
}
