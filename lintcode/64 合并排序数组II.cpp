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
 * @param A: sorted integer array A which has m elements,
 *           but size of A is m+n
 * @param B: sorted integer array B which has n elements
 * @return: void
 */
void mergeSortedArray(int A[], int m, int B[], int n) {
    if (m < 0 || n < 0) return;

    // base case: one array is empty
    if (n == 0) return;
    if (m == 0) {
        for (int i = 0; i < n; ++i) {
            A[i] = B[i];
        }
        return;
    }

    // move all the elements of A to the right aligned
    for (int i = m - 1; i >= 0; --i) {
        A[i+n] = A[i];
    }

    int pos = 0;
    int i = n, j = 0;
    while (i < m+n && j < n) {
        if (A[i] <= B[j]) {
            A[pos] = A[i];
            pos++;
            i++;
        } else {
            A[pos] = B[j];
            pos++;
            j++;
        }
    }

    if (i >= m + n) {
        for (int k = j; k < n; ++k) {
            A[pos] = B[k];
            pos++;

        }
    }

    if (j >= n) {
        for (int k = i; k < m+n; ++k) {
            A[pos] = A[k];
            pos++;
        }
    }

    return;

}
