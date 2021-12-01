#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

inline int getMiddle(int left, int right) {
    assert(left <= right);
    return left + (right - left) / 2;
}

inline int getMiddle2(int left, int right) {
    assert(left <= right);
    return left + (right - left + 1) / 2;
}


int findFirstTarget(vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left < right) {
        int mid = getMiddle(left, right);
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            right = mid;
        }
    }

    if (nums[left] == target) return left;
    else return -1;
}

int findLastTarget(vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left < right) {
        int mid = getMiddle2(left, right);
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid;
        }
    }

    if (nums[left] == target) return left;
    else return -1;

}


vector<int> searchRange(vector<int>& nums, int target) {
    int idx1 = findFirstTarget(nums, target);
    int idx2 = findLastTarget(nums, target);

    vector<int> ans;
    ans.push_back(idx1);
    ans.push_back(idx2);

    return ans;
}

#if 0
int main() {
    vector<int> v = { 5,7,7,8,8,10 };
    int t = 8;

    vector<int> ans = searchRange(v, t);
    for (int x : ans) {
        printf("%d\n", x);
    }

    return 0;
}
#endif // 0