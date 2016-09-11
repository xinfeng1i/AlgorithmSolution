#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        return;
    }
};
