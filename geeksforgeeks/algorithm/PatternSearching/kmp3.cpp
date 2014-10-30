#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computeLPSArray(string pat)
{
    int m = pat.size();
    vector<int> lps(m, 0);

    lps[0] = 0;     // lps[i] store the longest length of max prefix and suffix till i
    int len = 0;    // current has been matched length
    for (int i = 1; i < m; ++i)
    {
        while (len-1 >= 0 && pat[i] != pat[len])
        {
            len = lps[len-1];
        }
        if (pat[i] == pat[len])
        {
            len += 1;
        }
        lps[i] = len;
    }

    return lps;
}

void KMP(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    vector<int> lps = computeLPSArray(pat);

    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j - 1 >= 0 && txt[i] != pat[j])
        {
            j = lps[j-1]; 
        }
        if (txt[i] == pat[j])
        {
            j += 1;
        }

        if (j == m)
        {
            cout << "Pattern Find At Index:" << i-m+1 << endl;
            j = lps[j-1];   // slide to next match
        }
    }
}

int main()
{
    string txt;
    string pat;
    cin >> txt;
    cin >> pat;
    KMP(txt, pat);
    return 0;
}
