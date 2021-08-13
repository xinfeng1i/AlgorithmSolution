//
//  56_两数之和.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/13.
//

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


/* Method 1
 *
 * Navie algorithm:
 * Time: O(n^2), Space: O(1)
 */
vector<int> twoSum(vector<int> &numbers, int target) {
    size_t n = numbers.size();
    int idx1 = -1;
    int idx2 = -1;
    
    bool hasFound = false;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (target == numbers[i] + numbers[j]) {
                idx1 = (int) i;
                idx2 = (int) j;
                hasFound = true;
                break;
            }
        }
        if (hasFound) break;
    }

    vector<int> result;
    if (idx1 >= 0 && idx2 >= 0 && idx1 < idx2) {
        result.push_back(idx1);
        result.push_back(idx2);
    }
    return result;
}

/* Method 2
 *
 * Using Set/Map Container
 * Time: O(n), Space: O(n)
 */
vector<int> twoSum2(vector<int> &numbers, int target) {
    vector<int> result;
    int n = (int) numbers.size();
    
    // mapping: num -> idx
    map<int, vector<int>> num_to_idx;
    for (int i = 0; i < n; ++i) {
        if (num_to_idx.find(numbers[i]) == num_to_idx.end()) {
            vector<int> temp;
            num_to_idx[numbers[i]] = temp;
        }
        num_to_idx[numbers[i]].push_back(i);
    }
    
    // find the want number
    for (int i = 0; i < n; ++i) {
        int y = target - numbers[i];
        if (num_to_idx.find(y) != num_to_idx.end()) {
            vector<int> idxList = num_to_idx[y];
            for (int idx: idxList) {
                if (i < idx) {
                    result.push_back(i);
                    result.push_back(idx);
                    return result;
                }
            }
        }
    }
    
    return result;
}

/* Method 3:
 *
 * Sorting, then two pointer to middle
 * Time: O(nlogn)
 * Space: O(n)
 */
vector<int> twoSum3(vector<int> &numbers, int target) {
    
    // build data structure, O(n) space
    vector<pair<int, int>> numWithIndex;
    int n = (int) numbers.size();
    for (int i = 0; i < n; ++i) {
        numWithIndex.push_back(make_pair(numbers[i], i));
    }
    
    // sort, O(nlogn) time
    sort(numWithIndex.begin(), numWithIndex.end());
    
    // two pointer
    vector<int> result;
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (target == numWithIndex[i].first + numWithIndex[j].first) {
            result.push_back(numWithIndex[i].second);
            result.push_back(numWithIndex[j].second);
            // Notice Here: the first index < the second index
            if (result[0] > result[1]) {
                swap(result[0], result[1]);
            }
            return result;
        } else if (target < numWithIndex[i].first + numWithIndex[j].first) {
            j--;
        } else {
            i++;
        }
    }
    return result;
}

void test1() {
    vector<int> nums;
    nums.push_back(15);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(2);

    int target = 9;

    vector<int> result = twoSum3(nums, target);
    for (size_t i = 0; i < result.size(); ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    test1();
    return 0;
}
