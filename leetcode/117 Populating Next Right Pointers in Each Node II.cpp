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
#include <assert.h>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
	if (root == NULL) return;

	queue<TreeLinkNode*> q;
	q.push(root);
	while (!q.empty()) {
		int sz = (int) q.size();
		for (int i = 0; i < sz; ++i) {
			TreeLinkNode* cur = q.front();
			q.pop();
			// not the last node in this level
			if (i != sz - 1) {
				cur->next = q.front();
			} else {
				cur->next = NULL;
			}

			if (cur->left != NULL) q.push(cur->left);
			if (cur->right != NULL) q.push(cur->right);
		}
	}

	return;
}