#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;


/*  Formally, Ciel thinks that a number X is interesting if the following property is satisfied: 
    For each D between 0 and 9, inclusive, 
    X either does not contain the digit D at all, 
    or it contains exactly two digits D, 
    and there are precisely D other digits between them.
*/

string isInteresting(string x)
{
    for (int i = 0; i <=9; ++i)
    {
        if(count(x.begin(), x.end(), i + '0') == 0)
        {
            continue;
        }
        else if (count(x.begin(), x.end(), i + '0') == 2)
        {
            int first = x.find_first_of(i + '0');
            int second = x.find_last_of(i + '0');
            if (second - first - 1 == i)
            {
                continue;
            }
            else
            {
                return "Not interesting";
            }
        }
        else
        {
            return "Not interesting";
        }
    }
    return "Interesting";
}

#if 0
int main()
{
    cout << "Hello world!" << endl;
    string s;
    while (cin >> s)
    {
        cout << isInteresting(s) << endl; 
    }
    return 0;
}
#endif// 0