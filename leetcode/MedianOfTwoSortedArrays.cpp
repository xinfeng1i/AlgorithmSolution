#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
        vector<int> ans(m + n, 0);
        merge(A, A + m, B, B + n, ans.begin());
        if ((m + n) % 2 == 1)
        {
            return ans[(m + n - 1) / 2];
        }
        else
        {
            return (ans[(m + n - 2)/2] + ans[(m + n)/2]) / 2.0;
        }
    }
};