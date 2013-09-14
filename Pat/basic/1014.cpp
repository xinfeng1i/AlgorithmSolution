#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

string convertDay(int day)
{
    assert(day >= 1 && day <= 7);
    switch (day)
    {
        case 1:
            return "MON";
            break;
        case 2:
            return "TUE";
            break;
        case 3:
            return "WED";
            break;
        case 4:
            return "THU";
            break;
        case 5:
            return "FRI";
            break;
        case 6:
            return "SAT";
            break;
        case 7:
            return "SUN";
            break;
        default:
            return "ERR";
            break;
    }
}
int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    int day = 0;
    int hour = 0; 
    int minite = 0;
    int sz = min(s1.size(), s2.size());
    int i = 0;
    for (i = 0; i < sz; ++i)
    {
        // day range 'A' - 'G'
        if (s1[i] == s2[i] && isalpha(s1[i]) && isupper(s1[i]) && s1[i] >= 'A' && s1[i] <= 'G')
        {
                day = s1[i] - 'A' + 1; 
                break;
        }
    }
    for (int j = i + 1; j < sz; ++j)
    {
        // hour range '0' - '9' OR 'A' - 'N'
        if (s1[j] == s2[j] && isdigit(s1[j]) && s1[j] >= '0' && s1[j] <= '9')
        {
            hour = s1[j] - '0';
            break;
        }
        if (s1[j] == s2[j] && isalpha(s1[j]) && isupper(s1[j]) && s1[j] >= 'A' && s1[j] <= 'N')
        {
            hour = s1[j] - 'A' + 10;
            break;
        }
    }

    int sz2 = min(s3.size(), s4.size());
    for (int k = 0; k < sz2; ++k)
    {
        if (s3[k] == s4[k] && isalpha(s3[k]))
        {
            minite = k;
            break;
        }
    }

    cout << convertDay(day) << " ";

    if (hour < 10)
    {
        cout << 0 <<hour;
    }
    else
    {
        cout << hour;
    }

    cout << ":";

    if (minite < 10)
    {
        cout << 0 << minite;
    }
    else
    {
        cout << minite;
    }
    cout << endl;
    return 0;
}
