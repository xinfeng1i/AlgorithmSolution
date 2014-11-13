#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeList(ListNode* L1, ListNode* L2)
{
    if (L1 == NULL) return L2;
    if (L2 == NULL) return L1;

    ListNode* p1 = L1;
    ListNode* p2 = L2;
    ListNode* newHead = NULL;
    ListNode* cur = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        ListNode* pNext1 = p1->next;
        ListNode* pNext2 = p2->next;
        if (p1->val <= p2->val)
        {
            if (cur == NULL)
            {
                newHead = p1;
            }
            else
            {
                cur->next = p1;
            }
            cur = p1;
            p1 = pNext1;
        }
        else
        {
            if (cur == NULL)
            {
                newHead = p2;
            }
            else
            {
                cur->next = p2;
            }
            cur = p2;
            p2 = pNext2;
        }
    }
    if (p1 != NULL) cur->next = p1;
    if (p2 != NULL) cur->next = p2;

    return newHead;
}

ListNode* sortList(ListNode* head)
{
    // 0 or 1 nodes, already sorted
    if (head == NULL || head->next == NULL) return head;
    
    // split the list into two parts
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* L2 = slow->next;

    slow->next = NULL;
    ListNode* L1 = head;

    // sort the two parts recursively
    ListNode* sortedL1 = sortList(L1);
    ListNode* sortedL2 = sortList(L2);

    // merge
    ListNode* sortedList = mergeList(sortedL1, sortedL2);

    return sortedList;
}

int main()
{
    ListNode* L1 = new ListNode(1);
    L1->next = new ListNode(3);
    L1->next->next = new ListNode(5);

    ListNode* L2 = new ListNode(2);
    L2->next = new ListNode(4);
    L2->next->next = new ListNode(6);

    ListNode* newHead = mergeList(L1, L2);
    for (ListNode* p = newHead; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    ListNode* L = new ListNode(1);
    L->next = new ListNode(5);
    L->next->next = new ListNode(2);
    L->next->next->next = new ListNode(4);
    L->next->next->next->next = new ListNode(3);

    ListNode* sortedL = sortList(L);
    for (ListNode* p = sortedL; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;
    return 0;
}
