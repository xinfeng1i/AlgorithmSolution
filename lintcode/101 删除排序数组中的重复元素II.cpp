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
    if (A.size() <= 2) return A.size();

    int n = (int)A.size();
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 2 < n) {
            if (A[i] != A[i+2]) {
                A[pos] = A[i];
                pos++;
            }
        } else {
            A[pos] = A[i];
            pos++;
        }

    }

    return pos;
}
