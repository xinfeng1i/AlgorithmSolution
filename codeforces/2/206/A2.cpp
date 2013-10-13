#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k, d;
    cin >> k >> d;
    if (k == 1)
    {
        cout << d << endl;
    }
    else
    {
        if (d == 0)
        {
            cout << "No solution" << endl;
        }
        else
        {
            string s(k, '0');
            s[0] = d + '0';
            cout << s << endl;
        }
    }

    return 0;
}
