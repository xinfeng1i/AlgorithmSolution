#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
    int n1 = haystack.size();
    int n2 = needle.size();

    if (n1 < n2) return -1;

    for (int i = 0; i <= n1 - n2; ++i)
    {
        bool flag = true;
        for (int j = 0; j < n2; ++j)
        {
            if (needle[j] != haystack[i+j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string s1 = "c";
    string s2 = "bc";
    int pos = strStr(s1, s2);
    cout << pos << endl;
    return 0;
}
