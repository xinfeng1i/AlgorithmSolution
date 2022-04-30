#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = (int)nums.size();
    int ans = 0;

    int i = 0;
    int j = 0;
    int product = 1;
    while (j < n) {
        product *= nums[j];

        // notice the bound condition i <=j, or it will overflow the vector
        while (i <= j && product >= k) {
            product = product / nums[i];
            i++;
        }

        ans += j - i + 1;
        j++;
    }

    return ans;
}


int main() {
    vector<int> v = { 10, 5, 2, 6 };
    cout << numSubarrayProductLessThanK(v, 100) << endl;

    return 0;
}