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
 * @param numbers : Give an array numbers of n integer
 * @return : Find all unique triplets in the array which gives the sum of zero.
 */
vector<vector<int> > threeSum(vector<int> &A) {

    set<vector<int> > s;
    int n = (int)A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (A[i] + A[j] + A[k] == 0) {
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(A[k]);
                    sort(temp.begin(), temp.end());

                    s.insert(temp);
                }
            }
        }
    }

    vector<vector<int> > ans(s.begin(), s.end());
    return ans;
}
