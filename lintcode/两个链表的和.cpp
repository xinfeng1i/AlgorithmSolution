#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iterator>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};

ListNode *addLists(ListNode *l1, ListNode *l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* head = NULL;
    ListNode* pre = NULL;
    ListNode* p = head;
    int carry = 0;
    int digit = 0;
    while (p1 != NULL && p2 != NULL) {
        digit = p1->val + p2->val + carry;
        carry = digit / 10;
        digit = digit % 10;

        if (pre == NULL) {
            head = pre = new ListNode(digit);
        } else {
            pre->next = new ListNode(digit);
            pre = pre->next;
        }

        p1 = p1->next;
        p2 = p2->next;
    }

    while (p1 != NULL) {
        digit = p1->val + carry;
        carry = digit / 10;
        digit = digit % 10;
        pre->next = new ListNode(digit);
        pre = pre->next;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        digit = p2->val + carry;
        carry = digit / 10;
        digit = digit % 10;
        pre->next = new ListNode(digit);
        pre = pre->next;
        p2 = p2->next;
    }

    if (carry != 0) {
        pre->next = new ListNode(carry);
    }
    
    return head;
}

// 总结:
// 链表相加，注意进位的要求，如果最后进位还不为 0，需要补上一个额外的节点

int main() {
    ListNode* L1 = new ListNode(3);
    L1->next = new ListNode(6);
    L1->next->next = new ListNode(8);

    ListNode* L2 = new ListNode(8);
    L2->next = new ListNode(9);
    L2->next->next = new ListNode(8);
    //L2->next->next->next = new ListNode(8);

    ListNode* head = addLists(L1, L2);
    for (ListNode* p = head; p != NULL; p = p->next) {
        cout << p->val << " " << endl;
    }
    return 0;
}