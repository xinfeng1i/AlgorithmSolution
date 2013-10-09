#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<int> myhash(256, 1);

    // int myhash[256] = {1}; 
    // WRONG. G++ not support such initialize

    for (size_t j = 0; j < s2.size(); ++j)
    {
        myhash[s2[j]] = 0;
    }

    string ans("");
    for (size_t i = 0; i < s1.size(); ++i)
    {
        if (myhash[s1[i]] != 0)
        {
            ans += s1[i];
        }
    }
    cout << ans << endl;

    // usual algorithm
#if 0
    for (size_t i = 0; i < s1.size(); ++i)
    {
        bool flag = true;
        for (size_t j = 0; j < s2.size(); ++j)
        {
            if (s1[i] == s2[j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ans += s1[i];
        }
    }

    cout << ans << endl;
#endif

    return 0;
}


// Summay:
// Why use hash ?
// if we compare each to each, we have to compare all, In fact, 
// we don't care about if the letter is equal to the other, only care 
// if the letter is in that string. compare each letter to s2 cost 
// Time O(size(s2))
//
// the strength of hash is you give me a letter, I can tell you it's 
// state immediately. which cost Time O(1).
// But we have to construct the hash table and also we cost memory
