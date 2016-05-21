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
 * @param A: Given an integers array A
 * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
 */
vector<long long> productExcludeItself(vector<int> &A) {
    vector<long long> ans(A.size());
    if (A.empty()) return ans;

    int n = (int)A.size();
    vector<long long> prefix(A.begin(), A.end());
    for (size_t i = 1; i < prefix.size(); ++i) {
        prefix[i] = prefix[i-1] * A[i];
    }

    vector<long long> suffix(A.begin(), A.end());
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i+1] * A[i];
    }

    ans.resize(A.size());
    for (int i = 0; i < n; ++i) {
        ans[i] = (i == 0 ? 1 : prefix[i-1]) * (i + 1 >= n? 1: suffix[i+1]);
    }

    return ans;
}
