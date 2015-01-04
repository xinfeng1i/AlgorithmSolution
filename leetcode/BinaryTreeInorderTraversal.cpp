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

// 
//      3
//   1     2
// 4   5  6   7 

vector<int> InorderTraversal(TreeNode* root)
{
	vector<int> ans;
	stack<TreeNode*> s;
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
			s.pop();
			ans.push_back(p->val);
			root = p->right;
		}
	}
	return ans;
}

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->right = new TreeNode(5);

	vector<int> v = InorderTraversal(root);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << " " << v[i];
	}
	cout << endl;

}