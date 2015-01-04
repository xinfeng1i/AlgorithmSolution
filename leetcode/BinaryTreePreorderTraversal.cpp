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

vector<int> PreorderTraversal(TreeNode* root)
{
	vector<int> ans;
	stack<TreeNode*> s;

	while (!s.empty() || root != NULL)
	{
		if (root != NULL)
		{
			ans.push_back(root->val);
			if (root->right != NULL) s.push(root->right);
			root = root->left;
		}
		else
		{
			root = s.top();
			s.pop();
		}
	}
	return ans;
	
}



int main()
{
	TreeNode* root = new TreeNode(5);

	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);

	root->right = new TreeNode(7);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);

	cout << "Preorder Traversal Iteratively:" << endl;
	vector<int> v1 = PreorderTraversal(root);
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << " " << v1[i];
	}
	cout << endl;

}