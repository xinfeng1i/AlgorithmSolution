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


vector<int> PostorderTraversal(TreeNode* root)
{
	vector<int> ans;
	stack<TreeNode*> s;
	TreeNode* lastVisited = NULL;
	while (!s.empty() || root != NULL)
	{
		if (root != NULL)
		{
			s.push(root);
			root = root->left;
		}
		else
		{
			TreeNode* p = s.top();
			if (p->right != NULL && lastVisited != p->right)
			{
				root = p->right;
			}
			else
			{
				ans.push_back(p->val);
				lastVisited = s.top();
				s.pop();
			}
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


	cout << "Postorder Traversal Iteratively:" << endl;
	vector<int> v3 = PostorderTraversal(root);
	for (size_t i = 0; i < v3.size(); ++i)
	{
		cout << " " << v3[i];
	}
	cout << endl;

}