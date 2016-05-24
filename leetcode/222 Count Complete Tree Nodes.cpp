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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
        
    int lh = 0;
    int rh = 0;
	// 计算左子树高度
    TreeNode* pl = root->left;
    while (pl) {
        lh++;
        pl = pl->left;
    }
    
	// 计算右子树高度
    TreeNode* pr = root->right;
    while (pr) {
        rh++;
        pr = pr->left;
    }
    
	// 左右子树高度相同，说明左子树是一个满二叉树，其节点数为2^lh-1，再加上1个根节点为2^lh
    if (lh == rh) {
        return (1 << lh) + countNodes(root->right);
    } else { // 否则，说明右子树是比左子树高度少1的满二叉树，加上根节点总共有2^rh个节点
        return (1 << rh) + countNodes(root->left);
    }
}