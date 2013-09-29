#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// A more elegant compare algorithm
// link: ppcool.iteye.com/blog.1731427
//
// main idea, test 2 ways of the contration, if a + b smaller
// then a precede b, other wise b precede a

//
// bool compareString(const string& a, const string& b)
// {
//     string s1 = a + b;
//     string s2 = b + a;
//     return s1 < s2;
// }

bool compareString(const string& a, const string& b)
{
    int asz = a.size();
    int bsz = b.size();
    if (asz == bsz)
    {
        return a < b;
    }
    else if (asz < bsz)
    {
        if (a != b.substr(0, asz))
        {
            return a < b.substr(0, asz);
        }
        else
        {
            return compareString(a, b.substr(asz, bsz - asz));
        }
    }
    else
    {
        if (a.substr(0, bsz) != b)
        {
            return a.substr(0, bsz) < b;
        }
        else
        {
            return compareString(a.substr(bsz, asz - bsz), b);
        }
    }
}

int main()
{
    int N = 0;
    cin >> N;
    vector<string> words(N);
    string ans("");
    for (int i = 0; i < N; ++i)
    {
        cin >> words[i];
    }
    sort(words.begin(), words.end(), compareString);
    for (int i = 0; i < N; ++i)
    {
        ans += words[i];
    }

    long k = 0;
    // Be careful: meet 0 continue until meet nonzero
    // but it may never meet the nonzero to the end
    while (ans[k] == '0' && k < ans.size())
    {
        k++;
    }

    // k move to the end of the string, still didn't find the non
    // zero position
    if (k == ans.size())
    {
        cout << "0" << endl;
        return 0;
    }
    cout << ans.substr(k, -1) << endl;
    return 0;
}

// Summary:
// when find the first nonzero element in the stringlist, you ofen use
// while like this:
// *****************************
// *     int k = 0;            *
// *     while (s[k] == '0')   *
// *     {                     *
// *         k++;              *
// *     }                     *
// *****************************
// but this is WRONG !!! when not hit the nonzero char, continuing going 
// until you find it, but it may have the situation that, it never find 
// a nonzero char till the end, so the RIGHT code should like this
// *********************************************
// *     int k = 0;                            *
// *     while (s[k] == '0' && k < s.size())   *
// *     {                                     *
// *         k++;                              *
// *     }                                     *
// *********************************************
// which means, go until you find the nonzero character, or you get the 
// end of the stringlist
