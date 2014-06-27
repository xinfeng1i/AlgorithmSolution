#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

// Assert that a[] is sorted
int binarySearch(int a[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (key == a[mid]) return mid;
        else if (key < a[mid]) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}

int main()
{
    int a[] = {2, 3, 4, 10, 40};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 10;
    int ans = binarySearch(a, 0, n-1, x);
    if (ans == -1) printf("Cannot find the element\n");
    else printf("Find the element at pos %d\n", ans);

    return 0;
}
