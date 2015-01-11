#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

// Summary: very like Inorder binary tree iteratively.
//
// The basic idea is the smallest value lies in the most left node.
// Init: we need to find the most left node, at same time we need to
//       push all the path node in a stack, cause these values 
//       decreasing along the path
// Second: the larger value must lie in the right child tree of curnode
//         (if whose right child exist), in the right child we still need
//         find the left most node (with smallest value in the right child tree)
// Third:  the current smallest value always lie in the top of stack, just pop
//         and return it. Remember to update the stack accroding to the second step.
//
// Author: python27
// 2015/01/11
class BSTIterator 
{
public:
	BSTIterator(TreeNode *root) 
	{
		if (root != NULL)
		{
			while (root != NULL)
			{
				s.push(root);
				root = root->left;
			}
		}
	}

	bool hasNext() 
	{
		return !s.empty();
	}

	int next() 
	{
		TreeNode* p = s.top();
		s.pop();

		if (p->right != NULL)
		{
			TreeNode* node = p->right;
			while (node != NULL)
			{
				s.push(node);
				node = node->left;
			}
		}

		return p->val;
	}
private:
	TreeNode* pCurNode;
	stack<TreeNode*> s;
};

#if 1
int main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	BSTIterator i = BSTIterator(root);
	while (i.hasNext())
	{
		cout << i.next() << " ";
	}
	cout << endl;

	return 0;
}
#endif //0