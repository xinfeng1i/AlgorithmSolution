#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


// Time complexity: O(logn)
void heapify(int heap[],int n, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	int largest = i;

	// find the largest elem
	if (left < n && heap[left] > heap[largest]) largest = left;
	if (right < n && heap[right] > heap[largest]) largest = right;

	if (largest != i)
	{
		swap(heap[largest], heap[i]);
		heapify(heap, n, largest);
	}
}

// Time complexity: O(n)
void buildHeap(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		heapify(a, n, i);
	}
}


// Time complexity: O(nlogn)
void heapSort(int a[], int n)
{
	buildHeap(a, n);

	int last = n - 1;
	while (last >= 0)
	{
		swap(a[0], a[last]);
		last--;
		heapify(a, last + 1, 0);
	}

}

int main()
{
	int a[] = {8, 3, 9, 6, 1, 4, 10};
	int n = sizeof(a) / sizeof(a[0]);

	cout << "Before sort" << endl;
	for (int i = 0; i < n; ++i) cout << " " << a[i];
	cout << endl;

	heapSort(a, n);

	cout << "after sort" << endl;
	for (int i = 0; i < n; ++i) cout << " " << a[i];
	cout << endl;

	return 0;
}
