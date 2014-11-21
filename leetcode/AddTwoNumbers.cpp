#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (l1 == NULL && l2 == NULL) return NULL;

    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* head = NULL;
    ListNode* p = NULL;
    // add two list without carry
    while (p1 != NULL && p2 != NULL)
    {
        if (p == NULL) 
        {
            head = p = new ListNode(p1->val + p2->val);
        }
        else 
        {
            p->next = new ListNode(p1->val + p2->val);
            p = p->next;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    if (p1 != NULL)
    {
        while (p1 != NULL)
        {
            if (p == NULL)
            {
                head = p = new ListNode(p1->val);
            }
            else 
            {
                p->next = new ListNode(p1->val); 
                p = p->next;
            }
            p1 = p1->next;
        }
    }

    if (p2 != NULL)
    {
        while (p2 != NULL)
        {
            if (p == NULL) 
            {
                head = p = new ListNode(p2->val);
            }
            else 
            {
                p->next = new ListNode(p2->val);
                p = p->next;
            }
            p2 = p2->next;
        }
    }
    // add carry
    p = head;
    while (p != NULL)
    {
        int num = p->val;
        if (num >= 10)
        {
            p->val = num % 10;

            if (p->next != NULL)
            {
                p->next->val += num / 10;
            }
            else
            {
                p->next = new ListNode(num / 10);
            }
        }
        p = p->next;
    }
    return head; 
}

int main()
{
    ListNode* L1 = new ListNode(9);
    L1->next = new ListNode(4);
    L1->next->next = new ListNode(3);

    ListNode* L2 = NULL;
    //ListNode* L2 = new ListNode(1);
    //L2->next = new ListNode(6);
    //L2->next->next = new ListNode(4);

    ListNode* ans = addTwoNumbers(L1, L2);

    for (ListNode* p = ans; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    return 0;
}
