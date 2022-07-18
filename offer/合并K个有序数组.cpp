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
using namespace std;

//========================================================================
// Method1: Select the k elements by O(k) comparation
//
// Time: O(N*k) where N is the total number of elements of the k arrays
// Space: O(k)
//=========================================================================
vector<int> MergeKSortedArray(vector<vector<int>>& arrays) {
    int k = (int) arrays.size();
    vector<int> p(k, 0);

    vector<int> result;
    while (true) {
        // 1. select the min elem from the current k element
        int arrIdx = -1;
        int curMin = INT_MAX;
        for (int i = 0; i < k; ++i) {
            if (p[i] >= (int)arrays[i].size()) {
                continue;
            }

            if (arrays[i][p[i]] < curMin) {
                curMin = arrays[i][p[i]];
                arrIdx = i;
            }
        }

        if (arrIdx == -1) break;

        // 2. push the element to result
        result.push_back(curMin);

        // 3. move to next
        p[arrIdx]++;
    }

    return result;
}

//======================================================================
// Method II: Using the head to further reduce the time complexity
// 
// Time: O(N*logk), where N is the total Number of Elements.
// Space: O(k)
// ======================================================================
struct ArrElem {
    int val;
    int row;
    int col;
    ArrElem() : val(0), row(-1), col(-1) {};
    ArrElem(int x, int i, int j) : val(x), row(i), col(j) {}

    bool operator<(const ArrElem& other) const {
        if (val != other.val) {
            return val < other.val;
        }
        else if (row != other.row) {
            return row < other.row;
        }
        else {
            return col < other.col;
        }
    
    }
};


vector<int> mergeKSortedArrayII(vector<vector<int>>& arrs) {
    int k = (int)arrs.size();

    vector<int> result;
    priority_queue<ArrElem, vector<ArrElem>> heap;
    for (int i = 0; i < k; ++i) {
        ArrElem elem(arrs[i][0], i, 0);
        heap.push(elem);
    }

    while (!heap.empty()) {
        // get the min element from current k elements
        ArrElem temp = heap.top();
        result.push_back(temp.val);
        heap.pop();
        // push the next element to the heap
        if (temp.col + 1 < (int)arrs[temp.row].size()) {
            ArrElem nextElem(arrs[temp.row][temp.col + 1], temp.row, temp.col + 1);
            heap.push(nextElem);
        }   
    }

    return result;
}


// ======================================================================
// Method III: 使用自定义的堆数据结构进行k个最小数的比较
// 
// Time: O(N*logk)，where the N is the total number of elements.
// Space: O(k), where k is the size of the heap.
//
// ======================================================================
class MyHeap {
private:
    vector<ArrElem> mHeap;
    int getLeft(int idx) {
        return 2 * idx + 1;
    }
    int getRight(int idx) {
        return 2 * idx + 2;
    }
    int getParent(int idx) {
        if (idx % 2 == 1) {
            return (idx - 1) / 2;
        }
        else {
            return (idx - 2) / 2;
        }
    }
    void heapify(int idx) {
        int p = idx;
        int n = (int) mHeap.size();
        int left = getLeft(idx);
        int right = getRight(idx);
        if (left < n && mHeap[left] < mHeap[p]) {
            p = left;
        }
        if (right < n && mHeap[right] < mHeap[p]) {
            p = right;
        }
        if (p != idx) {
            ArrElem temp = mHeap[idx];
            mHeap[idx] = mHeap[p];
            mHeap[p] = temp;
            heapify(p);
        }
    }
    void buildHeap(vector<ArrElem>& v) {
        mHeap.clear();
        mHeap.resize(v.size());
        copy(v.begin(), v.end(), mHeap.begin());
        int n = (int) mHeap.size();
        for (int i = n - 1; i >= 0; --i) {
            heapify(i);
        }
    }
public:
    MyHeap() {
        mHeap.clear();
    }
    MyHeap(vector<ArrElem>& v) {
        buildHeap(v);
    }
    ArrElem getTop() {
        assert(!mHeap.empty());
        ArrElem ans = mHeap[0];
        return ans;
    }
    void pop() {
        assert(!mHeap.empty());
        int n = (int) mHeap.size();
        // swap to the last element
        ArrElem temp = mHeap[0];
        mHeap[0] = mHeap[n - 1];
        mHeap[n - 1] = temp;
        // remove the new last element
        mHeap.pop_back();
        // adjust heap
        heapify(0);
    }
    void push(ArrElem e) {
        mHeap.push_back(e);
        int n = (int) mHeap.size();
        int curIdx = n - 1;
        while (curIdx >= 0) {
            heapify(curIdx);
            curIdx = getParent(curIdx);
        }
    }

    int size() {
        return (int) mHeap.size();
    }

    bool empty() {
        return mHeap.empty();
    }
};


vector<int> mergeKSortedArrayIII(vector<vector<int>>& arrs) {
    int k = (int)arrs.size();

    vector<int> result;
    MyHeap heap;
    for (int i = 0; i < k; ++i) {
        ArrElem elem(arrs[i][0], i, 0);
        heap.push(elem);
    }

    while (!heap.empty()) {
        // get the min element from current k elements
        ArrElem temp = heap.getTop();
        result.push_back(temp.val);
        heap.pop();
        // push the next element to the heap
        if (temp.col + 1 < (int)arrs[temp.row].size()) {
            ArrElem nextElem(arrs[temp.row][temp.col + 1], temp.row, temp.col + 1);
            heap.push(nextElem);
        }
    }

    return result;
}




int main() {
    
    vector<int> v1 = { 1, 3, 5, 7};
    vector<int> v2 = { 2, 4, 6 };
    vector<int> v3 = { 0, 8, 9, 10, 11 };
    vector<vector<int>> arrs;
    arrs.push_back(v1);
    arrs.push_back(v2);
    arrs.push_back(v3);

    vector<int> result = mergeKSortedArrayIII(arrs);
    for (int x : result) {
        cout << " " << x;
    }
    cout << endl;
    

    /*
    // test MyHeap
    ArrElem a1(1, 0, 0);
    ArrElem a2(2, 0, 1);
    ArrElem a3(0, 0, 2);
    ArrElem a4(4, 0, 3);

    vector<ArrElem> v;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);

    MyHeap heap(v);
    heap.push(a4);

    while (!heap.empty()) {
        ArrElem e = heap.getTop();
        cout << e.val << " (" << e.row << ", " << e.col << ")" << endl;
        heap.pop();
    }
    */
    return 0;
}