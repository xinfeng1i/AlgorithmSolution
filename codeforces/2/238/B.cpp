#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    string s(n, 'a');

    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    int cnt = 0;

    int newstart = 0;
    while (newstart < n && s[newstart] == '.')
    {
        newstart++;
    }

    if (newstart >= n)
    {
        cout << n << endl;
        return 0;
    }

    int newend = n - 1;
    while (newend >= 0 && s[newend] == '.')
    {
        newend--;
    }

    if (newend < 0)
    {
        cout << n << endl;
        return 0;
    }
    
    if (s[newstart] == 'R')
    {
        cnt += newstart;
    }
    if (s[newend] == 'L')
    {
        cnt += n - (newend + 1);
    }

    for (int i = newstart; i <= newend; ++i)
    {
        if (s[i] == '.')
        {
            int left = i;
            int right = i;
            while (s[left] == '.') left--;
            while (s[right] == '.') right++;

            if (s[left] == 'L' && s[right] == 'R')
            {
                cnt++;
            }
            else if (s[left] == 'R' && s[right] == 'L')
            {
                if ((left + right) % 2 == 0 && (left + right) / 2 == i)
                {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
    
}
