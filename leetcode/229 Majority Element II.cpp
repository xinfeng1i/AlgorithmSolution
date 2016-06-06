#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Variant of Boyer-Moore Majority Vote Algorithm:
// see the link: https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
// also see the paper: http://www.cs.utexas.edu/users/misra/scannedPdf.dir/FindRepeatedElements.pdf
// k-reduced bag t = {}, d = the number of distinct numbers in t
// if x in t, t = x U t
// else if x not in t, t = x U t, d += 1, if (d == k), delete k distinct numbers
vector<int> majorityElement(vector<int>& nums) {
    int candidate1 = 0; int cnt1 = 0;
    int candidate2 = 0; int cnt2 = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        int x = nums[i];
        if (x == candidate1) {
            cnt1++;
        } else if (x == candidate2) {
            cnt2++;
        } else if (cnt1 == 0) {
            candidate1 = x;
            cnt1 = 1;
        } else if (cnt2 == 0) {
            candidate2 = x;
            cnt2 = 1;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1 = 0;
    cnt2 = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == candidate1) {
            cnt1++;
        } else if (nums[i] == candidate2) {
            cnt2++;
        }
    }
    
    vector<int> ans;
    int n = (int) nums.size();
    if (cnt1 > n/3) ans.push_back(candidate1);
    if (cnt2 > n/3) ans.push_back(candidate2);
    return ans;
}

int main()
{
    int a[] = {1, 2, 2, 3, 2, 1, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v(a, a+n);
    majorityElement(v);
    return 0;
}
