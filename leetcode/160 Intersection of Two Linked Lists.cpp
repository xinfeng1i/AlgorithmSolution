#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int n):val(n),next(NULL){}
};

ListNode* getIntersectionNode(ListNode* head1, ListNode* head2)
{
    if (head1 == NULL || head2 == NULL) return NULL;

    // head1 != NULL && head2 != NULL
    int n1 = 0;
    for (ListNode* p1 = head1; p1 != NULL; p1 = p1->next)
    {
        n1++;
    }

    int n2 = 0;
    for (ListNode* p2 = head2; p2 != NULL; p2 = p2->next)
    {
        n2++;
    }

    ListNode* p1 = head1;
    ListNode* p2 = head2;
    if (n1 != n2)
    {
        if (n1 > n2)
        {
            int diff = n1 - n2;
            while (diff--) p1 = p1->next;

        }
        else if (n1 < n2)
        {
            int diff = n2 - n1;
            while(diff--) p2 = p2->next;
        }
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val == p2->val)
        {
            return p1;
        }
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    return NULL;

}

void PrintList(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;
}

int main()
{
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    //ListNode* p3 = new ListNode(3);
    //p1->next = p3;
    //p2->next = p3;


    ListNode* h1 = p1;
    ListNode* h2 = p2;

    cout << "List h1:" << endl;
    PrintList(h1);

    cout << "List h2:" << endl;
    PrintList(h2);

    cout << "common part" << endl;
    ListNode* p = getIntersectionNode(h1, h2);
    PrintList(p);
    
    return 0;
}
