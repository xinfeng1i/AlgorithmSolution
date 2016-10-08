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

vector<vector<int> > Print(TreeNode* root) {
	vector<vector<int> > ans;
	if (root == NULL) return ans;
	queue<TreeNode*> q;
	q.push(root);
	int row_num = 0;
	while (!q.empty()) {
		row_num++;
		int n = static_cast<int>(q.size());
		vector<int> current_row;
		
		// get current row of the tree from left to right
		for (int i = 0; i < n; ++i) {
			TreeNode* temp = q.front();
			q.pop();
			current_row.push_back(temp->val);
			
			if (temp->left != NULL) q.push(temp->left);
			if (temp->right != NULL) q.push(temp->right);
		}
		
		// if current row is even row, reverse the order from right to left
		if (row_num % 2 == 0) {
			reverse(current_row.begin(), current_row.end());
		}
		
		ans.push_back(current_row);
	}
	return ans;
}

void PrintVec(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	
	vector<vector<int>> ans = Print(root);
	
	for (size_t i = 0; i < ans.size(); ++i) {
		PrintVec(ans[i]);
	}
	
	return 0;
}


