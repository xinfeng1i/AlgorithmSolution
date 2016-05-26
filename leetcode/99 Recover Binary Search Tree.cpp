#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 分为两种情况，情况一：
//        4
//       / \
//      2   6
//     / \  /\
//    1  7  5 3 mistake swap(3, 7)
//  中序顺序：1 2 7 4 5 6 3
//  如何找到（7,3）呢？首先找到将当前元素与其前驱元素比较，找到第一个降序对 (7, 4)
//  则第一个元素为降序对的第一个元素7
//  其次找到第二个降序对(6, 3)，第二个元素为该降序对的第二元素3
//  情况二：只有一个降序对
//     1
//    / \
//   2   3
// 中序遍历顺序为： 2 1 3
// 只有一个降序对(2, 1), 则第一、二个元素分别为降序对的第一、二个元素
//
// 总结：中序遍历整个BST，如果找到第一个降序对，则让first指针指向第一个元素，
// second指针指向第二个元素；如果找到第二个降序对，则更新第二个元素pair的第二个元素
TreeNode* prev = NULL;
TreeNode* cur = NULL;
TreeNode* first = NULL;
TreeNode* second = NULL;
void InOrder(TreeNode* root) {
    if (root == NULL) return;
        
    InOrder(root->left);
        
    if (prev == NULL) {
        cur = prev = root;
    } else {
        cur = root;
		// 找到第一个降序数据对，set两个指针为待交换元素
        if (cur->val <= prev->val) {
            if (first == NULL) {
                first = prev;
                second = cur;
			// 如果找到第二个降序数据对，reset第二个指针元素
            } else {
                second = cur;
            }
        }
        prev = cur;
    }
        
        
    InOrder(root->right);
}
    

void recoverTree(TreeNode* root) {
    if (root == NULL) return;
        
    InOrder(root);
    if (first != NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    } else if (first != NULL && second == NULL) {
        int temp = prev->val;
        prev->val = first->val;
        first->val = temp;
    }
        
}