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

/**
 * @param nums: A list of integers
 * @return: A list of integers includes the index of the first number
 *          and the index of the last number
 */
vector<int> subarraySum(vector<int> A) {
    int n = (int)A.size();
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += A[j];
            if (sum == 0) {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
}
