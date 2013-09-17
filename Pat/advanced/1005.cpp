#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string spellNumber(int digit)
{
    assert(digit >=0 && digit <= 9);
    switch (digit)
    {
        case 0: return "zero";
                break;
        case 1: return "one";
                break;
        case 2: return "two";
                break;
        case 3: return "three";
                break;
        case 4: return "four";
                break;
        case 5: return "five";
                break;
        case 6: return "six";
                break;
        case 7: return "seven";
                break;
        case 8: return "eight";
                break;
        case 9: return "nine";
                break;
    }
}

int main()
{
    string number;
    cin >> number;

    long long sum = 0;
    for (string::iterator it = number.begin(); it != number.end(); ++it)
    {
        sum += *it - '0';
    }

   //cout << "sum = " << sum << endl;

    string str_num = to_string(sum);
    bool flag = false;
    for (int i = 0; i < str_num.size(); ++i)
    {
        if (flag)
        {
            cout << " ";
        }
        else
        {
            flag = true;
        }

        cout << spellNumber(str_num[i]-'0');
    }
    cout << endl;
    return 0;
}