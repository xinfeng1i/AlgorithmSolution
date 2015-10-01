#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
    
    Node(char v) : value(v), left(NULL), right(NULL){}
};

Node* BuildTree(const string& preOrder, int left1, int right1,
          const string& inOrder, int left2, int right2)
{
    assert(right1 - left1 == right2 - left2);
    // base case
    if (left1 > right1) return NULL;
    // 构建根节点
    char ch = preOrder[left1];
    Node* root = new Node(ch);
    // 在中序中寻找根节点
    size_t mid2 = inOrder.find(ch);
    int leftNum = mid2 - left2;
    // 在前序中确定前后子树的位置
    int mid1 = left1 + leftNum;
    root->left = BuildTree(preOrder, left1 + 1, mid1,
                           inOrder, left2, mid2 - 1);
    root->right = BuildTree(preOrder, mid1 + 1, right1,
                            inOrder, mid2+ 1, right2);
    return root;
}

void PostOrder(Node* root)
{
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->value;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    Node* root = BuildTree(s1, 0, n - 1, s2, 0, n-1);
    PostOrder(root);
    return 0;
}
