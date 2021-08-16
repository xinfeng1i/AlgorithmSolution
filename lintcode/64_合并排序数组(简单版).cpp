//
//  64_合并排序数组(简单版).cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/16.
//

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


/*
 * @param A: sorted integer array A which has m elements, but size of A is m+n
 * @param m: An integer
 * @param B: sorted integer array B which has n elements
 * @param n: An integer
 * @return: nothing
 *
 * Method1: Shift the element to most right, then merge
 * Time: O(m+n)
 */
void mergeSortedArray(int A[], int m, int B[], int n) {
    // invalid input
    if (A == NULL || B == NULL) return;
    
    // at least one input is empty
    if (m == 0) {
        for (int i = 0; i < n; ++i) {
            A[i] = B[i];
        }
        return;
    }
    
    if (n == 0) {
        return;
    }
    
    // normal case
    // s1: move A elements to the most right part
    int k = m + n - 1;
    int i = m - 1;
    while (i >= 0) {
        A[k] = A[i];
        k--;
        i--;
    }
    
    i = n;
    int j = 0;
    int p = 0;
    while (i < m + n && j < n) {
        if (A[i] <= B[j]) {
            A[p] = A[i];
            p++;
            i++;
        } else {
            A[p] = B[j];
            p++;
            j++;
        }
    }
    
    while (j < n) {
        A[p] = B[j];
        p++;
        j++;
    }
    
    return;
}


/*
 * Method2: compare from right to left, move the bigger one to the most right
 * Time Complexity: O(m+n)
 */
void mergeSortedArray2(int A[], int m, int B[], int n) {
    // invalid input
    if (A == NULL || B == NULL) return;
    
    // at least one input is empty
    if (m == 0) {
        for (int i = 0; i < n; ++i) {
            A[i] = B[i];
        }
        return;
    }
    
    if (n == 0) {
        return;
    }
    
    int k = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[k--] = A[i--];
        } else {
            A[k--] = B[j--];
        }
    }
    
    while (j >= 0) {
        A[k--] = B[j--];
    }
    
    return;
}


int main() {
    int A[7] = {0};
    int B[3] = {0};
    
    A[0] = 2;
    A[1] = 8;
    A[2] = 9;
    A[3] = 13;
    
    B[0] = 3;
    B[1] = 5;
    B[2] = 7;
    
    mergeSortedArray2(A, 4, B, 3);
    
    for (int i = 0; i < 7; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}
