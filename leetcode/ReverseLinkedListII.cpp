#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    ListNode* pBeforeM = NULL;
    int curPos = 1;
    ListNode* pM = head;    // point to the m-th node
    while (curPos < m)
    {
        pBeforeM = pM;
        pM = pM->next;
        curPos++;
    }

    
    ListNode* pLast = NULL;     // point to the (n+1)th node
    curPos = m;
    ListNode* pPrev = NULL;
    ListNode* pCur = pM;
    while (curPos <= n)
    {
        // remember next node before reverse
        ListNode* pNext = pCur->next;

        // remember the (n+1)th node before reverse
        if (curPos == n) pLast = pCur->next;

        // reverse current node
        pCur->next = pPrev;
        // move to next node
        pPrev = pCur;
        pCur = pNext;

        curPos++;
    }

    ListNode* pN = pPrev;
    
    if (pBeforeM == NULL) head = pN;
    else pBeforeM->next = pN;

    pM->next = pLast;
    
    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* newHead = reverseBetween(head, 2, 2);

    for (ListNode* p = newHead; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    return 0;
}
