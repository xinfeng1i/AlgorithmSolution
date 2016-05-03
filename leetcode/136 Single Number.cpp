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
using namespace std;

int singleNumber(vector<int>& nums) {
	int ans = 0;
	for (size_t i = 0; i < nums.size(); ++i) {
		ans ^= nums[i];
	}
	return ans;
}