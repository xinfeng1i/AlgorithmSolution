#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if (head == NULL) return NULL;

    ListNode* ref = head;
    // ref point to the nth node from head
    int k = 1;
    while (k < n)
    {
        ref = ref->next;
        k++;
    }

    ListNode* p = head;
    ListNode* pre = NULL;
    while (ref->next != NULL)
    {
        ref = ref->next;
        pre = p;
        p = p->next;
    }

    ListNode* tmp = NULL;
    if (pre == NULL)        // need to delete the first node
    {
        head = head->next;
    }
    else
    {
        pre->next = p->next;
    }
    delete tmp;
    tmp = NULL;

    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    ListNode* newHead = removeNthFromEnd(head, 3);
    for (ListNode* p = newHead; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    return 0;
}
