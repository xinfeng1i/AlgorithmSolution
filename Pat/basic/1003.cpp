#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool matchPAT(const string& s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!(s[i] == 'P' || s[i] == 'A' || s[i] == 'T'))
        {
            return false;
        }
    }

    size_t first_P = s.find_first_of('P');
    string substr_X = s.substr(0, first_P);
    size_t cnt_A = 0;
    size_t first_A = first_P + 1;
    while (s[first_A] == 'A')
    {
        cnt_A++;
        first_A++;
    }
    if (cnt_A < 1)
    {
        return false;
    }
    string pattern = substr_X;
    pattern += "P";
    for (size_t k = 0; k < cnt_A; k++)
    {
        pattern += "A";
    }
    pattern += "T";
    for (size_t k = 0; k < cnt_A; k++)
    {
        pattern += substr_X;
    }

    if (s == pattern)
    {
        return true;
    }
    else
    {
        return false;
    }

}
int main()
{
    int n;
    cin >> n;

    vector<string> svec;
    svec.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> svec[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        if (matchPAT(svec[i]))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
