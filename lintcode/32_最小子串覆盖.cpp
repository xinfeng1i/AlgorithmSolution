#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;


/*
 * Method1: 滑动窗口问题
 * 1. 移动右指针找到满足条件的数组
 * 2. 移动左指针缩小窗口范围，找到最小的数组
 * 
 * 时间复杂度：
 * 空间复杂度：O(C)，其中 C 为字符集大小
 */
string minWindow(string& source, string& target) {
    if (target == "") return "";
    if (source == "") return "";
    if (source.size() < target.size()) return "";

    int n = (int)source.size();
    int m = (int)target.size();

    map<char, int> tmap;
    for (char ch : target) {
        if (tmap.find(ch) == tmap.end()) {
            tmap[ch] = 1;
        } else {
            tmap[ch] += 1;
        }
    }

    int matchCnt = 0;
    int minLength = INT_MAX;
    string ans = "";

    int i = 0;
    int j = 0;
    while (i < n) {
        /* 当前匹配字符数小于预期，不断移动右侧指针扩大范围 */
        while (j < n && matchCnt < m) {
            if (tmap.find(source[j]) != tmap.end()) {
                if (tmap[source[j]] >= 1) { matchCnt++; }
                tmap[source[j]]--;
            }
            j++;
        }

        /* 更新找到的 answer */
        if (matchCnt >= m) {
            int curLength = j - i;
            if (curLength < minLength) {
                minLength = curLength;
                ans = source.substr(i, curLength);
            }
        }

        /* 移动左指针缩小窗口范围 */
        if (tmap.find(source[i]) != tmap.end()) {
            if (tmap[source[i]] >= 0) { matchCnt--; }
            tmap[source[i]]++;            
        }
        i++;
    }

    return ans;
}

int main() {
    // string s1 = "adobecodebanc";
    // string s2 = "abc";
    string s1 = "abc";
    string s2 = "aa";

    string ans = minWindow(s1, s2);
    printf("%s\n", ans.c_str());


    return 0;
}