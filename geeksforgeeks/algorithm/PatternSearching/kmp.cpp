#include <iostream>
#include <vector>
#include <string>
using namespace std;

// lps[i] = the longest proper prefix of pat[0...i] which is also 
//          the suffix of pat[0...i]
// the algorithm is computed in the bottom to up
// specificilly speaking,
// if we have got lps[i-1] = len, in the next pos i, 
// we just compare pat[i] and pat[len]
//    if they are equal, then the len++, and lps[i] = len, i++;
//    else if they are not equal, the divide it into smaller subproblem
//    In this case, we want find if the pat[...i] can match pat[0...len-1]
//    the condition is that the suffix of pat[...i] can match pat[0...len-1]
//    maximally, so we notice that it was nothing but the longest proper
//    prefix of pat[0...len-1] which is also the suffix of pat[0...len-1],
//    so we update len = lps[len-1], but we not step forward i
//    if len == 0, so lps[-1] is not acceptable, so we consider it as a
//    special situation, when len == 0, lps[i] = 0; i++;
vector<int> PreKMP(string pat)
{
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0;
    lps[0] = 0;     // lps[i] = long prefix suffix of pat[0...i]

    int i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // pat[i] != pat[len]
        {
            if (len > 0)
            {
                len = lps[len-1];
            }
            else if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMPSearch(string pat, string txt)
{
    int n = txt.size();
    int m = pat.size();
    vector<int> lps = PreKMP(pat);

    int i = 0; 
    int j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
            if (j == m)
            {
                cout << "Found Pattern at index " << i - j << endl;
                j = lps[j-1];
            }
        }
        else // txt[i] != pat[j]
        {
            if (j > 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    cout << "Enter text:" << endl;
    string txt;
    cin >> txt;

    cout << "Enter Pattern:" << endl;
    string pat;
    cin >> pat;
    KMPSearch(pat, txt);

    return 0;
}
