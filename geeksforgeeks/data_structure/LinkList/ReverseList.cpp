#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
    // base case: 0 or 1 nodes only
    if (head == NULL || head->next == NULL) return head;
    
    ListNode* pPrev = NULL;
    ListNode* pCur = head;
    ListNode* pNext = pCur->next;
    while (pCur != NULL)
    {
        // remember the next node before change
        pNext = pCur->next;
        // change current node pointer to prev node
        pCur->next = pPrev;
        // move forward one step
        pPrev = pCur;
        pCur = pNext;
    }
    return pPrev;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    ListNode* newHead = reverseList(head);

    for (ListNode* p = newHead; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    return 0;
}
