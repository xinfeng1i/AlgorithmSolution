#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int TreeDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	int h1 = TreeDepth(root->left);
	int h2 = TreeDepth(root->right);
	return max(h1, h2)+1;
}
