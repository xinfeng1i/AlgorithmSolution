#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
using namespace std;

/*
 * Max Length Paralindromic Substring
 *
 * for each char at pos i as the middle of palindrome, expand
 * to the low and high end of the string, if the curlow and curhigh
 * char is equal, then it is a palindrome, update the maxlength; util
 * the [curlow, curhigh] is not equal, then we move to next pos of i
 * 
 * As the palindrome may not be odd, for even length paralindrome, we need
 * make [i-1][i] as the middles of the paramindrome, then repeat the above
 * algorithm.
 *
 * Complexity: O(n^2) time and O(1) space.
 */
int LongestPalindromicSubstring(string s)
{
    int n = s.size();
    int maxLength = 1;
    int startwith = 0;

    int low = 0;
    int high = 0;
    for (int i = 0; i < n; ++i)
    {
        low = i - 1;
        high = i + 1;
        // make s[i] as the middle of the odd length paralindrome
        while (low >= 0 && high < n && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                maxLength = high - low + 1;
                startwith = low;
            }
            low--;
            high++;
        }

        low = i - 1;
        high = i;
        // make s[i-1]s[i] as the middles of even length paralindrome
        while (low >= 0 && high < n && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                maxLength = high - low + 1;
                startwith = low;
            }
            low--;
            high++;
        }
    }

    return maxLength;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        int ans = LongestPalindromicSubstring(s);
        cout << ans << endl;
    }
    return 0;
}