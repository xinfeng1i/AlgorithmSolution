#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head)
{
    // 0 or 1 element only
    if (head == NULL || head->next == NULL) return head;

    ListNode* pre = NULL;
    ListNode* first = head;
    while (first != NULL && first->next != NULL)
    {
        ListNode* second = first->next;
        if (first->val == second->val)
        {
            int value = first->val;
            ListNode* p = second->next;
            while (p != NULL && p->val == value) p = p->next;

            ListNode* tmpP = first;
            while (tmpP != p)
            {
                ListNode* tmpDelete = tmpP;
                tmpP = tmpP->next;
                delete tmpDelete;
                tmpDelete = NULL;
            }

            if (pre == NULL) head = p; // first node need to be delete
            else pre->next = p;
            first = p;
        }
        else
        {
            pre = first;
            first = first->next;
        }
    }

    return head;
}

void printList(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(3);
    //head->next->next->next->next = new ListNode(4);
    //head->next->next->next->next->next = new ListNode(4);
    //head->next->next->next->next->next->next = new ListNode(5);
    
    printList(head);

    ListNode* newHead = deleteDuplicates(head);

    printList(newHead);

    return 0;
}
