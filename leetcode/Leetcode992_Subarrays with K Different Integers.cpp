#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

void addElem(map<int, int>& cnt, int elem) {
    if (cnt.find(elem) == cnt.end()) {
        cnt[elem] = 1;
    }
    else {
        cnt[elem] += 1;
    }
}

void removeElem(map<int, int>& cnt, int elem) {
    if (cnt[elem] >= 2) {
        cnt[elem] -= 1;
    }
    else if (cnt[elem] == 1) {
        cnt.erase(elem);
    }
}


// 滑动窗口经典问题， 参考别人的做法解决
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = (int)nums.size();
    
    map<int, int> cnt;
    int ans = 0;

    int i = 0;
    int j = 0;
    while (j <  n) {
        // 如果窗口内的字符不满足要求，右侧扩大窗口
        while (cnt.size() < k && j < n) {
            addElem(cnt, nums[j]);
            j++;
        }
        if (cnt.size() < k && j >= n) break;

        int prefix = 0;
        while (cnt.size() == k) {
            // 如果窗口满足要求，则固定右侧j，不断移动左侧i，
            // 每移动一次，构成的[i,j]区间均满足要求；直到左侧窗口到达边界位置
            while (cnt.size() == k && cnt[nums[i]] > 1) {
                prefix++;
                removeElem(cnt, nums[i]);
                i++;
            }
            ans += prefix + 1;

            if (j >= n) break;
            // 如果右侧下一个字符，已经是新字符，则需要构建新的窗口
            // 缩进左侧窗口一个位置
            if (cnt.find(nums[j]) == cnt.end()) {
                removeElem(cnt, nums[i]);
                i++;
            } else {
                // 如果右侧下一个位置字符出现在窗口内，则继续满足要求
                // 扩大右侧窗口一个位置
                addElem(cnt, nums[j]);
                j++;
            }

        }
    }
    return ans;
}

int main() {
    vector<int> v = { 1,2,1,2,3 };
    int k = 2;
    int ans = subarraysWithKDistinct(v, k);
    cout << ans << endl;
    return 0;
}