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
 * @param A: a list of integers
 * @return : return an integer
 */
int removeDuplicates(vector<int> &A) {
    // write your code here
    if (A.empty()) return 0;

    int pos = 0;
    for (size_t i = 1; i < A.size(); ++i) {
        if (A[i] != A[i-1]) {
            pos += 1;
            A[pos] = A[i];
        }
    }
    return pos + 1;
}
