#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode* insertionSortList(ListNode* head)
{
    if (head == NULL || head->next == NULL) return head;

    ListNode* cur = head->next;
    ListNode* prevCur = head;
    while (cur != NULL)
    {
        // find the first node that greater than cur node
        ListNode* p = head;
        ListNode* prevP = NULL;
        while (p != cur && p->val <= cur->val)
        {
            prevP = p;
            p = p->next;
        }
        
        if (p != cur)
        {
            // remeber the next position
            ListNode* nextCur = cur->next;
            // remove current node from original position
            prevCur->next = cur->next;
            // link the node with found position
            if (prevP != NULL)
            {
                cur->next = prevP->next;
                prevP->next = cur;
            }
            else
            {
                cur->next = head;
                head = cur;
            }

            prevCur = prevCur;
            cur = nextCur;
        }
        else
        {
            // move to next to be inserted node
            prevCur = cur;
            cur = cur->next;
        }
    }
    return head;
}

int main()
{
    ListNode* head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    //head->next->next->next = new ListNode(1);

    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    ListNode* newHead = insertionSortList(head);

    for (ListNode* p = newHead; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;
}
