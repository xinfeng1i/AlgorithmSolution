#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// suppose height[i] < height[j]
// since we have checked (i,j) area, then (i, i+1...j-1) area
// must be no more than (i,j) area, there is no need to check them
// then we only need check(i+1, j) area
// Loop Invariant: maxArea lies in the interval [i, j];
int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0; int j = n - 1;
    
    int maxArea = 0;
    while (i < j) {
        maxArea = max(maxArea, (j - i) * min(height[i], height[j]));
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return maxArea;
}