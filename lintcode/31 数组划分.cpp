#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;


int partitionArray(vector<int> &nums, int k) {
    // write your code here
        
    // Loop Invariant
    // [0...i] < k; [i+1, j) >= k
    int n = static_cast<int>(nums.size());
    int i = -1;
    for (int j = 0; j < n; ++j) {
        if (nums[j] >= k) {
            continue;
        } else {
            i += 1;
            swap(nums[i], nums[j]);
        }
    }
    
	return i+1;
}