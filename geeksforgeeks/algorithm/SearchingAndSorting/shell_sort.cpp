#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*
 * shell sort: a variation of insertion sort
 * time complexity: O(n^2)
 */
void shellSort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        
        // insert x in [gap, n) into [0,gap-1]
        for (int i = gap; i < n; ++i)
        {
            // insert sort in local array [0, gap, 2*gap, 3*gap, ...]
            int tmp = a[i]; int j;
            for (j = i; j - gap >= 0 && a[j-gap] > tmp; j -= gap)
            {
                a[j] = a[j-gap];
            }

            a[j] = tmp;
        }
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i) printf(" %d", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {6, 4, 9, 7, 2, 10, 1};
    int n = sizeof(a) / sizeof(a[0]);

    printf("before sort\n");
    printArray(a, n);

    shellSort(a, n);

    printf("after sort\n");
    printArray(a, n);

    return 0;
}
