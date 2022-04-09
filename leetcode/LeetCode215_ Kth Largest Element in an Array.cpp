#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

/*
 * 算法1：quick sort partition，时间复杂度 O(n)
 */
int partition1(vector<int>& v, int left, int right) {
    assert(left <= right);
    
    int pivot = v[left];
    int i = left;
    for (int j = left + 1; j <= right; ++j) {
        if (v[j] >= pivot) {
            swap(v[i + 1], v[j]);
            i++;
        }
    }
    swap(v[left], v[i]);
    return i;
}

int findKthMaxElement(vector<int>& v, int k, int left, int right) {
    if (left > right) return -1;
    if (left == right && k == 1) return v[left];
    
    int mid = partition1(v, left, right);
    int cnt = mid - left + 1;
    if (cnt == k) {
        return v[mid];
    }
    else if (cnt > k) {
        return findKthMaxElement(v, k, left, mid - 1);
    }
    else {
        return findKthMaxElement(v, k - cnt, mid + 1, right);
    }
}


int findKthLargest(vector<int>& nums, int k) {
    int n = (int)nums.size();
    return findKthMaxElement(nums, k, 0, n - 1);
}

/*
 * 算法2：实现堆
 */

int getLeft(int i) {
    return 2 * i + 1;
}

int getRight(int i) {
    return 2 * i + 2;
}

int getParent(int i) {
    return (i - 1) / 2;
}


void heapify(int i, vector<int>& v, int size) {
    int left = getLeft(i);
    int right = getRight(i);

    int smaller = i;
    if (left < size && v[left] < v[smaller]) smaller = left;
    if (right < size && v[right] < v[smaller]) smaller = right;
    if (smaller == i) {
        return;
    }
    else {
        swap(v[i], v[smaller]);
        heapify(smaller, v, size);
    }
}

void buildHeap(vector<int>& v) {
    int sz = (int) v.size();
    for (int i = sz - 1; i >= 0; i--) {
        heapify(i, v, sz);
    }
}


int findKthLargest(vector<int>& nums, int k) {
    int n = (int) nums.size();

    // build heap with first k elements, time: O(k)
    vector<int> heap;
    for (int i = 0; i < k; ++i) heap.push_back(nums[i]);
    buildHeap(heap);

    // insert the remaining element to heap one by one, time: (n-k)log(k)
    for (int i = k; i < n; ++i) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapify(0, heap, k);
        }
    }

    return heap[0];
}



int main() {
    vector<int> v = { 20, 30, 10, 50, 40 };
    
    for (int x : v) {
        cout << " " << x;
    }
    cout << endl;

    buildHeap(v);

    for (int x : v) {
        cout << " " << x;
    }
    cout << endl;

    return 0;
}