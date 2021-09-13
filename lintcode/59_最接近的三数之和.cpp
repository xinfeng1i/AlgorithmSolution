//
//  59_最接近的三数之和.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/21.
//

#include<cmath>
#include<cstdio>
#include<climits>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

/*
 * Method1: Naive Algorithm
 * Time: O(n^3)
 */
int threeSumClosest(vector<int> &numbers, int target) {
    int result = -1;
    int minDiff = INT_MAX;
    
    int n = (int) numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int cur_sum = numbers[i] + numbers[j] + numbers[k];
                int cur_diff = abs(cur_sum - target);
                if (cur_diff < minDiff) {
                    minDiff = cur_diff;
                    result = cur_sum;
                }
            }
        }
    }
    
    return result;
}

/*
 * 给定有序数据，两个数最接近的两数之和
 */
pair<int, int> twoSumClosest(vector<int>& sortedNumbers, int left, int right, int target) {
    int minDiff = INT_MAX;
    int result = -1;
    
    int i = left;
    int j = right;
    while (i < j) {
        int curSum = sortedNumbers[i] + sortedNumbers[j];
        if (curSum > target) {
            int curDiff = curSum - target;
            if (curDiff < minDiff) {
                minDiff = curDiff;
                result = curSum;
            }
            j--;
        } else {
            int curDiff = target - curSum;
            if (curDiff < minDiff) {
                minDiff = curDiff;
                result = curSum;
            }
            i++;
        }
    }
    return make_pair(minDiff, result);
}

/*
 * Method2: 先排序 O(nlogn)，将最接近的 3 数之和转换为最接近的 2 数之和
 * Time: O(n^2)
 * Space: O(1)
 */
int threeSumClosest2(vector<int> &numbers, int target) {
    sort(numbers.begin(), numbers.end());
    
    int minDiff = INT_MAX;
    int finalSum = -1;
    
    int n = (int) numbers.size();
    for (int i = 0; i < n; ++i) {
        int a = numbers[i];
        pair<int, int> temp = twoSumClosest(numbers, i + 1, n - 1, target - a);
        if (temp.first < minDiff) {
            minDiff = temp.first;
            finalSum = temp.second + a;
        }
    }
    
    return finalSum;
}


int main() {
    printf("hello world!\n");
    return 0;
}
