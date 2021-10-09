//
//  328_字符串划分.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/10/9.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;


/*
 * Method: 哈希表+贪心算法
 *
 * 记录每个字母最后一次出现的位置 index，然后贪心遍历，不断扩张 rightmost
 *
 * 时间复杂度：O(n)
 * 空间复杂度: O(C)，C表示字母表大小
 */
vector<int> splitString(string &s) {
    vector<int> ans;
    if (s.empty()) return ans;
    if (s.size() == 1) { ans.push_back(1); return ans; }
    
    // 记录每个字母最后一次出现的index
    unordered_map<char, int> m;
    
    int n = (int) s.size();
    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        if (m.find(ch) == m.end()) {
            m[ch] = i;
        } else {
            int lastOccur = max(i, m[ch]);
            m[ch] = lastOccur;
        }
    }
    
    
    char ch = s[0];
    int leftMost = 0;
    int rightMost = m[ch];
    int i = 0;
    while (i < n) {
        while (i < rightMost) {
            ch = s[i];
            rightMost = max(m[ch], rightMost);
            i++;
        }
        
        if (i >= rightMost) {
            int curLength = rightMost - leftMost + 1;
            ans.push_back(curLength);
        }
        
        i += 1;
        leftMost = i;
        rightMost = m[s[i]];
    }
    
    return ans;
}

#if 0
int main() {
    //string s = "mpmpcpmcmdefegdehinhklin";
    string s = "ab";
    
    vector<int> ans = splitString(s);
    for (int x: ans) {
        printf("%d ", x);
    }
    printf("\n");
    
    return 0;
}
#endif // 0
