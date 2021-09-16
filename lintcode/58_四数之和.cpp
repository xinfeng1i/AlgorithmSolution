//
//  58_四数之和.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/9/16.
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


vector<pair<int, int>> twoSumHelper(vector<int> sortedNumbers, int left, int right, int target) {
    vector<pair<int, int>> result;
    
    if (left >= right) {
        return result;
    }
    
    int i = left;
    int j = right;
    while (i < j) {
        int curSum = sortedNumbers[i] + sortedNumbers[j];
        if (curSum < target) {
            i += 1;
        } else if (curSum > target) {
            j -= 1;
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
 * 借助 Two Sum 子函数的帮助，将问题逐渐缩小
 * 时间复杂度：O(n^3)
 * 空间复杂度: O(1)
 */
vector<vector<int>> fourSum(vector<int> &numbers, int target) {
    set<vector<int>> result;
    
    // sorting: O(nlogn)
    sort(numbers.begin(), numbers.end());
    
    // time: O(n^3)
    int n = (int)numbers.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
            int a = numbers[i];
            int b = numbers[j];
            vector<pair<int, int>> lastTwoNumbers = twoSumHelper(numbers, j+1, n-1, target-a-b);
            if (!lastTwoNumbers.empty()) {
                for (auto pair: lastTwoNumbers) {
                    int c = pair.first;
                    int d = pair.second;
                    
                    vector<int> temp;
                    temp.push_back(a);
                    temp.push_back(b);
                    temp.push_back(c);
                    temp.push_back(d);
                    
                    result.insert(temp);
                }
            }
        }
    }
    
    vector<vector<int>> answer(result.begin(), result.end());
    return answer;
}


void printV(vector<int> v) {
    for (int x: v) {
        printf(" %d", x);
    }
    printf("\n");
}

#if 0
int main() {
    //vector<int> numbers = {1,0,-1,0,-2,2};
    //int target = 0;
    
    vector<int> numbers = {2,7,11,15};
    int target = 3;
    
    vector<vector<int>> result = fourSum(numbers, target);
    
    printf("result:\n");
    for (vector<int> v: result) {
        printV(v);
    }
    
    return 0;
}
#endif // 0



