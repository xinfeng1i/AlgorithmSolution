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
 * O(n) Max palindrome substring for leetcode
 * 
 * ____|________iMirror_______center________i________|_____
 * centerLeft                                   CenterRight
 *
 * Case 1: L[iMirror] < centerRight - i:
 * Case 2: L[iMirror] == centerRight - i && centerRight == MostRightEnd
 * case 3: L[iMirror] == centerRight - i && centerRight < MostRightEnd
 * case 4: L[iMirror] > centerRight - i;
 * 
 * case 1 and 2 not need to expand
 * case 3 and 4 need to expand
 * if expending leading to L[i] + i > centerRight, update center = i
 * 
 * Time Complexity: O(n)
 */

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

string Preprocess(string s)
{
    if (s == "") return "^$";

    string ans = "^";
    for (size_t i = 0; i < s.size(); ++i)
        ans += "#" + s.substr(i, 1);
    ans += "#$";

    return ans;
}

string MaxPalindromeSubstring(string s)
{
    if (s == "") return "";

    string T = Preprocess(s);
    int n = T.size();
    int* L = new int[n];

    L[0] = 0;
    L[1] = 1;
    int center = 1;
    int centerRight = 0;
    int centerLeft = 0;
    int i = 0;
    for (i = 2; i < n - 1; ++i)
    {
        int iMirror = 2 * center - i;
        centerRight = center + L[center];
        centerLeft = center - L[center];
        
        L[i] = centerRight > i ? MIN(L[iMirror], centerRight - i) : 0;

        // expanding
        while (T[i + L[i] + 1] == T[i - L[i] - 1])
            L[i]++;

        if (i + L[i] > centerRight)
        {
            center = i;
        }
    }

    int ansCenter = 0;
    int ansLength = 0;
    for (i = 2; i < n - 1; ++i)
    {
        if (L[i] > ansLength)
        {
            ansCenter = i;
            ansLength = L[i];
        }
    }

    return s.substr((ansCenter - 1 - ansLength) / 2, ansLength);
}
