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
 * @param A: a vector of integers
 * @return: an integer
 */
int firstMissingPositive(vector<int> A) {
    int n = (int)A.size();
    for (int i = 0; i < n; ++i) {
        if (A[i] <= 0 || A[i] > n) {
            continue;
        } else {
            int x = A[i];
            while (1 <= x && x <= n && A[x-1] != x) {
                int temp = A[x-1];
                A[x-1] = x;
                x = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (A[i] != i + 1) return i+1;
    }

    return n+1;
}
