#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k)
{

    // base case: no need to reverse
    if (k <= 1) return head;
    if (head == NULL || head->next == NULL) return head;

    // list length
    int n = 0;
    for (ListNode* p = head; p != NULL; p = p->next)
    {
        n++;
    }
    // length < k, return directly
    if (n < k) return head;
    
    // reverse the first k nodes
    ListNode* pFirst = NULL;
    ListNode* pLast = NULL;
    ListNode* pNextFirst = NULL;
    ListNode* pPrev = NULL;
    int curK = 1;
    ListNode* pCur = head;
    while (curK <= k)
    {
        // if this is the first node, remember it
        if (curK == 1) pFirst = pCur;
        // if this is the k-th node, reset header point to it
        if (curK == k) 
        { 
            head = pCur;                // new head node
            pLast = pCur;               // last node of the first k nodes
            pNextFirst = pCur->next;    // first nodes of the next k nodes
        }

        ListNode* pNext = pCur->next;
        pCur->next = pPrev;
        pPrev = pCur;
        pCur = pNext;
        
        curK++;
    }

    // reverse the rest list 
    ListNode* rest = reverseKGroup(pNextFirst, k);
    // chain the first k group with the rest list
    pFirst->next = rest;
    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);
    
    cout << "List:" << endl;
    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    ListNode* newHead = reverseKGroup(head, 3);

    cout << "Reverse k Groups:" << endl;
    for (ListNode* p = newHead; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    return 0;
}
