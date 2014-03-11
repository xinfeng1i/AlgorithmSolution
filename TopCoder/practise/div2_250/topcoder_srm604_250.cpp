#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 193 pt
bool isUnusual(string a, string b)
{
    int mink = min(a.size(), b.size());
    for (int k = 1; k < mink; ++k)
    {
        if (a.substr(0, k) == b.substr(b.size() - k) &&
            a.substr(k) == b.substr(0, b.size() - k))
        {
            return true;
        }
    }
    return false;
}
int howManyPairs(vector <string> words)
{
    int cnt = 0; 
    for (int i = 0; i < words.size(); ++i)
    {
        for (int j = i + 1; j < words.size(); ++j)
        {
            if (isUnusual(words[i], words[j]))
            {
                cnt++;
            }
        }
    }

    return cnt;
}

#if 0
int main()
{
    string a, b;
    cin >> a >> b;
    cout << isUnusual(a, b) << endl;
    return 0;
}
#endif // 0