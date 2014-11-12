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

ListNode* reverseListRecursively(ListNode* head)
{
    // base case: 0 or 1 nodes only
    if (head == NULL || head->next == NULL) return head;
    
    ListNode* pFirst = head;
    ListNode* pRest = head->next;

    // reverse the rest list
    ListNode* pRestHead = reverseListRecursively(pRest);
    // find the last node of the rest list
    ListNode* pLast = pRestHead;
    while (pLast != NULL && pLast->next != NULL) pLast = pLast->next;

    // chain the the two part
    if (pLast != NULL) pLast->next = pFirst;
    pFirst->next = NULL;
   
    return pRestHead;
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

    ListNode* newHead = reverseListRecursively(head);

    for (ListNode* p = newHead; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    return 0;
}
