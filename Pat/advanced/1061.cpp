#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;

string toDay(int d)
{
    switch(d)
    {
        case 1: return "MON";
                break;
        case 2: return "TUE";
                break;
        case 3: return "WED";
                break;
        case 4: return "THU";
                break;
        case 5: return "FRI";
                break;
        case 6: return "SAT";
                break;
        case 7: return "SUN";
                break;
        default:cerr << "Function toDay parameter wrong" << endl;
                break;
    }
}

int main()
{
    //freopen("1061data.txt", "r", stdin);

    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    string day;
    int hour;
    int minite;
    int minsz1 = min(s1.size(), s2.size());
    int i = 0;
    for (i = 0; i < minsz1; ++i)
    {
        if (s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'G'))
        {
            day = toDay(s1[i] - 'A' + 1);
            break;
        }
    }

    for (int j = i + 1; j < minsz1; ++j)
    {
        if ( s1[j] == s2[j] && 
             ( (s1[j] >= '0' && s1[j] <= '9') || 
               (s1[j] >= 'A' && s1[j] <= 'N') ) )
        {
            if (s1[j] >= '0' && s1[j] <= '9')
            {
                hour = s1[j] - '0';
            }
            else
            {
                hour = s1[j] - 'A' + 10;
            }
            
            break;
            
        }
                         
    }

    int minsz2 = min(s3.size(), s4.size());
    for (int i = 0; i < minsz2; ++i)
    {
        if (s3[i] == s4[i] && isalpha(s3[i]))
        {
            minite = i;
            break;
        }
    }

    cout << day << " ";
    printf("%02d:%02d\n", hour, minite);
    return 0;
}
