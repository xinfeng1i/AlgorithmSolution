#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

void PrintVector(const vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    }
    cout << endl;
}

// This function comes from Introduction to Algorithm
// it's more elegant
// 
vector<int> ComputePrefixSuffixArray(string pat)
{
    int m = pat.size();
    vector<int> lps(m, 0); // lps = longest prefix suffix

    int k = -1;
    lps[0] = -1;
    for (int i = 1; i < m; ++i)
    {
        while (k >= 0 && pat[k+1] != pat[i]) k = lps[k];
        if (pat[k+1] == pat[i]) k += 1;
        lps[i] = k;
    }
    
    return lps;
}

void KMP(string pat, string txt)
{
    int n = txt.size();
    int m = pat.size();

    vector<int> lps = ComputePrefixSuffixArray(pat);

    int j = -1;
    for (int i = 0; i < n; ++i)
    {
        // next character does not match
        while (j >= 0 && pat[j+1] != txt[i]) j = lps[j];
        // next character match
        if (pat[j+1] == txt[i]) j += 1;
        // is all of P matched ?
        if (j == m-1) {cout << "Pattern at " << i - (m-1) << "\n"; j = lps[j];}
    }
}

int main()
{
    cout << "Enter text:" << endl;
    string txt;
    cin >> txt;

    cout << "Enter pattern:" << endl;
    string pat;
    cin >> pat;
    
    KMP(pat, txt);
    return 0;
}

