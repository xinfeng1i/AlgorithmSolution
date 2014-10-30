#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> ComputeLPSArray(string pat)
{
    int m = pat.size();

    vector<int> lps(m, 0);
    lps[0] = 0;
    int len = 0;
    for (int i  = 1; i < m; ++i)
    {
        while (len - 1 >= 0 && pat[i] != pat[len])
        {
            len = pat[len-1];
        }
        if (pat[i] == pat[len])
        {
            len++;
        }
        pat[i] = len;
    }
    return lps;
}

void KMP(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    vector<int> lps = ComputeLPSArray(pat);

    int len = 0;
    for (int i = 0; i < n; ++i)
    {
        while (len - 1 >= 0 && txt[i] != pat[len])
        {
            len = pat[len-1];
        }
        if (txt[i] == pat[len])
        {
            len++;
        }

        if (len == m)
        {
            cout << "Pattern Found at Index:" << i -m + 1 << endl;
            len = pat[len-1];
        }
    }
    return;
}

int main()
{
    string txt, pat;
    cin >> txt >> pat;
    KMP(txt, pat);
    return 0;
}
