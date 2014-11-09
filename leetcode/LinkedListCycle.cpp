#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head)
{
    if (head == NULL) return false;
    if (head->next == NULL) return false;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (true)
    {
        if (p1 != NULL) p1 = p1->next;  // step one
        else return false;
        if (p2 != NULL) p2 = p2->next;  // step one
        else return false;
        if (p2 != NULL) p2 = p2->next;  // step two
        else return false;

        if (p1 == NULL || p2 == NULL || p2->next == NULL || p2->next->next == NULL) return false;
        if (p1 == p2) return true;
        if (p2->next == p1 || p2->next->next == p1) return true;
    }
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next;
    cout << hasCycle(head) << endl;
    return 0;
}
