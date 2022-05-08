#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
using namespace std;


class KthLargest {
private:
    vector<int> heap;
    int mK;

public:
    void minHeapify(vector<int>& heap, int idx, int heapSize) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        int pSmall = idx;
        if (left < heapSize && heap[left] < heap[pSmall]) {
            pSmall = left;
        }
        if (right < heapSize && heap[right] < heap[pSmall]) {
            pSmall = right;
        }

        if (pSmall == idx) {
            return;
        }
        else {
            swap(heap[idx], heap[pSmall]);
            minHeapify(heap, pSmall, heapSize);
        }
    }


    void buildMinHeap(vector<int>& v) {
        if (v.empty()) return;

        int n = (int)v.size();
        for (int i = n - 1; i >= 0; --i) {
            minHeapify(v, i, n);
        }
    }

    void insertHeap(vector<int>& heap, int x) {
        if (x <= heap[0]) return;

        int sz = heap.size();
        heap[0] = x;
        minHeapify(heap, 0, sz);
    }

    KthLargest(int k, vector<int>& nums) {
        mK = k;
        if (nums.empty()) return;

        int n = (int)nums.size();
        if (k <= n) {
            for (int i = 0; i < k; ++i) heap.push_back(nums[i]);
            buildMinHeap(heap);
            for (int i = k; i < n; ++i) insertHeap(heap, nums[i]);
        }
        else {
            for (int i = 0; i < n; ++i) heap.push_back(nums[i]);
        }
    }

    int add(int val) {
        if (heap.size() >= mK) {
            insertHeap(heap, val);
            return heap[0];
        }
        else {
            heap.push_back(val);
            buildMinHeap(heap);
            return heap[0];
        }


    }
};