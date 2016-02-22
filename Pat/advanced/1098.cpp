#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void AdjustHeap(vector<int>& heap, int heapSize, int adjustIndex) {
	// pMaxIndex point to the max node of cur,left,right nodes
	int pMaxIndex = adjustIndex;
	if (2*adjustIndex+1 < heapSize && heap[2*adjustIndex+1] > heap[pMaxIndex])
		pMaxIndex = 2 * adjustIndex + 1;
	if (2*adjustIndex+2 < heapSize && heap[2*adjustIndex+2] > heap[pMaxIndex])
		pMaxIndex = 2 * adjustIndex + 2;

	// the cur node has max value, no need to adjust
	if (pMaxIndex == adjustIndex) {
		return;
	} else {
		swap(heap[adjustIndex], heap[pMaxIndex]);
		AdjustHeap(heap, heapSize, pMaxIndex);
	}
}

void PrintVector(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (i == 0) printf("%d", v[i]);
		else printf(" %d", v[i]);
	}
	printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	vector<int> input(n, 0);
	vector<int> output(n, 0);
	for (int i = 0; i < n; ++i) scanf("%d", &input[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &output[i]);

	vector<int> temp(input.begin(), input.end());
	sort(temp.begin(), temp.end());

	bool isHeapSort = true;
	int j = n - 1;
	while (j >= 0 && temp[j] == output[j]) j--;
	for (int i = 0; i <= j; ++i) {
		if (2*i+1 <= j) {
			if (output[i] < output[2*i+1]) isHeapSort = false;
		}
		if (2*i+2 <= j) {
			if (output[i] < output[2*i+2]) isHeapSort = false;
		}
	}

	if (isHeapSort) {
		printf("Heap Sort\n");
		int heapSize = j + 1;
		swap(output[0], output[heapSize-1]);
		heapSize--;
		AdjustHeap(output, heapSize, 0);
		PrintVector(output);

	} else {
		printf("Insertion Sort\n");
		int k = 0;
		while (k+1 < n && output[k] <= output[k+1]) k++;
		int next = k + 1;
		int temp = output[next];
		int start = 0;
		while (output[start] <= output[next]) start++;
		for (int idx = next - 1; idx >= start; --idx) {
			output[idx+1] = output[idx];
		}
		output[start] = temp;
		PrintVector(output);
	}
	return 0;
}