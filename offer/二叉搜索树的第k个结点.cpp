#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
 * BST的中序遍历就是一个排序数组
 * 因此可以仿照二分查找的方法进行快速搜索，比较
 * 中间元素，根据其结果递归的查找左右子树
 */
void NumberOfNodes(TreeNode* root, int& num) {
	if (root == NULL) {
		num = 0;
		return;
	}
	int left_num = 0; int right_num = 0;
	NumberOfNodes(root->left, left_num);
	NumberOfNodes(root->right, right_num);
	num = left_num + right_num + 1;
	return;
}

TreeNode* KthNode(TreeNode* root, unsigned int k)
{
	int n = 0;
	NumberOfNodes(root, n);
	
	if (k < 1 || k > n) return NULL;
	if (root == NULL) return NULL;
	
	int left_n = 0;
	int right_n = 0;
	NumberOfNodes(root->left, left_n);
	
	if (left_n == k-1) {
		return root;
	} else if (left_n > k-1) {
		return KthNode(root->left, k);
	} else if (left_n < k-1) {
		return KthNode(root->right, k-(left_n+1));
	}
}

int main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);

	TreeNode* p = KthNode(root, 5);
	cout << p->val << endl;


	return 0;
}
