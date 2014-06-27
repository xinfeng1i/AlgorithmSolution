#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

// Select sort
// Every time we choose the minimum element from the unsorted part of array
// add it to the sorted part

// LOOP INVRIANT: a[-, i) is sorted
//                INIT: a[-, 0) is sorted
//                KEEP: every time we add a element to the sorted part
//                LAST: i == n, so a[-, n) is sorted

// Time Complexity: O(n^2)
void selectSort(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[minIndex]) minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i) printf(" %d", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a) / sizeof(a[0]);
   
    printf("Before Sort\n");
    printArray(a, n);

    selectSort(a, n);

    printf("After Sort\n");
    printArray(a, n);

    return 0;
}
