//
//  Leetcode89_格雷编码.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/3.
//

#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cmath>
using namespace std;

bool isOnebitDiff(int a, int b) {
    int x = a ^ b;
    int cnt = 0;
    while (x) {
        x = x & (x - 1);
        cnt += 1;
    }
    return cnt == 1;
}

bool solveGrayCode(vector<int>& sofar, vector<int>& nums, vector<bool>& visited) {
    // Base Case
    if (sofar.size() == nums.size() + 1) {
        if (isOnebitDiff(sofar[0], sofar.back())) {
            return true;
        }
        return false;
    }
    
    for (size_t i = 0; i < nums.size(); ++i) {
        int lastNum = sofar.back();
        if (!visited[i] && isOnebitDiff(nums[i], lastNum)) {
            // 1. try a choice
            visited[i] = true;
            sofar.push_back(nums[i]);
            
            // 2. check if lead to a solution
            bool ok = solveGrayCode(sofar, nums, visited);
            
            if (ok) {
                return true;
            } else {
                // 3. trackbacking
                visited[i] = false;
                sofar.pop_back();
            }
        }
    }
    return false;
}


/**
 * 方法I：回溯，暴力枚举所有的序列，如果碰到符合要求的格雷序列，则返回。
 * 这种方法时间复杂度过高，会出现超时。
 * 令 N = 2^n，则时间复杂度为：O(N!)
 */
vector<int> grayCode(int n) {
    int maxNum = pow(2, n) - 1;
    vector<int> nums;
    for (int i = 1; i <= maxNum; ++i) {
        nums.push_back(i);
    }
    
    vector<int> sofar;
    sofar.push_back(0);
    
    vector<bool> visited(nums.size(), false);
    bool ok = solveGrayCode(sofar, nums, visited);
    
    if (ok) {
        return sofar;
    } else {
        sofar.clear();
        return sofar;
    }
}

/**
 * 方法II: 原理同方法III，但是自己重现实现，每次重新生成一个ans容器来更新
 */
vector<int> grayCodeII(int n) {
    vector<int> prev = { 0 , 1 };
    if (n == 1) return prev;
    
    vector<int> ans;
    for (int i = 2; i <= n; ++i) {
        vector<int> cur(prev.begin(), prev.end());
        vector<int> temp(prev.rbegin(), prev.rend());
        int highestBitNum = (1 << (i-1));
        for (int x : temp) {
            cur.push_back(x + highestBitNum);
        }
        
        if (i == n) {
            ans.resize(cur.size());
            copy(cur.begin(), cur.end(), ans.begin());
            break;
        }
        
        prev.clear();
        prev.resize(cur.size());
        copy(cur.begin(), cur.end(), prev.begin());
    }
    return ans;
}


/**
 * 方法III: 格雷码的编码规则：
 * G(0) = { 0 }
 * G(n) 的元素个数为 G(n-1) 元素个数的2倍，其中：
 *      G(n) 的前一半元素就是 G(n-1)
 *      G(n) 的后一半元素是 G(n-1) 逆序后在最高位加上1
 * 时间复杂度: N=2^n  O(N)
 */
vector<int> grayCodeIII(int n) {
    vector<int> ans = { 0 };
    for (int i = 1; i <= n; ++i) {
        int highestBitNum = 1 << (i - 1);
        // 逆序枚举每一个元素，将其最高位bit放置为1后，再进行push_back
        int sz = (int) ans.size();
        for (int j = sz - 1; j >= 0; j--) {
            int x = ans[j] + highestBitNum;
            ans.push_back(x);
        }
    }
    
    return ans;
}



int main() {
    int n = 4;
    vector<int> ans = grayCodeIII(n);
    cout << "ans: " << endl;
    for (int x : ans) cout << " " << x;
    cout << endl;
    return 0;
}
