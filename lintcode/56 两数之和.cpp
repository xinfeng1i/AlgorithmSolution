#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
 * @param numbers : An array of Integer
 * @param target : target = numbers[index1] + numbers[index2]
 * @return : [index1+1, index2+1] (index1 < index2)
 */
vector<int> twoSum(vector<int> &A, int target) {
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = i +1; j < A.size(); ++j) {
            if (A[i] + A[j] == target) {
                vector<int> ans(2, 0);
                ans[0] = i + 1;
                ans[1] = j + 1;
                return ans;
            }
        }
    }
}
