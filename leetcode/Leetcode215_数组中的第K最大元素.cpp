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


int findKthSmall(vector<int>& nums, int left, int right, int k) {
    int pivot = nums[left];
    int i = left;
    for (int j = left + 1; j <= right; ++j) {
        if (nums[j] <= pivot) {
            swap(nums[j], nums[i + 1]);
            i++;
        }
    }
    swap(nums[i], nums[left]);

    int leftCnt = i - left;
    if (leftCnt == k - 1) {
        return nums[i];
    }
    else if (leftCnt > k - 1) {
        return findKthSmall(nums, left, i - 1, k);
    }
    else {
        return findKthSmall(nums, i + 1, right, k - leftCnt - 1);
    }

}

int findKthLargest(vector<int>& nums, int k) {
    int n = (int)nums.size();
    int rank = n + 1 - k;
    return findKthSmall(nums, 0, n - 1, rank);
}


int main() {
    vector<int> v = { 3,2,1,5,6,4 };
    cout << findKthLargest(v, 6) << endl;
    return 0;
}