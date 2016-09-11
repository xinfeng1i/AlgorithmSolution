#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) return NULL;
        
        ListNode* pre = NULL;
        ListNode* cur = pHead;
        while (cur) {
            ListNode* pNext = cur->next;
            cur->next = pre;       
            pre = cur;
            cur = pNext;
        }
        return pre;

    }
};
