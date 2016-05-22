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
 * @param A and B: sorted integer array A and B.
 * @return: A new sorted integer array
 */
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    int n1 = (int)A.size();
    int n2 = (int)B.size();
    vector<int> ans;

    int i = 0; int j = 0;
    while (i < n1 && j < n2) {
        if (A[i] <= B[j]) {
            ans.push_back(A[i]);
            i++;
        } else {
            ans.push_back(B[j]);
            j++;
        }
    }

    while (i < n1) {
        ans.push_back(A[i]);
        i++;
    }

    while (j < n2) {
        ans.push_back(B[j]);
        j++;
    }

    return ans;
}
