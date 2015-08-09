#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void PrintVector(const vector<int> array)
{
    for (size_t i = 0; i < array.size(); ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

vector<int> MaxPrefixSuffixArray(string pat)
{
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0;
    lps[0] = 0;

    for (int i = 1; i < m; ++i)
    {
        while (len - 1 >= 0 && pat[i] != pat[len]) len = lps[len-1];
        if (pat[len] == pat[i]) len++;
        lps[i] = len;
    }

    return lps;
}

int KMP(string str, string pat)
{
    int n = str.size();
    int m = pat.size();
    int cnt = 0;

    vector<int> lps = MaxPrefixSuffixArray(pat);
    int len = 0;
    int i = 0;
    for(i = 0; i < n; ++i)
    {
        while (len - 1 >= 0 && str[i] != pat[len]) len = lps[len-1];
        if (str[i] == pat[len]) len++;

        if (len == m)
        {
            cnt++;
            len = lps[len-1];
        }
    }

    return cnt;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    string pat;
    string s;
    int N;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> pat;
        cin >> s;
        int ans = KMP(s, pat);
        cout << ans << endl;
    }
    return 0;
}