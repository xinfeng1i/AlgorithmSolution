#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

#if 0
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int i = 0, j = 0;
    int n1 = s1.size(), n2 = s2.size();

    string ans = "";
    // bound case:
    // i < n1 && j < n2 is not true for case bbbaaa & bbb
    // it will not detect the borken key A, but quit first
    while (i < n1) {
        int ch1 = s1[i];
        if (isalpha(ch1)) ch1 = toupper(ch1);
        int ch2 = s2[j];
        if (isalpha(ch2)) ch2 = toupper(ch2);
        if (ch1 == ch2) {
            i++;
            j++;
        } else {
            if (ans.find(ch1) == -1)
                ans += ch1;
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}
#endif //0
