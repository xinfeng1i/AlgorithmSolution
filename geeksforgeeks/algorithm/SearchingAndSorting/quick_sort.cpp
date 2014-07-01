#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

/* This function takes the last element as pivot, place all the elements
 * smaller than the pivot to left of pivot and all greater elements to 
 * right of pivot
 *
 * LOOP INVARIANT: [-, i] <= pivot, [-, j] is to be sorted
 *                 INIT: i = left - 1, j = right - 1, RIGHT
 *                 KEEP: very time we find a smaller element, we i++, swap
 *                       so the [-, i] always <= pivot
 *                 LAST: j = right, all the smaller elements is in [-, i],
 *                       so all [i+1, j] is to be sorted.
 */
int partition(int a[], int left, int right)
{
    assert(left <= right);
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; ++j)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i+1], a[right]);

    return i + 1;
}

/* Time Complexity:
 * T(n) = T(k) + T(n-1-k) + O(n)
 * When the array is already sorted in increasing or decreasing order, the
 * worst case happens
 *
 * Worst Case: T(n) = T(0) + T(n-1) + O(n)             O(n^2)
 * Best Case:  T(n) = 2T(n/2) + O(n)                   O(nlogn)
 * Average Case: T(n) = T(n/9) + T(9n/10) + O(n),      O(nlogn)
 */

void quickSort(int a[], int left, int right)
{
    if (left >= right) return;

    int mid = partition(a, left, right);
    quickSort(a, left, mid - 1);
    quickSort(a, mid + 1, right);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i) printf(" %d", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {8, 3, 9, 2, 6, 1, 7};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before Sort\n");
    printArray(a, n);

    quickSort(a, 0, n-1);

    printf("After Sort\n");
    printArray(a, n);

    return 0;
}

