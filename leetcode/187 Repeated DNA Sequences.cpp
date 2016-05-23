#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    int n = (int) s.size();
        
    unordered_map<string, int> hstb;
    for (int i = 0; i <= n - 10; ++i) {
        string temp = s.substr(i, 10);
        hstb[temp] += 1;
    }
        
    vector<string> ans;
    for (auto it = hstb.begin(); it != hstb.end(); ++it) {
        if (it->second > 1) {
            ans.push_back(it->first);
        }
    }
    return ans;
}