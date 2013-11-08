#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string check(string str)
{
    // base case
    if (str == "")
    {
        return "VALID";
    }

    // first char not 'w', false
    if (str[0] != 'w')
    {
        return "INVALID";
    }

    // calc the number of 'w's
    int cnt = 0;
    int i = 0;
    while (i < str.size() && str[i] == 'w')
    {
        cnt++;

        ++i;
    }
    // if the follow chars not has 3*cnt chars, false
    if (4 * cnt > str.size())
    {
        return "INVALID";
    }

    for (int k = cnt; k < 2 * cnt; ++k)
    {
        if (str[k] != 'o')
        {
            return "INVALID";
        }
    }

    for (int k = cnt * 2; k < cnt * 3; ++k)
    {
        if (str[k] != 'l')
        {
            return "INVALID";
        }
    }

    for (int k = 3 * cnt; k < cnt * 4; ++k)
    {
        if (str[k] != 'f')
        {
            return "INVALID";
        }
    }

    return check(str.substr(4 * cnt));
}

int main()
{
    string s;
    cin >> s;
    cout << check(s) << endl;
    return 0;
}
