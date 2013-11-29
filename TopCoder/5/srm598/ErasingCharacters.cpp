#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int TwoSameIndex(string s)
{
    int ans = -1;
    int n = s.size();

    // cannot use size() - 1 directly, because 
    // s.size() int unsigned int, size()-1 will the 
    // the maximum unsigned int
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i+1])
        {
            ans = i;
            break;
        }
    }

    return ans;
}

string simulate(string s)
{
    while (TwoSameIndex(s) != -1)
    {
        int cur = TwoSameIndex(s);
        s.erase(cur, 2);
    }

    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << simulate(s) << endl;

    return 0;
}
