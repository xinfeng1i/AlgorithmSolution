#include <iostream>
#include <string>
using namespace std;

bool isPanlindromic(const string& s)
{
    // base case
    if (s == "")
    {
        return true;
    }

    if (s[0] != s[s.size() - 1])
    {
        return false;
    }
    else
    {
        return isPanlindromic(s.substr(1, s.size() - 2));
    }

}


int main()
{
    string s;
    getline(cin, s);

    int sz = s.size();
    int maxLength = 0;
    string maxSymmetric;
    for (int i = 0; i < sz; ++i)
    {
        for (int j = i; j < sz; ++j)
        {
            string ss = s.substr(i, j - i + 1);
            if (ss.size() > maxLength && isPanlindromic(ss))
            {
                maxLength = ss.size();
                maxSymmetric = ss;
            }
        }
    }

    cout << maxLength << endl;
    //cout << maxSymmetric << endl;
    return 0;
}
