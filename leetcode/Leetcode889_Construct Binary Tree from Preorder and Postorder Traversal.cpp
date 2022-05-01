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


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


TreeNode* buildTreeRecursively(
    vector<int>& preorder, int preLeft, int preRight,
    vector<int>& postorder, int postLeft, int postRight, 
    unordered_map<int, int>& value2Index) {
    if (preLeft > preRight) return NULL;

    int rootVal = preorder[preLeft];
    int mid1 = preLeft;  // Notice this initial value, or will not correctly single element.
    int postMaxIndex = -1;
    for (int i = preLeft + 1; i <= preRight; ++i) {
        int num1 = i - preLeft;
        int idx2 = value2Index[preorder[i]];
        postMaxIndex = max(postMaxIndex, idx2);
        int num2 = postMaxIndex - postLeft + 1;
        if (num1 == num2) {
            mid1 = i;
            break;
        }
    }

    int leftNum = mid1 - preLeft;
    int mid2 = postLeft + leftNum - 1;

    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTreeRecursively(preorder, preLeft + 1, mid1, postorder, postLeft, mid2, value2Index);
    root->right = buildTreeRecursively(preorder, mid1 + 1, preRight, postorder, mid2 + 1, postRight - 1, value2Index);
    return root;
}


TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = (int)preorder.size();
    unordered_map<int, int> hash;
    for (size_t i = 0; i < postorder.size(); ++i) {
        int val = postorder[i];
        int idx = (int)i;
        hash[val] = idx;
    }
    return buildTreeRecursively(preorder, 0, n - 1, postorder, 0, n - 1, hash);
}

int main() {
    vector<int> v1 = { 1, 2, 4, 5, 3, 6, 7 }; 
    vector<int> v2 = { 4, 5, 2, 6, 7, 3, 1 };
    TreeNode* root = constructFromPrePost(v1, v2);
    return 0;
}

