#include <iostream>
#include <string>
using namespace std;

int digitalRoot(string n)
{
    int sum = 0;
    for (int i = 0; i < n.size(); ++i)
    {
        sum += n[i] - '0';
    }

    if (sum < 10)
    {
        return sum;
    }

    return digitalRoot(to_string(sum));
}

void strAddOne(string& s)
{
    int sz = s.size();
    s[sz-1] += 1;
    for (int i = sz-1; i > 0; i--)
    {
        if (s[i] > '9')
        {
            s[i] = '0';
            s[i-1] += 1;
        }
    }
}

int main()
{
    int k, d;
    cin >> k >> d;
    if (k == 1)
    {
        cout << d << endl;
        return 0;
    }

    string min_str(k, '0');
    min_str[0] = '1';

    string max_str(k, '9');

    for (string s = min_str; s < max_str; strAddOne(s))
    {
        if (digitalRoot(s) == d)
        {
            cout << s << endl;
            return 0;
        }
    }

    cout << "No solution" << endl;
    return 0;
}
