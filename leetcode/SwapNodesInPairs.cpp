#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* swapPairs(ListNode* head)
{
    // base case: zero or only one Node
    if (head == NULL || head->next == NULL) return head;

    // swap the first two nodes
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    p1->next = p2->next;
    p2->next = p1;
    head = p2;

    ListNode* p = head->next;
    while (p != NULL && p->next != NULL && p->next->next != NULL)
    {
        p1 = p->next;
        p2 = p->next->next;
        
        p1->next = p2->next;
        p2->next = p1;
        p->next = p2;

        // update p
        p = p->next->next;
    }
    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);

    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    ListNode* newHead = swapPairs(head);
    for (ListNode* p = newHead; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;
    
    return 0;
}
