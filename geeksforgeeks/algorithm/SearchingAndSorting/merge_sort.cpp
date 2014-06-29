#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;


// merge the left sorted part and right sorted part of a
void merge(int a[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// copy the two part
	int x[n1]; int y[n2];
	for (int i = 0; i < n1; ++i) x[i] = a[left + i];
	for (int j = 0; j < n2; ++j) y[j] = a[mid + 1 + j];

	// merge if both two parts not emtpy
	int i = 0; int j = 0; int k = left; // NOTENOTE that, k start with left...
	while (i < n1 && j < n2)
	{
		if (x[i] <= y[j]) a[k++] = x[i++];
		else a[k++] = y[j++];
	}

	// if one part is empty;
	while (i < n1) a[k++] = x[i++];
	while (j < n2) a[k++] = y[j++];
}

/***********************************************************
 * merge sort a[left, right]
 * Method: Divide and Conquer
 *
 * Time Complexity: O(nlogn) (Worst, average and best)
 * Space Complexity: O(n);
 *
 * Stable: YES
 ***********************************************************/
void mergeSort(int a[], int left, int right)
{
	if (left >= right) return;

	int mid = (left + right) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid+1, right);
	merge(a, left, mid, right);
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; ++i) printf(" %d", a[i]);
	printf("\n");
}

int main()
{
	int a[] = {8, 5, 9, 6, 7, 3, 1, 12, 10};	
	int n = sizeof(a) / sizeof(a[0]);

	printf("Before sort:\n");
	printArray(a, n);

	mergeSort(a, 0, n-1);


	printf("After sort:\n");
	printArray(a, n);
}
