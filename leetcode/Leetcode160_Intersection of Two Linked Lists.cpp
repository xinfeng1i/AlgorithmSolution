#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};



int countNodeNum(ListNode* head) {
    int n = 0;
    ListNode* p = head;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    return n;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == NULL || headB == NULL) return NULL;

    int n1 = countNodeNum(headA);
    int n2 = countNodeNum(headB);

    ListNode* pLong = NULL;
    ListNode* pShort = NULL;
    int diff = 0;
    if (n1 >= n2) {
        diff = n1 - n2;
        pLong = headA;
        pShort = headB;
    }
    else {
        diff = n2 - n1;
        pLong = headB;
        pShort = headA;
    }

    for (int i = 0; i < diff; ++i) {
        pLong = pLong->next;
    }

    while (pLong != NULL && pShort != NULL) {
        if (pLong == pShort) {
            return pLong;
        }
        pLong = pLong->next;
        pShort = pShort->next;
    }

    return NULL;
}


#if 0
int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);

    p1->next = p2;
    p2->next = p3;

    ListNode* q1 = new ListNode(100);
    ListNode* q2 = new ListNode(200);
    q1->next = q2;
    q2->next = p3;

    ListNode* res = getIntersectionNode(p1, q1);
    if (res == NULL) {
        cout << "NULL" << endl;
    }
    else {
        cout << res->val << endl;
    }

    return 0;
}
#endif // 0