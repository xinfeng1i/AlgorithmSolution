#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
    	A.resize(nums.size());
    	copy(nums.begin(), nums.end(), A.begin());
    	int n = (int) nums.size();
    	proot = BuildSegmentTree(nums, 0, n-1);
    }

    void update(int i, int val) {
    	int diff = val - A[i];
    	UpdateVal(proot, i, diff);
    	A[i] = val;
    }

    int sumRange(int i, int j) {
        return RangeSum(proot, i, j);
    }
private:
	SegmentNode* proot;
	vector<int> A;
public:
	struct SegmentNode {
	int start;
	int end;
	int sum;
	SegmentNode* left;
	SegmentNode* right;
	
	SegmentNode(int s, int e):start(s), end(e), sum(0), left(NULL), right(NULL) {}
};

SegmentNode* BuildSegmentTree(vector<int>& A, int s, int e) {
	if (s > e) return NULL;
	if (s == e) {
		SegmentNode* root = new SegmentNode(s, e);
		root->sum = A[s];
		return root;
	}
	
	int mid = s + (e - s) / 2;
	SegmentNode* left_tree = BuildSegmentTree(A, s, mid);
	SegmentNode* right_tree = BuildSegmentTree(A, mid+1, e);
	SegmentNode* root = new SegmentNode(s, e);
	root->sum = left_tree->sum + right_tree->sum;
	root->left = left_tree;
	root->right = right_tree;
	return root;
}

int RangeSum(SegmentNode* root, int s, int e) {
	if (root == NULL) return 0;
	if (root->end < s || root->start > e) return 0;
	if (s <= root->start && e >= root->end) return root->sum;
	//int mid = root->start + (root->end - root->start) / 2;
	int left_sum = RangeSum(root->left, s, e);
	int right_sum = RangeSum(root->right, s, e);
	return left_sum + right_sum;
}

void UpdateVal(SegmentNode* root, int idx, int diff) {
	if (root == NULL) return;
	if (idx < root->start || idx > root->end) return;
	root->sum += diff;
	UpdateVal(root->left, idx, diff);
	UpdateVal(root->right, idx, diff); 
}
};


