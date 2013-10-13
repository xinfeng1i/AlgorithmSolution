#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k;
    string a, b;
    cin >> k >> a >> b;

    int pa = 0;
    string a_int;
    flag a_hasPoint = false;
    while (pa < a.size() && a[pa] != '.')
    {
        pa++;
    }
    if (pa < a.size())
    {
        a_hasPoint = true;
    }

    int pb = 0;
    bool b_hasPoint = false;
    while (pb < b.size() && b[pb] != '.')
    {
        pb++;
    }
    if (pb < b.size())
    {
        b_hasPoint = true;
    }

#if 0
    int pb = 0;
    string b_int;
    while (pb < b.size() && b[pb] != '.')
    {
        pb++;
    }
    if (pb >= b.size())
    {
        b_int = b;
    }
    else
    {
        b_int = b.substr(0, pb);
    }

    if (a_int.size() == b_int.size() && a_int.size() >= k)
    {
        if (a_int[0] != '0' && b_int[0] != '0')
        {
            if (a_int.substr(0, k) == b_int.substr(0, k))
            {
                cout << "YES" << endl;
                cout << "0." << a_int.substr(0, k) << "*10^" << a.size() << endl;
                return 0;
            }
        }
    }
#endif

    return 0;
}
