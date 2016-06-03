// Return the path sum rooted at root
// left_sum = max path sum contain root and extend tarwards left children
//       A
//     B
//      C
// right_sum left_sum = max path sum contain root and extend tarwards right children
//       A
//         D
//        E
// left_right_sum = max path sum contain root and extend both tarwards left & right children
//       A
//    B      D
//     C    E
void maxPathSumRootedAt(TreeNode* root, int& left_sum, int& right_sum, int& left_right_sum, int& max_sum) {
    if (root == NULL) {
        left_sum = right_sum = left_right_sum = 0;
        return;
    }
    
    int left_sum1 = 0, right_sum1 = 0, left_right_sum1 = 0;
    maxPathSumRootedAt(root->left, left_sum1, right_sum1, left_right_sum1, max_sum);

    int left_sum1 = 0, right_sum1 = 0, left_right_sum1 = 0;
    maxPathSumRootedAt(root->right, left_sum2, right_sum2, left_right_sum2, max_sum);
    
    left_sum = max(max(left_sum1, right_sum1) + root->val, root->val);
    right_sum = max(max(left_sum2, right_sum2) + root->val, root->val);
    left_right_sum = (left_sum + right_sum - root->val);
    if (left_sum > max_sum) max_sum = left_sum;
    if (right_sum > max_sum) max_sum = right_sum;
    if (left_right_sum > max_sum) max_sum = left_right_sum;
}

int maxPathSum(TreeNode* root) {
    if (root == NULL) return 0;
    int lsum = 0, rsum = 0, lrsum = 0, maxsum = INT_MIN;
    maxPathSumRootedAt(root, lsum, rsum, lrsum, maxsum);
    return maxsum == INT_MIN ? 0 : maxsum;
}
