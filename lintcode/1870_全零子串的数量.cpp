//
//  1870_全零子串的数量.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/10/9.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;


/*
 * Method: 使用两个指针，统计连续0子串的长度，然后使用数学公式直接计算即可
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
int stringCount(string &str) {
    if (str.empty()) return 0;
    
    long long ans = 0;
    int n = (int) str.size();
    int i = 0;
    while (i < n) {
        while (i < n && str[i] != '0') i++;
        if (i >= n) break;
        
        int j = i;
        while (j < n && str[j] == '0') j++;
        int zeroCnt = j - i;
        ans += ((long long) (zeroCnt + 1) * (long long) zeroCnt) / 2;
        
        i = j;
    }
    
    return (int) ans;
}

#if 0
int main() {
    // string s = "00010011";  // expected: 9
    string s = "010010";  // expected: 5
    int ans = stringCount(s);
    printf("%d\n", ans);
    return 0;
}
#endif // 0
