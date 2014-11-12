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
    if (head == NULL || head->next == NULL) return head;

    ListNode* pPrev = NULL;
    ListNode* pCur = head;
    ListNode* pNext = pCur->next;
    while (pCur != NULL)
    {
        pNext = pCur->next;
        pCur->next = pPrev;
        pPrev = pCur;
        pCur = pNext;
    }
    return pPrev;
}

void reorderList(ListNode* head)
{
    // 0, 1, 2 nodes, nothing to do
    if (head == NULL || head->next == NULL ||
        head->next->next == NULL) return;

    // fast, slow pointer to find the middle of the list
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* mid = slow->next;
    slow->next = NULL;
    ListNode* reverseHead = reverseList(mid);

    ListNode* p1 = head;
    ListNode* p2 = reverseHead;
    while (p1 != NULL && p2 != NULL)
    {
        // remember the next node after p1, p2 before changing
        ListNode* p1After = p1->next;
        ListNode* p2After = p2->next;
        // change the pointer
        p1->next = p2;
        p2->next = p1After;
        // move forward;
        p1 = p1After;
        p2 = p2After;
    }
    return;
}

int main()
{
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);

    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    //ListNode* reverseHead = reverseList(head);

    reorderList(head);

    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;
}
