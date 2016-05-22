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
 * @param numbers: Give an array numbers of n integer
 * @param target: An integer
 * @return: return the sum of the three integers, the sum closest target.
 */
int threeSumClosest(vector<int> A, int target) {
    int n = (int)A.size();

    int min_diff = INT_MAX;
    int closest_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int cur_sum = A[i] + A[j] + A[k];
                if (abs(cur_sum - target) < min_diff) {
                    min_diff = abs(cur_sum - target);
                    closest_sum = cur_sum;
                }
            }
        }
    }

    return closest_sum;
}
