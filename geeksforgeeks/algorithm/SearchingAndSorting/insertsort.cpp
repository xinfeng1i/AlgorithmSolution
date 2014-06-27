#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_ELEMENTS 100

// Insert Sort Algorithm
// Basic Idea: assume that the array a[...,i] is already sorted,
// every time, we have a elem j, find a suitable position to insert the j
// Init: a[0] is already sorted
// Loop Invariant: a[0, j) is sorted
//      Init: a[0, 1) is already sorted
//      keep: a[0, j) is sorted, then a[0, j+1) is sorted
//      After:a[0, n) is sorted.
// Time Complexity: O(n^2)
// Author: python27
// Date:   2014/06/26

void InsertSort(int a[], int n)
{
    int i, j, k;
    for (j = 1; j < n; ++j)
    {
        int elem = a[j];
        for (i = 0; i < j; ++i)
        {
            if (a[i] > elem) break;
        }

        for (k = j - 1; k >= i; --k)
        {
            a[k+1] = a[k];
        }
        
        a[i] = elem;
    }
}

int main()
{
    int a[] = {1, 4, 5, 3, 8, 2};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before Sort: \n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    InsertSort(a, n);

    printf("After Sort: \n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
