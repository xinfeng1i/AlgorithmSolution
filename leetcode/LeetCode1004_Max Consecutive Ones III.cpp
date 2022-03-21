#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


int longestOnes_Imp1(vector<int>& nums, int k) {
    int cnt = 0;
    int n = (int)nums.size();

    int i = 0;
    int j = 0;
    int ans = 0;
    while (true) {
        while (j < n && cnt < k) {
            if (nums[j] == 0) cnt++; 
            j++;        
        }
        if (j >= n && cnt < k) {
            ans = max(ans, j - i);
        }
 
        while (j < n && nums[j] == 1) j++;
        ans = max(ans, j - i);

        while (i < n && nums[i] == 1) i++;
        if (i >= n) break;
        cnt--; i++;      
    }

/*
    
    */
    return ans;
}



int longestOnes(vector<int>& nums, int k) {
    int cnt = 0;
    int n = (int)nums.size();

    int i = 0;
    int j = 0;
    int ans = 0;
    for (int j = 0; j < n; ++j) {
        if (cnt <= k) {
            if (nums[j] == 0) cnt++;
        }

        while (cnt > k) {
            if (nums[i] == 0) cnt--;
            i++;
        }

        ans = max(ans, j - i + 1);
    }
    return ans;
}




int main() {
    vector<int> v1 = { 1,1,1,0,0,0,1,1,1,1,0 };
    int k1 = 2;

    vector<int> v2 = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    int k2 = 3;

    vector<int> v3 = { 0,0,0,0 };
    int k3 = 0;

    cout << longestOnes(v1, k1) << endl;
    cout << longestOnes(v2, k2) << endl;
    cout << longestOnes(v3, k3) << endl;
    return 0;
}