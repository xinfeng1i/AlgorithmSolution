#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
using namespace std;


// 方法一：不断交换直到各司其职，各在其位
int firstMissingPositive(vector<int>& nums) {
    int n = (int)nums.size();

    for (int i = 0; i < n; ++i) {
        if (nums[i] == i + 1) {
            ;
        }
        else if (nums[i] <= 0 || nums[i] >= n) {
            ;
        }
        else {
            while (nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= n) {
                int toIdx = nums[i] - 1;
                // 注意swap这里：如果 toIdx 位置数值相等，则会进入死循环，例如 [1,1]
                if (nums[toIdx] != toIdx + 1) {
                    swap(nums[i], nums[toIdx]);
                }
                else {
                    break;
                }
            }
        }
    }

    int i = 0;
    for (i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            break;
        }
    }

    return i + 1;
}


// 方法二：对于每个元素负数标记该元素的存在性
int firstMissingPositive(vector<int>& nums) {
    int n = (int)nums.size();

    const int VAL = n + 100;
    for (int i = 0; i < n; ++i) {
        if (nums[i] <= 0) {
            nums[i] = VAL;
        }
    }

    for (int i = 0; i < n; ++i) {
        int toIdx = abs(nums[i]) - 1;
        if (toIdx >= 0 && toIdx < n) {
            nums[toIdx] = -1 * abs(nums[toIdx]);
        }
    }

    int i = 0;
    for (i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            break;
        }
    }
    return i + 1;

}