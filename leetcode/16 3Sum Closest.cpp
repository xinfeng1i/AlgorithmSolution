#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
    int result = 0;
    int minDiff = INT_MAX;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        int twoSumTarget = target - nums[i];
        int front = i + 1;
        int back = n - 1;
        while (front < back) {
            int curSum = nums[front] + nums[back];
            if (curSum == twoSumTarget) {
                return target;
            } else if (curSum > twoSumTarget) {
                if (curSum - twoSumTarget < minDiff) {
                    minDiff = curSum - twoSumTarget;
                    result = curSum + nums[i];
                }
                back--;
            } else {
                if (twoSumTarget - curSum < minDiff) {
                    minDiff = twoSumTarget - curSum;
                    result = curSum + nums[i];
                }
                front++;
            }
        }
    }
    return result;
}

int main()
{
    int a[] = {-1, 2, 1, -4};
    vector<int> nums(a, a + 4);
    int result = threeSumClosest(nums, 2);
    cout << result << endl;
    return 0;
}
