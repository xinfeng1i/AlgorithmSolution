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



// 定义dp[i] = [i, n-1]后缀有多少种解码方式，则
// dp[i-1] = dp[i+1] + dp[i] ,如果(i,i+1)能构成一个字符
// dp[i-1] = dp[i+1] , 否则
int numDecodings(string s) {
    // base case: 0 or 1 length
    if (s.empty()) return 0;
    if (s.size() == 1) {
        if (s[0] != '0') return 1;
        else return 0;
    }
        
    int n = (int)s.size();
    vector<int> dp(n, 0);
        
    if (s[n-1] == '0') dp[n-1] = 0;
    else dp[n-1] = 1;
        
    for (int i = n-2; i >= 0; --i) {
        if (s[i] == '0') {
            dp[i] = 0;
            continue;
        }
            
        int num = (s[i]-'0') * 10 + (s[i+1]-'0');
        if (num <= 26) {
            if (i+2 < n) dp[i] = dp[i+2]+dp[i+1];
            else dp[i] = dp[i+1] + 1;
        } else {
            dp[i] = dp[i+1];
        }
    }
        
    return dp[0];
}