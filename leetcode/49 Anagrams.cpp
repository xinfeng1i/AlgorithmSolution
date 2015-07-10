#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> anagrams(vector<string>& strs)
{
    map<string, vector<string> > table;
    for (size_t i = 0; i < strs.size(); ++i)
    {
        string word = strs[i];
        sort(word.begin(), word.end());
        table[word].push_back(strs[i]);
    }
    
    vector<string> ans;
    map<string, vector<string> >::iterator it;
    for (it = table.begin(); it != table.end(); ++it)
    {
        if (it->second.size() > 1)
        {
            for (vector<string>::iterator i = (it->second).begin(); i != (it->second).end(); ++i)
            {
                ans.push_back(*i);
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> v;
    v.push_back("tea");
    v.push_back("and");
    v.push_back("ate");
    v.push_back("eat");
    v.push_back("dan");
    
    vector<string> ans = anagrams(v);
    for (size_t i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
