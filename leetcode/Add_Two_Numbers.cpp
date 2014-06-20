// Definition for singly-linked list.
#include <iostream>
using namespace std;
 
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode* p1;
        ListNode* p2;
        long long f1 = 1, f2 = 1;
        long long num1 = 0, num2 = 0;
        for (p1 = l1; p1 != NULL; p1 = p1->next)
        {
            num1 = f1 * (p1->val) + num1;
            f1 *= 10;
        }

        for (p2 = l2; p2 != NULL; p2 = p2->next)
        {
            num2 = f2 * (p2->val) + num2;
            f2 *= 10;
        }

        long ans = num1 + num2;
        string s(to_string(ans));
        ListNode* head = NULL;
        for (size_t i = 0; i < s.size(); ++i)
        {
            pnewnode = new ListNode(s[i]-'0');
            pnewnode->next = head;
            head = pnewnode;
        }

        return head;
    }
};

