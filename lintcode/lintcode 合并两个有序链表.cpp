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

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* head = NULL;
    ListNode* last = NULL;

    ListNode* p1 = l1;
    ListNode* p2 = l2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val <= p2->val) {
            if (last == NULL) {
                head = last = new ListNode(p1->val);
            } else {
                last->next = new ListNode(p1->val);
                last = last->next;
            }
            p1 = p1->next;
        } else {
            if (last == NULL) {
                head = last = new ListNode(p2->val);
            } else {
                last->next = new ListNode(p2->val);
                last = last->next;
            }
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        if (last == NULL) {
            head = last = new ListNode(p1->val);
        } else {
            last->next = new ListNode(p1->val);
            last = last->next;
        }
        p1 = p1->next;
    }

    while (p2 != NULL) {
        if (last == NULL) {
            head = last = new ListNode(p2->val);
        } else {
            last->next = new ListNode(p2->val);
            last = last->next;
        }
        p2 = p2->next;
    }
    return head;
}

#if 0
int main()
{
    ListNode* L1 = new ListNode(1);
    L1->next = new ListNode(3);
    L1->next->next = new ListNode(8);
    L1->next->next->next = new ListNode(11);
    L1->next->next->next->next = new ListNode(15);

    ListNode* L2 = new ListNode(2);

    ListNode* L = mergeTwoLists(L1, L2);
    for (ListNode* p = L; p != NULL; p = p->next)
        cout << " " << p->val;
    cout << endl;

    return 0;
}
#endif //0