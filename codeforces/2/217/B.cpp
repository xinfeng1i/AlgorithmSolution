#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

// judge a is a subsequece of b
bool isSubSequence(const vector<int>&a, const vector<int>& b)
{
    if (a.size() > b.size())
    {
        return false;
    }

    int pa = 0;
    int pb = 0;
    while (pa < a.size() && pb < b.size())
    {
        // until ==, or exceed the index
        while (pb < b.size() && b[pb] != a[pa])
        {
            pb++;
        }

        // exceed pb but not exceed pa, then not the same
        if (pb >= b.size() && pa < a.size())
        {
            return false;
        }
        else
        {
            pb++;
            pa++;
        }
    }

    // if all elems of a have been matched, then same
    if (pa >= a.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<vector<int> > cards(n);

    int m;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        for (int k = 0; k < m; ++k)
        {
            cin >> tmp;
            cards[i].push_back(tmp);
        }

        // need sort the array to avoid like:
        // 3 5
        // 5 3
        // is not considered the same
        sort(cards[i].begin(), cards[i].end());
    }

    for (int i = 0; i < n; ++i)
    {
        bool sameWithOther = false;
        for (int j = 0; j < n; ++j)
        {
            if (j != i)
            {
                if (isSubSequence(cards[j], cards[i]))
                {
                    sameWithOther = true;
                    cout << "NO" << endl;
                    break;
                }
            }
        }

        if (!sameWithOther)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
