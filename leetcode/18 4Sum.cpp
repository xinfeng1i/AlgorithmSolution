#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    
    vector<vector<int> > result;
    int n = nums.size();
    for (int i = 0; i < n - 3; ++i) {
        for (int j = i + 1; j < n - 2; ++j) {
            int twoSumTarget = target - nums[i] - nums[j];
            int front = j + 1;
            int back = n - 1;
            while (front < back) {
                int twoSum = nums[front] + nums[back];
                if (twoSum == twoSumTarget) {
                    vector<int> quadruplets(4, 0);
                    quadruplets[0] = nums[i];
                    quadruplets[1] = nums[j];
                    quadruplets[2] = nums[front];
                    quadruplets[3] = nums[back];
                    result.push_back(quadruplets);
                    while (front < back && nums[back] == quadruplets[3]) back--;
                    while (front < back && nums[front] == quadruplets[2]) front++;
                } else if (twoSum > twoSumTarget) {
                    back--;
                } else {
                    front++;
                }
            }
            while (j < n - 2 && nums[j] == nums[j+1]) j++;
            
        }
        while (i < n - 3 && nums[i] == nums[i+1]) i++;
    }
    return result;
}

void PrintVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main()
{
    int a[] = {1, 0, -1, 0, -2, 2};
    vector<int> nums(a, a + 6);
    vector<vector<int> > result;
    result = fourSum(nums, 0);
    for (size_t i = 0; i < result.size(); ++i) {
        PrintVec(result[i]);
    }
    return 0;
    
}
