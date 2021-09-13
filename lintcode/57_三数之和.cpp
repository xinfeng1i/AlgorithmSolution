//
//  57_三数之和.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/17.
//

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

/*
 * @param numbers: Give an array numbers of n integer
 * @return: Find all unique triplets in the array which gives the sum of zero.
 *
 * Method1: Naive Algorithm, passed.
 * Time: O(n^3)
 */
vector<vector<int>> threeSum(vector<int> &numbers) {
    set<vector<int>> s;
    
    size_t n = numbers.size();
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            for (size_t k = j + 1; k < n; ++k) {
                if (numbers[i] + numbers[j] + numbers[k] == 0) {
                    vector<int> temp;
                    temp.push_back(numbers[i]);
                    temp.push_back(numbers[j]);
                    temp.push_back(numbers[k]);
                    sort(temp.begin(), temp.end());
                    
                    s.insert(temp);
                }
            }
        }
    }
    
    vector<vector<int>> result;
    for (auto it = s.begin(); it != s.end(); ++it) {
        result.push_back(*it);
    }
    return result;
}

/*
 * Find all two numbers (a, b), such that a + b == target.
 * Time: O(n)
 */
vector<pair<int, int>> twoSumSubFunction(vector<int>& sortedNumbers,
                                         int left, int right, int target) {
    vector<pair<int, int>> result;
    
    if (left >= right) {
        return result;
    }
    
    int i = left;
    int j = right;
    while (i < j) {
        if (sortedNumbers[i] + sortedNumbers[j] < target) {
            i++;
        } else if (sortedNumbers[i] + sortedNumbers[j] > target) {
            j--;
        } else {
            pair<int, int> temp = make_pair(sortedNumbers[i], sortedNumbers[j]);
            result.push_back(temp);
            i++;
            j--;
        }
    }
    
    return result;
}

/*
 * Method2: Reduce the three sum -> two sum problem, passed.
 *
 * Time: O(nlogn) + O(n^2) = O(n^2)
 */
vector<vector<int>> threeSum2(vector<int> &numbers) {
    // O(nlogn)
    sort(numbers.begin(), numbers.end());
    
    set<vector<int>> s;
    int n = (int) numbers.size();
    for (int i = 0; i < n; ++i) {
        int a = numbers[i];
        vector<pair<int, int>> pairList = twoSumSubFunction(numbers, i+1, n-1, -a);
        
        if (pairList.empty()) {
            continue;
        }
        for (pair<int, int> p: pairList) {
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(p.first);
            temp.push_back(p.second);
            
            sort(temp.begin(), temp.end());
            s.insert(temp);
        }
    }
    
    vector<vector<int>> result(s.begin(), s.end());
    return result;
}


void printResult(const vector<vector<int>>& v) {
    if (v.empty()) {
        printf("Empty!\n");
        return;
    }
    
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v[i].size(); ++j) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

void test_1() {
    // vector<int> nums = {2,7,11,15};
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum2(nums);
    printResult(result);
}

int main() {
    test_1();
    return 0;
}
