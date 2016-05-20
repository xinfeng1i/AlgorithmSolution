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
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    // write your code here
    if (strs.empty()) return "";
        
    size_t min_sz = strs[0].size();
    for (size_t i = 1; i < strs.size(); ++i) {
        min_sz = min(min_sz, strs[i].size());
    }
        
    // found empty string
    if (min_sz == 0) return "";
        
    int pos;
    for (pos = 0; pos < min_sz; ) {
        bool all_equal = true;
        int ch = strs[0][pos];
        for (size_t i = 1; i < strs.size(); ++i) {
            if (strs[i][pos] == ch) {
                continue;
            } else {
                all_equal = false;
                break;
            }
        }
            
        if (all_equal) pos++;
        else break;
    }
        
    int max_pos = pos - 1;
        
    if (max_pos < 0) return "";
    else return strs[0].substr(0, max_pos+1);
        
}
