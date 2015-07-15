#include "MyHeaders.h"

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void deleteNode(ListNode* node) 
{
    ListNode* pNext = node->next;
    *node = *(node->next);
}

void PrintList(ListNode* head)
{
    ListNode* p = NULL;
    for (p = head; p != NULL; p = p->next)
    {
        cout << p->val << " ";
    }
    cout << endl;
}

int main()
{
    ListNode* p1 = NULL;
    ListNode* p2 = NULL;
    ListNode* p3 = NULL;
    ListNode* p4 = NULL;
    ListNode* head = p1 =  new ListNode(1);
    head->next = p2 = new ListNode(2);
    head->next->next = p3 = new ListNode(3);
    head->next->next->next = p4 = new ListNode(4);

    cout << "Original List:" << endl;
    PrintList(head);

    deleteNode(p1);

    cout << "After Remove List:" << endl;
    PrintList(head);
    
    return 0;
}

       
    