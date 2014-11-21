#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* sortedListToBST(ListNode* head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL) return new TreeNode(head->val);

    // find the middle element with fast and slow pointer
    ListNode* prevSlow = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // divide the list to left and right part
    ListNode* L1 = head;
    if (prevSlow != NULL)
    {
        prevSlow->next = NULL;
    }
    else
    {
        L1 = NULL; 
    }
    ListNode* L2 = slow->next;

    // construct BST recursively 
    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(L1);
    root->right = sortedListToBST(L2);
    
    return root;
}

void InOrder(TreeNode* root)
{
    if (root == NULL) return;
    InOrder(root->left);
    cout << " " << root->val;
    InOrder(root->right);
}

int main()
{
    ListNode* head = new ListNode(1);
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);

    TreeNode* root = sortedListToBST(head);
    InOrder(root);

    return 0;
}
