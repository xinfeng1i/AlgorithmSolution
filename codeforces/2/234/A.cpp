#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

int NumberOfOptions(string s, vector<int>& ans_a)
{
    int ans = 0;
    for (int a = 1; a <= 12; ++a)
    {
        if (12 % a == 0)
        {
            int b = 12 / a;
            bool flag = false;
            for (int j = 0; j < b; ++j)
            {
                set<char> tmp;
                for (int i = j; i < 12; i += b)
                {
                    tmp.insert(s[i]); 
                }

                if (tmp.size() == 1 && tmp.count('X') == 1)
                {
                    flag = true;
                    break;
                }
            }

            if (flag == true)
            {
                ans++;
                ans_a.push_back(a);
            }
        }
    }

    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    string input;
    for (int i = 0; i < t;++i)
    {
        cin >> input;
        int ans = 0;
        vector<int> ans_a;

        ans = NumberOfOptions(input, ans_a);
        
        cout << ans;
        for (int i = 0; i < ans_a.size(); ++i)
        {
            cout << " " << ans_a[i] << "x" << 12 / ans_a[i];
        }
        cout << endl;
    }
    return 0;
}
