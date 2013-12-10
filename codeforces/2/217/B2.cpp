#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// a is a subsequence of b ?
bool isSubsequence(const vector<int> &a, const vector<int> &b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        // not find
        if (find(b.begin(), b.end(), a[i]) == b.end())
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > cards(n);
    
    int m, tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            cin >> tmp;
            cards[i].push_back(tmp);
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        bool findSubseq = false;
        for (int j = 0; j < n; ++j)
        {
            if (j != i)
            {
                if (isSubsequence(cards[j], cards[i]))
                {
                    findSubseq = true;
                    cout << "NO" << endl;
                    break;
                }
            }
        }
        
        if (!findSubseq)
        {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}

// Summary:
// The key of the problem is that judge whether a is subsequence of
// b, then original method using poniter and while loop, it is easy 
// to find bugs, the new method using STL and for loop, it is more
// clear and decent.
// Lessons: Using STL.
