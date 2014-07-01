#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

/* Bucket Sort
 * When INPUT is uniformly distributed over a range. For Example:
 * Sort a large set of floating numbers which are in range [0.0, 1.0) and 
 * are uniformly distributed across the range
 *
 * Algorithm Step:
 * 1. build n buckets (lists)
 * 2. for very elements, insert a[i] into buckets[n * a[i]]
 * 3. sort every bucket
 * 4. concatenate all the sorted buckets
 */
void bucketSort(double a[], int n)
{ 
    // build buckets
    vector<double> buckets[n];

    // insert elements
    for (int i = 0; i < n; ++i)
    {
        int index = (int)(a[i] * n);
        buckets[index].push_back(a[i]);
    }

    // sort bucket
    for (int i = 0; i < n; ++i)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }
    
    // concatenate buckets
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < buckets[i].size(); ++j)
        {
            a[k++] = buckets[i][j];
        }
    }

    return;
}

void printArray(double a[], int n)
{
    for (int i = 0; i < n; ++i) printf(" %f", a[i]);
    printf("\n");
}


int main()
{
    double a[] = {0.8, 0.3, 0.9, 0.2, 0.6, 0.1, 0.7};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before Sort\n");
    printArray(a, n);

    bucketSort(a, n);

    printf("After Sort\n");
    printArray(a, n);

    return 0;
}
