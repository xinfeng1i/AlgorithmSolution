#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int compareChar(char a, char b)
{
    if (a == b)
    {
        return 0;
    }
    else
    {
        if ( (a == 'C' && b == 'J') ||
             (a == 'J' && b == 'B') ||
             (a == 'B' && b == 'C') )
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    long n;
    cin >> n;

    char ch1, ch2;
    long victory_cnt1 = 0, fail_cnt1 = 0, equal_cnt1 = 0;
    long victory_cnt2 = 0, fail_cnt2 = 0, equal_cnt2 = 0;
    map<char, long> char_victory_cnt1;
    map<char, long> char_victory_cnt2;
    for (long i = 0; i < n; ++i)
    {
        cin >> ch1 >> ch2;
        if (compareChar(ch1, ch2) > 0)
        {
            victory_cnt1++;
            fail_cnt2++;
            char_victory_cnt1[ch1]++;
        }
        else if (compareChar(ch1, ch2) == 0)
        {
            equal_cnt1++;
            equal_cnt2++;
        }
        else
        {
            fail_cnt1++;
            victory_cnt2++;
            char_victory_cnt2[ch2]++;
        }
    }

    cout << victory_cnt1 << " " << equal_cnt1 << " " << fail_cnt1 << endl;
    cout << victory_cnt2 << " " << equal_cnt2 << " " << fail_cnt2 << endl;

    char max_char1 = 'B';
    long max_cnt1 = 0;
    char max_char2 = 'B';
    long max_cnt2 = 0;
    map<char, long>::iterator it1, it2;
    for (it1 = char_victory_cnt1.begin(); it1 != char_victory_cnt1.end(); ++it1)
    {
        if (it1->second > max_cnt1)
        {
            max_cnt1 = it1->second;
            max_char1 = it1->first;
        }
    }

    for (it2 = char_victory_cnt2.begin(); it2 != char_victory_cnt2.end(); ++it2)
    {
        if (it2->second > max_cnt2)
        {
            max_cnt2 = it2->second;
            max_char2 = it2->first;
        }
    }

    cout << max_char1 << " " << max_char2 << endl;

    return 0;
    
}
