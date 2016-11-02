#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int maxArea(vector<int>& height) {
	int n = height.size();
	int l = 0;
	int r = n-1;
	
	int ans = 0;
	while (l < r) {
        int temp = min(height[r], height[l])*(r-l);
	    ans = max(ans, temp);
		if (height[l] <= height[r]) {
			l++;
		} else {
			r--;
		}
	}
	return ans;
}
