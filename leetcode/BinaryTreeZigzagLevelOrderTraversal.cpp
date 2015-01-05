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

vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int> > ans;
	if (root == NULL) return ans;

	queue<TreeNode*> q;
	q.push(root);
	int flag = 1;
	int curLevelNum = 1;
	int nextLevelNum = 0;
	vector<int> curLevel;
	while (!q.empty())
	{
		curLevel.clear();
		nextLevelNum = 0;
		// pop the curlevelnum nodes
		for (int i = 0; i < curLevelNum; ++i)
		{
			TreeNode* tmp = q.front();
			
			// each node push_back or push_front based on flag
			if (flag == 1)
			{
				curLevel.push_back(tmp->val);
			}
			else
			{
				curLevel.insert(curLevel.begin(), tmp->val);
			}

			// count the number of node in nextlevel
			if (tmp->left != NULL)  { q.push(tmp->left);  nextLevelNum++; }
			if (tmp->right != NULL) { q.push(tmp->right); nextLevelNum++; }

			q.pop();
		}

		ans.push_back(curLevel);

		// update the next level num
		curLevelNum = nextLevelNum;
		// update the insert direction
		flag = 1 - flag;

	}

	return ans;

}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	vector<vector<int>> ans = zigzagLevelOrder(root);

	for (size_t i = 0; i < ans.size(); ++i)
	{
		for (size_t j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}