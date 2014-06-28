#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

// sort the element a[left, right];
// Loop Invariant: all [..., i] < pivot, (i,...) to be sorted
//                 all [j, ...] > pivot, (...,j) to be sorted
//
//                 Init: i = left; j = right + 1; statisfy;
//                 Keep: after each loop, (..., i] < pivot, [j,...) > pivot
//                 Loop end: ? 
void quickSort(int a[], int left, int right)
{
    // base case
    if (left >= right) return;

    int i = left; int j = right + 1;
    int pivot = a[left];

    // loop invariant: [..., i] < pivot; [j, ...] > pivot
    while (i < j)
    {
        do{i++;}while(a[i] <= pivot); 
        do{j--;}while(a[j] > pivot);
        if (i < j) swap(a[i], a[j]);
    }

    swap(a[left], a[j]);

    quickSort(a, left, j - 1);
    quickSort(a, j + 1, right);
}

int main()
{
    // test for activity problem

    int a[] = {1, 3, 2, 5, 7, 6};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before QuickSort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    quickSort(a, 0, n - 1);

    printf("After QuickSort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    return 0;
}

