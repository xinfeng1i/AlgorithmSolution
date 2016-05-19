#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

vector<string> anagrams(vector<string> &strs) {
    // write your code here
    unordered_map<string, int> tb;
    for (size_t i = 0; i < strs.size(); ++i){
        string s = strs[i];
        sort(s.begin(), s.end());
        if (tb.find(s) == tb.end()) {
            tb[s] = 1;
        } else {
            tb[s] += 1;
        }
    }

    vector<string> ans;
    for (size_t i = 0; i < strs.size(); ++i){
        string s = strs[i];
        sort(s.begin(), s.end());
        if (tb[s] > 1) {
            ans.push_back(strs[i]);
        }
    }

    return ans;
}
