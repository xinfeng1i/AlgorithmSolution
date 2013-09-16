#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cstdio>
#include <algorithm>
using namespace std;

#define EPS 1e-9

int main()
{
    int k1 = 0;
    cin >> k1;
    vector<pair<int, double> > v1(k1);
    for (int i = 0; i < k1; ++i)
    {
        cin >> v1[i].first >> v1[i].second;
    }

    int k2 = 0;
    cin >> k2;
    vector<pair<int, double> > v2(k2);
    for (int i = 0; i < k2; ++i)
    {
        cin >> v2[i].first >> v2[i].second;
    }

    // add v2 some element to v1
    vector<bool> visitedV2(k2, false);
    for (int i = 0; i < k1; ++i)
    {
        for(int j = 0; j < k2; ++j)
        {
            if (!visitedV2[j] && v2[j].first == v1[i].first)
            {
                v1[i].second += v2[j].second;
                visitedV2[j] = true;
            }
        }
    }

    // union remainer elements
    for (int j = 0; j < k2; ++j)
    {
        if (visitedV2[j] == false)
        {
            v1.push_back(v2[j]);
        }
    }

    map<int, double> ans(v1.begin(), v1.end());
    // delete the zeros items;
    for (auto it = ans.begin(); it != ans.end(); )
    {
        if (abs(it->second) < EPS) 
        {
            it = ans.erase(it);
        }
        else
        {
            ++it;
        }
    }

    int ans_sz = ans.size();
    cout << ans_sz;
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
    {
        cout << " " << it->first << " ";
        printf("%0.1f", it->second);
    }
    cout << endl;
    

    return 0;
}

// Bound check:
// 1. Only output non-zero items, so in the end delete the zero items
// 2. Output format, don't split it too deep
