#include "MyHeaders.h"

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head)
{
    // base case
    if (head == NULL || head->next == NULL) return true;
    
    int n = 0;
    ListNode* p;
    for (p = head; p != NULL; p = p->next)
    {
        n++;
    }

    assert(n >= 2);
    int cnt = 0;
    ListNode* pMid = NULL;

    // find middle node
    for (p = head; p != NULL; p = p->next)
    {
        cnt++;
        if (cnt == n / 2 + 1) 
        {
            pMid = p;
            break;
        }
    }
    
    ListNode* p1 = head;    // first half part
    ListNode* p2 = pMid;    // second half part
    if (n % 2 == 1) p2 = pMid->next;

    ListNode* p1End = p1;
    while (p1End->next != p2) p1End = p1End->next;

    // Reverse the second part of the list
    ListNode* p2Pre = NULL;
    while (p2 != NULL)
    {
        ListNode* p2Next = p2->next;

        p2->next = p2Pre;

        p2Pre = p2;
        p2 = p2Next;
    }
    
    bool flag = true;

    // Compare the two part
    ListNode* reverseHead = p2Pre;
    p2 = reverseHead;
    p1 = head;
    while (p2 != NULL)
    {
        if (p1->val != p2->val)
        {
            flag = false;
            break;
        }
        p2 = p2->next;
        p1 = p1->next;
    }

    // Rverse the second half part back
    p2Pre = NULL;
    p2 = reverseHead;
    while (p2 != NULL)
    {
        ListNode* p2Next = p2->next;
        p2->next = p2Pre;
        p2Pre = p2;
        p2 = p2Next;
    }

    p1End = p2Pre;
    
    return flag;
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(1);

    cout << "Original List:" << endl;
    PrintList(head);

    bool ans = isPalindrome(head);
    cout << "ans = " << ans << endl;

    cout << "After List:" << endl;
    PrintList(head);

    return 0;
}