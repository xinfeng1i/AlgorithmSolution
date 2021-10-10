//
//  387_最小差.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/10/10.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

/*
 * Method: 两个有序数组Merge变种
 *
 * 时间复杂度：O(nlogn + mlogm)
 * 空间复杂度：O(1)
 */
int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int ans = INT_MAX;
        int m = (int) A.size();
        int n = (int) B.size();
        int i = 0;
        int j = 0;
        int diff = -1;
        while (i < m && j < n) {
            if (A[i] < B[j]) {
                diff = B[j] - A[i];
                if (diff < ans) ans = diff;
                i++;
            } else if (A[i] > B[j]) {
                diff = A[i] - B[j];
                if (diff < ans) ans = diff;
                j++;
            } else {
                diff = 0;
                if (diff < ans) ans = diff;
                i++;
                j++;
            }
        }

        return ans;
}


#if 0
int main() {
    // vector<int> A = {3, 6, 7, 4};
    // vector<int> B = {2, 8, 9, 3};
    
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {7, 6, 5};
    
    int ans = smallestDifference(A, B);
    printf("%d\n", ans);
    
    return 0;
}
#endif // 0
