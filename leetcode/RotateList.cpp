#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k)
{
    // 0 or 1 Node, return directly
    if (head == NULL || head->next == NULL) return head;

    // List length
    int n = 0;
    for (ListNode* p = head; p != NULL; p = p->next)
    {
        n++;
    }
    
    k = k % n;
    if (k == 0) return head;

    // find the (n-k)-th Node
    int num = n - k;
    int curnum = 1;
    ListNode* pre = head;
    while (curnum < num)
    {
        pre = pre->next;
        curnum++;
    }

    // find the last Node
    ListNode* last = head;
    while (last->next != NULL) last = last->next;

    // update pointer
    last->next = head;
    head = pre->next;
    pre->next = NULL;

    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    ListNode* newHead = rotateRight(head, 2);

    for (ListNode* p = newHead; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;

    return 0;
}
